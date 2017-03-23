#include <stdio.h>
int main()
{
	int a = -1;
	int b = ((unsigned int)a)>>5;
	printf("%d\n",b);
	return 0;
}