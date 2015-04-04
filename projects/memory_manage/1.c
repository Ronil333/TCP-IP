#include"header.c"
//#include<math.h>
int power(char *p)
{
int sum=1,n,i;
n=atoi(p);
//printf("Nuber is  %s\n",p);
for(i=0;i<n;i++)
sum=sum*2;
return sum;
//printf("n===%d\n",sum);
}
main(int argc,char **argv)
{
char p[30],q[30];
int n1,n2,n3,size=1,i,p_size=1,a;
FILE *fp;
fp=fopen(argv[1],"r");
///fp=fopen("/usr/include/math.h","r");

if(fp==NULL)
{
printf("File not present...\n");
return;
}

//Total size
size=power(argv[2]);
printf("total size=====%d\n",size);

//no of pages
//n1=atoi(argv[3]);
//n1=atoi(argv[2])-atoi(argv[3]);
p_size=power(argv[3]);
//p_size=power(n1);
printf("page size=====%d\n",p_size);

printf("Number of pages  are...%d\n",size/p_size);

while(fgets(p,30,fp))
{

int i=0;
for(i=0;p[i]!=' ';i++)
q[i]=p[i];
q[i]='\0';
n2=atoi(q);

printf("n2===%d\n",n2);
printf("%d is in %d page...\n",n2,n2/p_size);
}

}

