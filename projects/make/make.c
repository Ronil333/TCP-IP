#include"header.c"
main()
{
struct stat vo,vc;
int i=0,j,k,c,o;
static int t=0;
char a[50]="cc -c ",q[50],*tmpc,*tmpo,b[50],tmp[50];
FILE *fp;
fp=fopen("makefile","r");

if(fp==NULL)
{
printf("File not present..\n");
return;
}

while(fgets(q,50,fp))
{
//a[50]="cc -c ";
j=0;
k=0;
tmpc=malloc(15);
tmpo=malloc(15);
i++;
	if(i==2)
	{
	strcpy(tmp,q);
	}
	if((i!=1)&&(i%2))
	{
	for(j=0;q[j]!=':';j++)
	tmpo[j]=q[j];
	tmpo[j]='\0';
	j=j+1;
	for(;(q[j]!='\n')&&(q[j]!=NULL);j++,k++)
	tmpc[k]=q[j];
	tmpc[k]='\0';
//	printf("%s %s\n",tmpo,tmpc);
	o=stat(tmpo,&vo);
	c=stat(tmpc,&vc);
		if(o<0||c<0)
		{
		strcpy(b,a);
		strcat(b,tmpc);
		strcat(b," -o ");
		strcat(b,tmpo);
		printf("%s\n",b);
		system(b);
		bzero(b,50);
		}
		else
		{
			if(vc.st_mtime>vo.st_mtime)
			{
			strcpy(b,a);
			strcat(b,tmpc);
			strcat(b," -o ");
			strcat(b,tmpo);
			printf("%s\n",b);
			system(b);
			bzero(b,50);
			
			}
			else
			{
			t++;
			if(t==3)
			{
			printf("Makefile uptodate...\n"); 
			}
			system(tmp);	
			}
		}
	}


}

}



