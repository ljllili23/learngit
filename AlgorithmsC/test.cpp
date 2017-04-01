#include <stdio.h>
#inclue <string.h>
int main()
{
	char a[101],s[101];
	int i,len,mid,next,top;

	gets(a); //read in a line of string;
	len = strlen(a); //get the length of the string;
	mid = len/2-1;
	top = 0;
	for(i=0;i<=mid;i++)
	{
		s[++top] = a[i];
	}
	if (len%2==0)
	
		next = mid+1;
	else
		next = mid+2;
	
	return 0;
}