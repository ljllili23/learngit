#include <stdio.h>
int main()
{
	int a[101],i,j,t,n;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	//begin bubble sort
	for(i=1;i<=n-1;i++)
	{
		for(j=1;j<=n-i;j++)
		{
			if(a[j]>a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	printf("%d",a[1]);
	for(i=2;i<=n;i++)
	{
		if(a[i] != a[i-1])
			printf("%d",a[i]);	
	}
	getchar();getchar();
	return 0;
}