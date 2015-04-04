#include"header.c"
char a[100];
char b[100];
void search(char *,char *);
main(int argc,char **argv)
{
	search(argv[1],argv[2]);
}
void search(char *p,char *q)
{
	static int count=0;
	struct stat v;
	struct dirent *l;
	DIR *dp;
	dp=opendir(p);
	strcpy(b,p);
	if(dp==NULL)
	{
		perror("opendir");
		return;
	}
	else
	{
	while((l=readdir(dp)))
	{

	if(l->d_name[0]!='.')
	{
	strcpy(a,b);
	//strcpy(a,p);
	strcat(a,l->d_name);
	stat(a,&v);
	if(S_ISDIR(v.st_mode))
	{
		printf("In dir-----%s\n",a);
		strcat(a,"/");
		printf("%s\n",a);
		search(a,q);
	}
		if(strcmp(l->d_name,q)==0)
		{
			count++;
		}
	}
	}
//	ii++;
	}
	printf("count=%d\n",count);
}


