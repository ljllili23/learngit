//test.cpp
#include <stdio.h>
typedef int DataType;
void Reverse(DataType A[], int left, int right, int arraySize)
{
	if(left>right || right>=arraySize)
		return;
	int mid = (left+right)/2;
	for(int i=0;i<=mid-left;i++)
	{
		DataType temp=A[left+i];
		A[left+i]=A[right-i];
		A[right-i]=temp;
	}
}

void Exchange(DataType A[], int m, int n, int arraySize)
{
	Reverse(A,0,m+n-1,arraySize);
	Reverse(A,0,n-1,arraySize);
	Reverse(A,n,m+n-1,arraySize);
}

int main()
{
	int m=8,n=6,arraySize=14;
	DataType A[]={1,2,3,4,5,6,7,8,11,12,13,14,15,16};
	Exchange(A,m,n,arraySize);
	for(int i=0;i<arraySize;i++)
		printf("%d\n",A[i]);
	return 0;
}