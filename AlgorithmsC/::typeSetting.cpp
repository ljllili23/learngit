//typeSetting.cpp
#include <iostream>
using namespace std;
int main(){
	int h;
	while(cin>>h){
		int maxLine = h+(h-1)*2;
		for(int i=0;i<h;++i){
			for(int j=0;j<maxLine;++j){
				if(j<maxLine-h-i*2)
					cout<<' ';
				else cout<<'*';
			}
			cout<<endl;
		}
	}
	return 0;
}