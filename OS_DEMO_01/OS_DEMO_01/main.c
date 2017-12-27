//
//  main.c
//  OS_DEMO_01
//
//  Created by mac on 5/16/17.
//  Copyright (c) 2017 LeeJiangLee. All rights reserved.
//

/*OStest*/
/*LeeJiangLee*/
// #include <conio.h>
#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
struct jincheng {
    int pid;
    int youxian;
    int daxiao;
    int msg;
    int live;
};
struct jincheng neicun[20],waicun;
int shumu=1;
int create() {
     if(shumu>=20)
    {
        printf("\n 内存已满，请先结束或换出进程\n");}
    else {
         printf("\n 请创建第%d个进程",shumu);
         printf("\n 请输入新进程的 pid\n");
         scanf("%d",&neicun[shumu].pid);
         printf("\n 请输入新的进程的优先级\n");
         scanf("%d",&neicun[shumu].youxian);
         printf("\n 请输入新的进程的大小\n");
         scanf("%d",&neicun[shumu].daxiao);
         printf("\n 请输入新的进程的消息\n");
         scanf("%d",&neicun[shumu].msg);
         neicun[shumu].live=1;
         shumu++;
    }
     return neicun[shumu-1].live;
}
void viewrun() {
    int vpid;
    printf("\n 请输入想显示第几个创建的进程\n");
    scanf("%d",&vpid);
    if(vpid>0&&vpid<=20&&neicun[vpid].live==1)
    {
        printf("\n进程的pid是:%d\n",neicun[vpid].pid);
        printf("\n进程的优先级是:%d\n",neicun[vpid].youxian);
        printf("\n进程的大小是:%d\n",neicun[vpid].daxiao);
        printf("\n进程的消息是:%d\n",neicun[vpid].msg);
    }
    else {
        printf("\n 所查看运行进程不存在\n");
    }
    printf("请按回车退出查看\n");
    vpid=getchar();
}
void huanchu()
{
    int pid1,pid2;
    char c;
    printf("\n 请输入第一个替换进程是第几个创建的\n");
    scanf("%d",&pid1);
    printf("\n 请输入第二个替换进程是第几个创建的\n");
    scanf("%d",&pid2);
    if(pid1>0&&pid1<=20&&neicun[pid1].live==1)
    {
        if(neicun[pid1].youxian>neicun[pid2].youxian)
        {
            waicun.pid=neicun[pid1].pid;
            waicun.youxian=neicun[pid1].youxian;
            waicun.daxiao=neicun[pid1].daxiao;
            waicun.msg=neicun[pid1].msg;
            neicun[pid1].pid=neicun[pid2].pid;
            neicun[pid1].youxian=neicun[pid2].youxian;
            neicun[pid1].daxiao=neicun[pid2].daxiao;
            neicun[pid1].msg=neicun[pid2].msg;
            neicun[pid2].pid=waicun.pid;
            neicun[pid2].youxian=waicun.youxian;
            neicun[pid2].daxiao=waicun.daxiao;
            neicun[pid2].msg=waicun.msg;
            printf("\n 替换完成\n");
            printf("\n 被替换进程的pid是:%d\n",waicun.pid);
            printf("\n 被替换进程的youxian是:%d\n",waicun.youxian);
            printf("\n 被替换进程的daxiao是:%d\n",waicun.daxiao);
            printf("\n 被替换进程的msg是:%d\n",waicun.msg);
        }
        else {
            printf("\n进程优先级不够大");
        }
    }
    else {
        printf("所查看运行进程不存在");
    } printf("请按回车退出换出进程\n");
    c=getchar();
}
void Pkill()
{
    int kpid;
    printf("\n 请输入要撤销第几个创建的进程\n");
    scanf("%d",&kpid);
    if(kpid>0&&kpid<20&&neicun[kpid].live==1)
    {
        neicun[kpid].live=0;
        printf("\n 已撤销第%d个创建的进程",kpid);
    }
    else {
        printf("\n 所查看运行进程不存在\n");
    }
    printf("请按回车退出查看\n");
    kpid=getchar();
}
int main ()
{
    int n;
    char a;
    n=1;
    while(n==1) {
      //  system("cls");
        printf("\n***********************************");
        printf("\n*         进程演示系统            *");
        printf("\n***********************************");
        printf("\n  1.创建新的进程   2.查看运行进程  ");
        printf("\n  3.换出某个进程   4.杀死运行进程  ");
        printf("\n  5.退出          ");
        printf("\n***********************************");
        printf("\n请选择（1~5）");
        a=getchar();
        switch(a)
        {
            case'1':create();
                break;
                
            case'2':viewrun();
                break;
            case'3':huanchu();
                break;
            case'4':Pkill();
                break;
            case'5':exit(0);
            default:n=0;
        }
    }
    return 0;
}