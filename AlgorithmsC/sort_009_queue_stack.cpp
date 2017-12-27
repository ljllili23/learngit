#include <stdio.h>
struct queue
{
	int data[1000];
	int head;
	int tail;
};
struct stack
{
	int data[10];
	int top;
};

int main()
{
	struct queue q1,q2;
	struct stack s;
	int book[10];
	int i, t;

	//initialization
	q1.head = 1; q1.tail = 1;
	q2.head = 1; q2.tail = 1;

	s.top=0;

	for(i=1;i<=9;i++)
		book[i]=0;
	printf("\n Please input the q1 numbers:");
	for(i=1;i<=6;i++)
		{
			scanf("%d",&q1.data[q1.tail++]);
		}
	printf("\n Please input the q2 numbers:");

	for(i=1;i<=6;i++)
	{
		scanf("%d", &q2.data[q2.tail++]);
	}

	while(q1.head<q1.tail && q2.head<q2.tail) //when the two queues are not empty
	{
		t=q1.data[q1.head];
		if(book[t]==0)
		{
			q1.head++;
			s.top++;
			s.data[s.top]=t;
			book[t]++;
		}else
		{
			q1.head++;
			q1.data[q1.tail++]=t;
			while(s.data[s.top]!=t)
			{
				q1.data[q1.tail++] = s.data[s.top--];
				book[s.data[s.top]]=0;
			}
			book[s.data[s.top]]=0;
			q1.data[q1.tail++] = s.data[s.top--];
		}
		if (q1.head == q1.tail) break; //if there is no more element in q1 queue, end the game.
/*********************************************/
			t=q2.data[q2.head];
		if(book[t]==0)
		{
			q2.head++;
			s.top++;
			s.data[s.top]=t;
			book[t]++;
		}else
		{
			q2.head++;
			q2.data[q2.tail++]=t;
			while(s.data[s.top]!=t)
			{
				q2.data[q2.tail++] = s.data[s.top--];
				book[s.data[s.top]]=0;
			}
			book[s.data[s.top]]=0;
			q2.data[q2.tail++] = s.data[s.top--];
		}
		if (q2.head == q2.tail) break; //if there is no more element in q1 queue, end the game.
	}
		/////////////////////////////////////////
		if(q2.head==q2.tail)
		{
			printf("q1 win the game!\n");
			printf("the cards in q1's hand:");
			for(i=q1.head;i<q1.tail-1;i++)
			{
				printf("%d\t",q1.data[i]);
			}
			if(s.top>0)
			{
				printf("\n the cards on the desk:");
				for(i=s.top;i>0;i--)
				{
					printf("%d",s.data[i]);
				}
			}else printf("there isn't any card on the desk!");
		}
/*****************************************/
		if(q1.head==q1.tail)
		{
			printf("q2 win the game!");
			printf("the cards in q2's hand:");
			for(i=q2.head;i<q2.tail-1;i++)
			{
				printf("%d",q2.data[i]);
			}
			if(s.top>0)
			{
				printf("\n the cards on the desk:");
				for(i=s.top;i>0;i--)
				{
					printf("%d\t",s.data[i]);
				}
			}else printf("there isn't any card on the desk!");
		}		
	
	getchar(); getchar();
	return 0;
}