http://zarb.org/~gc/html/libpng.html
http://www.xbdev.net/image_formats/png/index.php
http://www.pygtk.org/pygtk2tutorial/sec-Images.html
http://zetcode.com/tutorials/gtktutorial/firstprograms/
http://pastebin.com/TnM8tdAu
https://developer.gnome.org/gtk3/stable/GtkImage.html
# TCP-IP
http://www.raspberry-projects.com/pi/pi-operating-systems/raspbian/io-pins-raspbian/uart-pins
http://www.slideshare.net/anandopaul/linux-booting-steps
http://blog.rlove.org/2010/07/linux-kernel-development-third-edition.html
http://www.esacademy.com/en/library/book-recommendations.html
#include<stdio.h>
#include<string.h>    //strlen
#include<sys/socket.h>
#include<arpa/inet.h> //inet_addr
 
void RecvFile(int sock, const char* filename) 
{ 
    int rval; 
    char buf[2000]; 
    //char name[20];
  //  int t=0;
    FILE *file = fopen(filename, "wb"); 
	perror("fopen");

	printf("---filename = %s-------\n",filename);
    if (!file)
    {
        printf("Can't open file for writing");
        return;
    }
int l,total=0;
int fsize = recv(sock , &l ,4,0);
printf("------------fsize = %d and  l = %d--------\n",fsize,l);

   while (1)
    {
	if(total==l)
	{
		printf("now break;\n");
		break;
	}
        //rval = recv(sock, buf, sizeof(buf), 0);
		int bytesRemaining = (l-total);
	rval = read(sock,buf, (bytesRemaining < 2000 ? bytesRemaining : 2000));
	
      int written = fwrite(buf, 1, rval, file);
	printf("----- rval = %d total = %d ----\n",rval,total);
	total = total +rval;
   } 
total=0,rval=0;
    fclose(file); 
} 


int main(int argc , char *argv[])
{
    int socket_desc,c,new_socket;
    struct sockaddr_in server,client;
    char *message , client_reply[6000];
   FILE *fp,*fps;  
	char s[20];
    //Create socket
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1)
    {
        printf("Could not create socket");
    }
	
	

	//fp=fopen("screenshot1.png","w+");
	//perror("fopen");

    
    server.sin_addr.s_addr = inet_addr("192.168.1.4");;
    server.sin_family = AF_INET;
    server.sin_port = htons(1234);
printf("------%d--------\n",ntohs(server.sin_port));

//Bind
if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
{
    puts("bind failed");
    return 1;
}
puts("bind done");
//Listen
    listen(socket_desc , 3);
     
    //Accept and incoming connection
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);
    new_socket = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
int cnt=0;
while(cnt<5)
{
	
	sprintf(s,"%s%d%s","screenshot",cnt,".png");
	
	RecvFile(new_socket,s);
	
	cnt++;
}
/*
   while(recv(new_socket, client_reply , 6000 , 0) < 0)
    {
	fwrite(client_reply,strlen(client_reply)+1,1,fp);
//        puts("recv failed");
    }
    puts("Reply received");
    puts(client_reply);

*/
/*
if(send(new_socket,client_reply,strlen(client_reply),0)<0)
{
printf("send failed...\n");
}
puts("send done..\n");
    if (new_socket<0)
    {
        perror("accept failed");
    }
     
    puts("Connection accepted");
 printf("---- client id = %d-----------\n",client.sin_addr.s_addr);
*/ 
   return 0;
}

 
 /**
    Simple TCP client to fetch a web page
    Silver Moon (m00n.silv3r@gmail.com)
*/
 
#include<stdio.h>
#include<string.h>    //strlen
#include<sys/socket.h>
#include<arpa/inet.h> //inet_addr
#include <sys/stat.h> 


void send_file(int sock) 
{ 
	struct stat obj;
printf("---file send----\n");
    char buf[1025]; 
    const char* filename = "screenshot.png"; 
	FILE *file = fopen("screenshot.png", "rb"); 
	if (!file)
	{
		printf("Can't open file for reading"); 
	        return;
	}
	stat("screenshot.png",&obj);
	int fsize = obj.st_size;
	printf("====file size is %d====\n",fsize);
send(sock , &fsize , 4 , 0);

    while (!feof(file)) 
    { 
        int rval = fread(buf, 1, sizeof(buf), file); 
        if (rval < 1)
        {
            printf("Can't read from file");
            fclose(file);
            return;
        }

        int off = 0;
        do
        {
            int sent = send(sock, &buf[off], rval - off, 0);
            if (sent < 1)
            {
                // if the socket is non-blocking, then check
                // the socket error for WSAEWOULDBLOCK/EAGAIN
                // (depending on platform) and if true then
                // use select() to wait for a small period of
                // time to see if the socket becomes writable
                // again before failing the transfer...

                printf("Can't write to socket");
                fclose(file);
                return;
            }

            off += sent;
        }
        while (off < rval);
    } 

    fclose(file);

}

int main(int argc , char *argv[])
{
	FILE *fp;
    int socket_desc;
    struct sockaddr_in server;
    char message[256] , server_reply[6000];
     

//	fp=fopen("screenshot.png","r");
//	perror("fopen");
    //Create socket
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1)
    {
        printf("Could not create socket");
    }
     
    //ip address of www.msn.com (get by doing a ping www.msn.com at terminal)
    server.sin_addr.s_addr = inet_addr("192.168.1.4");
    server.sin_family = AF_INET;
    server.sin_port = htons( 1234 );
 
 
 
 
    //Connect to remote server
    if (connect(socket_desc , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        puts("connect error");
        return 1;
    }
     
    puts("Connected\n");

int cnt=0;
while(cnt<5)
{

send_file(socket_desc);
sleep(0.5);
cnt++;

}
/*     
while(fread(message, 1,sizeof(message), fp)>0)
{
 

    //Send some data
    if( send(socket_desc , message , strlen(message) , 0) < 0)
    {
        puts("Send failed");
        return 1;
    }
 
}     
   puts("Data Send\n");
 
   //Receive a reply from the server
    if( recv(socket_desc, server_reply , 6000 , 0) < 0)
    {
        puts("recv failed");
    }
    puts("Reply received\n");
    puts(server_reply);
 */    
    return 0;
}
