#include"header.c"
struct st
{
char ch[10];
struct st *next;
};
void print(struct st *ptr)
{
	static int i=0;
	while(ptr&&i<5)
	{
		printf("%s\n",ptr->ch);
		ptr=ptr->next;
		i++;
	}
}
void add_begin(struct st **ptr,char *p)
{
struct st *tmp;
tmp=malloc(sizeof(struct st));
strcpy(tmp->ch,p);

tmp->next=*ptr;
*ptr=tmp;
}

main(int argc,char **argv)
{
	int c=1;
	char ch1[10];
	struct st *headptr=0;

	if(strcmp(argv[1],"-c")==0)
	{
		char *q[]={argv[2],argv[3],NULL};
		execvp(q[0],q);
	}
	else
	{
	int j=0;
		while(1)
		{
			printf("<%d Ronil>",c++);
			gets(ch1);
			/*while(ch1[j])
			{
				if(ch1[j]!=';')
				{
				
				}
			j++;
			} */
			if(strcmp(ch1,"hist")==0)
			{
				print(headptr);
			}
			else if(strcmp(ch1,"pid")==0)
			{
				printf("%d\n",getpid());
			}
			else if(strcmp(ch1,"ppid")==0)
			{
				printf("%d\n",getppid());
			}
			else if(strcmp(ch1,"quit")==0)
			{
				return;
			}
			else
			{
				if(fork()==0)
				{
				execlp(ch1,ch1,NULL);	
				}
				else
				{
				add_begin(&headptr,ch1);
				wait(0);
				}
			}
		}
	}
}
