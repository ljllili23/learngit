#include <stdio.h>
int main()
{
	int a[101],i,t,n;
	for(i=1;i<=100;i++)
	{
		a[i]=0;
	}
	printf("Please input the amount of the numbers to be sorted:");
	scanf("%d",&n); //input the amount of the numbers
	printf("writer down the sequence:");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&t);
		a[t]=1;
	}
	for(i=1;i<=100;i++)
	{
		if(a[i]==1)
			printf("%d\t",i);
	}
	getchar();getchar();
	return 0;
}