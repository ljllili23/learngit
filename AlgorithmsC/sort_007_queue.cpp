#include <stdio.h>
int main()
{
	int q[102]={0,6,3,1,7,5,8,9,2,4},head,tail;
	//initialize the queue;
	head = 1;
	tail = 10; //there are already 9 element in the queue, so the tail point to the next place;
	while(head<tail) //when the queue not empty;
	{
		//print the head and delete it from the queue;
		printf("%d", q[head]);
		head++;

		//add new head element to the tail;
		q[tail] = q[head];
		tail++;
		//then make the head element out of the queue;
		head++;
	}
	getchar();getchar();
	return 0;
}