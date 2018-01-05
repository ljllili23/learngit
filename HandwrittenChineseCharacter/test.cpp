#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
  int n,i,j,tem;
 // int flag=0;
  int buf[100];
  printf("Please input:");
  while(scanf("%d",&n)!=EOF)
  {
     printf("Please input:");
    for(i=0;i<n;++i)
    {
     
      scanf("%d", &buf[i]);
    }
    // for(i=n;i>0;--i)
    // {
    //   flag=0;
    //   for(j=1;j<i;++j)
    //   {
    //     if(buf[j-1]>buf[j])
    //     {
    //       flag=1;
    //       tem=buf[j-1];
    //       buf[j-1]=buf[j];
    //       buf[j]=tem;
    //     }
    //   }
    //   if(flag==0) break;
    // }
    // BUBBLE SORT
    sort(buf,buf+n);
    for(i=0;i<n;++i)
    {
      printf("%d ",buf[i]);
    }
    printf("\n");
  }
  return 0;
}