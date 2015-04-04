#include"header.c"
main(int argc,char **argv)
{
//if(fork()==0)
//{
//exit(3);
	if(strcmp(argv[1],"-c")==0)
	{
//	sleep(2);
	char *p[]={argv[2],argv[3],NULL};
	execvp(p[0],p);
	exit(3);
	}
	else
	{
/*	if(fork())	
	{
	while(1);	
	
	}
*/	//else
	{
	static int c=1;
	char ch[10],ch1;
	while(1)
	{
	struct stat v;
		printf("<%d Ronil>",c);
	scanf("%s",ch);
if(ch[0]!='\n')
printf("%s\n",ch);	
else{

                c++;
                printf("<%d Ronil>",c);


}

/*	if(stat(ch,&v)<0)
	{
	perror("stat");
	return;
	}
*/	//stat(ch,&v);
//	printf("%c\n",ch[0]);
	/*ch1=ch[0];
	printf("%d\n",ch1);
	if(ch1=='\n')
                {
                c++;
                printf("<%d Ronil>",c);
                }
*/
		if(strcmp(ch,"curPid")==0)
		{
		//printf("cur pid is...%d\n",v.st_uid);
		printf("cur pid is...%s\n",ch);
		
		
		}





		c++;
	}

	}	
	}
	}








