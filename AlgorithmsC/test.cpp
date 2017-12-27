#include <stdio.h>
#include <string.h>
int main()
{
	char a [101], s[101];
	int i,len,mid,next,top,t;
	char sign[100];
	t=1;
	while(t)
	{
	printf("Please input the string you want to identify:");
	gets(a); //read in a line of string
	len = strlen(a); //get the length of the string
	mid = len/2 - 1; //get the mid point of the string
	top = 0; //initialize the stack
	//put the characters before the mid point into the stack in sequence
	 for(i=0;i<=mid;i++)
	 {
	 	s[++top] = a[i];
	 }
	 //identify the length of the string to be odd or even, and find out the subscribe of the beginning of the characters under matching.
	 if(len%2==0)
	 {
	 	next = mid+1;
	 } else
	 		next = mid+2;
	 //matching beginning
	 for(i=next; i<=len-1; i++)
	 {
	 	if(a[i] != s[top])
	 		break;
	 	top--;
	 }

	 // if the value of 'top' is zero, then all the characters in the stack were matched exactly.
	 if(top==0)
	 {
	 	printf("YES");

	 }else
	 		printf("NO");
	 printf("\n DO YOU WANT TO CONTINUE TO IDENTIFY ANOTHER STRING? YES or NO?");
	 gets(sign);
	 if (!strcmp(sign,"YES"))
	 {
	 	t=1;
	 }else
	 	t=0;
	 	}
	
	return 0;
}