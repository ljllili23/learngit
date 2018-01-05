#//search.cpp
#include <iostream>
using namespace std;
int main(){
	int n;
	int buf[200];
	int x;
	int ans=-1;
	while(scanf("%d",&n)){
		for(int i=0;i<n;++i){
			scanf("%d",&buf[i]);
		}
		scanf("%d",&x);
		for(int i=0;i<n;++i){
			if(buf[i]==x){
				ans=i;
				break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}