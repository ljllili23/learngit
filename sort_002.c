#include <stdio.h>
int main()
{
	int book[1000],i,j,t,n;
	for(i=0;i<=1000;i++)
		book[i]=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&t);
		book[t]++;
	}
	for(i=1000;i>=0;i--)
	{
		for(j=1;j<=book[i];j++)
			{printf("%d",i);
			printf(",");}
	}
	getchar();getchar();
	return 0;
}