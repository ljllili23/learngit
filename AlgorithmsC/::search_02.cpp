//search_02.cpp
#include <iostream>
#include <algorithm>
using namespace std;
struct Stu{
	char no[100]; //why student's numbers is char type??? for strcmp();
	char name[100]; //student's name
	int age;
	char sex[5];
	bool operator < (const Stu &A) const{
		return strcmp(no,A.no)<0;
	}
}buf[1000];
int main(){
	int n;
	int ans;
	while(cin>>n){
		for(int i=0;i<n;++i){
			cin>>buf[i].no>>buf[i].name>>buf[i].sex>>buf[i].age;
		}
		sort(buf,buf+n);
		int t;
		cin>>t;
		while(t--!=0){
			ans=-1;
			char x[30];
			cin>>x;
			int top=n-1,base=0;
			while(top>=base){
				int mid=(top+base)/2;
				int tmp=strcmp(buf[mid].no,x);
				if(tmp==0){
					ans=mid;
					break;
				}
				else if(tmp>0) top=mid-1;
				else base=mid+1;
			}
			if(ans==-1) cout<<"NO ANSWER!"<<endl;
			else{
				cout<<buf[ans].no<<' '<<buf[ans].name<<' '<<buf[ans].sex<<' '<<buf[ans].age<<endl;
			}
		}
	}
	return 0;
}