#include <stdio.h>
int fun(int x)
{
	int num=0;
	int f[10]={6,2,5,5,4,5,6,3,7,6};
	while(x/10!=0)
	{
		num += f[x%10];
		x=x/10;
	}
	num += f[x];
	return num;
}
int main()
{
	int a,b,c,m,sum=0;
	for(a=0;a<1111;a++)
		
	return 0;
}