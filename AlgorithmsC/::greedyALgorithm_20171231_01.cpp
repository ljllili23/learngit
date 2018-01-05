//greedyALgorithm_20171231_01.cpp
#include <iostream>
#include <algorithm>
using std::cin;
struct goods{
	double j; //total weight
	double f; //total cost
	double s; //cost performance
	bool operator< (const goods & A) const{
		return s>A.s;
	}
}buf[1000];

int main(){
	double m;
	int n;
	while(std::cin>>m>>n){
		if(m==-1&&n==-1) break;
		for(int i=0;i<n;++i){
			cin>>buf[i].j>>buf[i].f;
			buf[i].s=buf[i].j/buf[i].f;
		}
		std::sort(buf,buf+n);
		int idx = 0; //index of buf[];
		double ans = 0;
		while(m>0&&idx<n){
			if(m>buf[idx].f){
				ans+=buf[idx].j;
				m-=buf[idx].f;
			}
			else{
				ans+=m*buf[idx].s;  //WARNING!!! ans+=?;		
				m=0;
			}
			++idx;
		}
		printf("%.3lf\n",ans);
	}
	return 0;
}