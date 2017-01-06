#include <stdio.h>
int main()
{
	int *a;
	int i,j,n,flag;
	printf("Please input the number of the numbers you want to sort:");
	scanf("%d",&n);
	
	for (i=1;i<=n;i++)
	{
		scanf("%d", &a[i-1]);
	}
	for(i=n;i>0;i--)
	{
		for(j=0;j<i-1;j++)
		{
			if(a[j]<a[j+1])
				{
					flag=a[j];
					a[j]=a[j+1];
					a[j+1]=flag;
				}
		}
	}
	for(i=1;i<=n;i++)
		printf("%d ",a[i-1]);
	printf("\n");
	return 0;
}