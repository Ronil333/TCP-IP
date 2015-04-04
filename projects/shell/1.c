#include"header.c"

struct st
{
char ch[20];
int pid;
struct st *next;
};

void print(struct st *ptr)
{
struct st *tmp;
static int i=0;

ptr=ptr->next;
while(ptr&&i<5)
{
printf("%s %d\n",ptr->ch,ptr->pid);
ptr=ptr->next;
i++;
}

}


void add_begin(struct st **ptr,char *p)
{
struct st *tmp;
tmp=malloc(sizeof(struct st));
strcpy(tmp->ch,p);
tmp->pid=getpid();
tmp->next=*ptr;
*ptr=tmp;
}
main(int argc,char **argv)
{
struct st *headptr=0;
 if(strcmp(argv[1],"-c")==0)//with -c option
        {
        char *p[]={argv[2],argv[3],NULL};
        execvp(p[0],p);
//        exit(3);
        }
else//without -c option
{
char ch[10];
static int c=1;
//if(fork())
//{//Parent
while(1)
{
printf("<%d RonilD>",c++);
//wait(0);
//gets(ch);
	if(fork())
	{
	gets(ch);
	}
	else
	{
	
	
	add_begin(&headptr,ch);
	if(strcmp(ch,"hist")==0)
	{
	print(headptr);
	}
	else
	{
	
	system(ch);
	
	}
	}
}
}


}

