#include <stdio.h>
#include <stdlib.h>
#define getpch(type)(type*)malloc(sizeof(type))
//#define NULL 0

struct pcb{
	char ID[10];
	char state;
	int priority;
	int ALLtime;
	int CPUtime;
	int STARTBLOCK;
	int BLOCKTIME;
	struct pcb* next;
}*head=NULL, *bhead=NULL, *p;
typedef struct pcb PCB;
 void sort(PCB *p)
{
	PCB *p1, *p2;
	int insert=0;
	if((head==NULL)||((p->priority)>(head->priority))) //insert head when it is empty 
	{
		p->next=head;
		head=p;
	}
	else //compare the priority when it isnot empty
	{
		p1=head;
		p2=head->next;
		while(p2!=NULL)
		{
			if((p->priority)>(p2->priority)) //if
			{
				p->next=p2;
				p1->next=p;
				p2=NULL;
				//insert=1;
			}
			else
			{
				p1=p1->next;
				p2=p2->next;
			}
		}
		if(p2==NULL)
		{
			p1->next=p;
			p->next=NULL;
		}

	}
	
}
void input()
{
	int i,N;
	system("CLS");
	printf("\n please input the process number:N=");
	scanf("%d",&N);
	for(i=0;i<N;i++)
	{
		printf("\n the process number No.%d:\n",i);
		p=getpch(PCB);
		printf("\ninput the process name:");
		scanf("%s",p->ID);
		printf("\n input the priority:");
		scanf("%d", &p->priority);
		printf("\n input the process running time:") ;
		scanf("%d", &p->ALLtime);
		printf("\n input the process STARBLOCK:"); //运行阻塞时间
		scanf("%d",&p->STARTBLOCK);
		printf("\n input the process BLOCKTIME:");
		scanf("%d",&p->BLOCKTIME);
		printf("\n");
		p->CPUtime=0;
		p->state='w';
		p->next=NULL;
		sort(p);
	}
}
	int getsize()
	{
		int size=0;
		PCB* pr=head;
		while(pr!=NULL)
			{
				size++;
				pr=pr->next;
			}
		return(size);
	}
void show(PCB * pr)
{
	printf("\n ID  state  priority  ALLtime  CPUtime STARTBLOCK  BLOCKTIME\n");
	printf("  %s\t",pr->ID);
	printf("%c\t",pr->state);
	 printf("%d\t",pr->priority);
	printf("  %d\t",pr->ALLtime);
	printf("  %d\t",pr->CPUtime);
	printf("  %d\t",pr->STARTBLOCK);
	printf("  %d\t",pr->BLOCKTIME);
	printf("\n");
}
void PushReady(PCB *p)//插入就绪队列 
{   
	p->state='w';  
	sort(p); 
}
void running() //检查阻塞队列，将就绪进程插入到就绪队列
{
	PCB  *p1, *p2;
	if(!bhead)
	{
		return;
	}
	else
	{
		p1=bhead, p2=bhead;
		p=p1;
		do
		{
			if(p==bhead)
			{
				if(p->BLOCKTIME==0)
				{
					bhead = p1->next;
					PushReady(p);
					p1=p=bhead;
				}
				else
				{
					p=p->next;
				}
			}
				else if(p->BLOCKTIME==0)
				{
					p1->next=p->next;
					PushReady(p);     
					p = p1->next;    
				}
				else    {     
					p1 = p1->next;     
					p = p->next;
				}
			
			
		}while(p!=NULL);

	}
}
void blocking(PCB *pr) /*建立进程阻塞函数(进程运行时间到,置阻塞状态*/  
{  
	 PCB* pre; 
	 pre=bhead;  
	pr->state='B'; 
	 if(bhead==NULL)   
		bhead=pr;   
	else   
	{    
		while(pre->next)    
			pre=pre->next;    
		pre->next=pr; 
	 } 
	 pr->next=NULL; 
 }
void check() 
{   
	PCB* pr;  
	PCB* pre;   
	printf("\n \t当前正在运行的进程ID是:%s",pr->ID);   
	show(pr);   
	pr=head;  
	if(pr==NULL)   
		printf("当前就绪队列已空!");  
	else  
	{   //printf("\n 当前就绪队列为:\n");   
	//while(pr!=NULL){       
		show(pr);       
		pr=pr->next;            
		 pr->CPUtime++;      
		pr->ALLtime --;     
		 if(pr->ALLtime == 0)  
			 {    
				printf("\n进程 [%s] 运行完毕！\n",pr->ID);    
				free(pr);   
			}   else if(pr->ALLtime!= 0)   
			{ 
				   pr->priority-=3;   
				 if(pr->STARTBLOCK == pr->CPUtime)     
				 blocking(pr);    
				//else head = sort(pr);  
			}
			pr = head;//未执行的就绪队列   
			while(pr)   
			{    
			pr->priority+=1;//每在就绪队列一个时间片，优先级加1    
			pr = pr->next;   
			}       
			}  
			running();//检查阻塞队列有无就绪进程  
			pre=bhead;  
			while(pre)//阻塞队列阻塞时间减1  
				{  
					pre->BLOCKTIME --;  
					pre = pre->next;  
				} 
			}  
int main()  
{   
	int len,i=0;   
	char ch;   
	input();   
	len=getsize();   
	while((len!=0)&&(head!=NULL))   
		{    ch=getchar();    
			i++;    
			printf("\n\t正在执行第%d轮进程 \n",i);    
			p=head;    
			head=p->next;    
			p->next=NULL;    
			p->state='R';   
			check();    
			printf("\n 按任一键继续......");    
			ch=getchar();   
		}   
		printf("\n\n 进程已经完成.\n");   
		ch=getchar(); 
		return 0; 
	} 