//HashBucketSort.cpp
#include <iostream>
using namesp
#define OFFSET 500000
int Hash[1000000];
int main(){
	int n,m;
	int i;
	while(scanf("%d%d",&n,&m)!=EOF&&n!=0){
		for(i=0;i<n;++i){
			int x;
			scanf("%d",&x);
			Hash[x+OFFSET]=1;
		}
		for(i=500000;i>=-500000;--i){
			if(Hash[i+OFFSET]==1){
				cout<<i;
				m--;
				if(m!=0)
					cout<<' ';
				else {cout<<endl; break;}
			}
		}
	}
	return 0;
}