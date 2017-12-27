#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *next;
}
int main()
{
	struct node *head,*p,*q,*t;
	int i, n, a;
	printf("Please input the number of the chain table:");
	scanf("%d",&n);
	head = NULL; //the head pointer point to NULL
	for(i=1;i<=n;i++)
	{
		printf("Please input the data:");
		scanf("%d",&a);
		p = (struct node *)malloc(sizeof(struct node));
		p->data = a;
		p->next=NULL;
		if(head==NULL)
			head=p; //if this is the first node built,then the head pointer point to this node
		else
			q->next=p; //if not,then the next pointer of previous node point to the current node
		q=p; //the pointer q point to the current node

	}
	scanf("%d",&a); //read in the number to be inserted
	t = head;
	while(t != NULL)
	{
		if(t->next == NULL || t->next->data>a)
		{
			p=(struct node *)malloc(sizeof(struct node));
			p->data = a;
			p->next=t->next;   
		}
	}
	getchar();getchar();
	return 0;
}