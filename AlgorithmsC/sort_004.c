#include<stdio.h>
int a[101],n; // global variable

void quicksort(int left, int right)
{
	int i,j,t,temp;
	if(left>right)
		return;
	temp=a[left]; //tmep中存的就是基准数
	i=left;
	j=right;
	while(i!=j)
	{
		//顺序很重要，要先从右往左找
		while(a[j]>=temp && i<j)
			j--;
		//再从左往右找
		while(a[i]<=temp && i<j)
			i++;
		//交换两个数在数组中的位置
		if(i<j) //当哨兵i和哨兵j没有相遇时
		{
			t=a[i];
			a[i]=a[j];
			a[j]=t;
		}
	}
	//将基准数归位
	a[left]=a[i]; 
	a[i]=temp;

	quicksort(left,i-1); //继续处理左边的，这里是一个递归的过程
	quicksort(i+1,right);//继续处理右边的，这里是一个递归的过程

}

int main()
{
	int i,j,t;
	//input the data
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%d", &a[i]);
	}
	quicksort(1,n);

	//输出排序后的结果
	for (i=1;i<=n;i++)
	{
		printf("%d\t",a[i]);

	}
	getchar();
	getchar();
	return 0;

}