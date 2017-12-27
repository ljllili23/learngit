#include <stdio.h>
 
#include <string.h>
#include <time.h>

struct node
{

	struct node* next;
};
typedef struct PCB{
	int PID;
	int Priority;
	int Type; // Run 0 / ready 1 / block 2
	//struct node;
}Spcb; 
 struct PCB Creat(int priority)
{
	struct PCB A;
	A.PID=1;
	A.Priority=priority;
	return A;
}
int main()
{
	int PID;
	int TYPE;
	printf("start!\n");
	
	PID=(Creat(0).PID);
	printf("%d\n",PID);
	TYPE=(Creat(0).PID);
	printf("%d\n",TYPE);
	
	getchar();

	return 0;

}