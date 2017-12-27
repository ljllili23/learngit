#include <stdio.h>

int main()
{
	struct queue{
		int data[100];
		int head;
		int tail;
	};
	struct queue q;
	int i;
	q.head=1;
	q.tail=1;
	printf("Please input a queue of number:");
	for(i=1;i<=9;i++)
		{
			scanf("%d",&q.data[q.tail++]);
			
		}
	while(q.head<q.tail)
	{
		printf("%d",q.data[q.head]);
		q.head++;
		q.data[q.tail]=q.data[q.head];
		q.tail++;
		q.head++;  //throw away the head number.
	}
	getchar();getchar();
	return 0;
}