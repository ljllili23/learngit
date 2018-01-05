//binaryTree_v2.0
//2018.01.04
//LeeJiangLee

#include <stdio.h>
#include <queue>

using namespace std;

priority_queue <int, vector<int>, greater<int> > Q;

int main(){
	int n;

	while(scanf("%d", &n)!=EOF){
		while(!Q.empty()) Q.pop();
		for(int i=0;i<n;++i){
			int x;
			scanf("%d",&x);
			Q.push(x);
		}
		int ans=0;
		while(Q.size()>1){
			int a=Q.top();
			Q.pop();
			int b=Q.top();
			Q.pop();
			ans+=a+b;
			Q.push(a+b);
		}
		printf("%d",ans);
	}
	return 0;
}