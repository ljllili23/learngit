#include <stdio.h>
#include <stack>

using namespace std;

int mat[][5]={
	1,0,0,0,0,
	1,0,0,0,0,
	1,0,0,0,0,
	1,1,1,0,0,
	1,1,1,0,0,
};

stack <int> op;
stack <double> in;

char str[220];  //WHY 220 ?

void getOp(bool &retop, int &retnum, int &i){
	if(i==0&&op.empty()){
		retop=true;
		retnum=0;
		return;
	}
	if(str[i]==0){
		retop=true;
		retnum=0;
		return;
	}
	if(str[i]>='0'&&str[i]<='9'){
		retop=false;
		retnum=0;
		for(;str[i]!=' '&&str[i]!=0;++i){
			retnum*=10;
			retnum+=str[i]-'0';
		}
		if(str[i]==' ')
			++i;
		return;
	}
	else{
		retop=true;
		if(str[i]=='+'){
			retnum=1;
		}
		else if(str[i]=='-'){
			retnum=2;
		}
		else if(str[i]=='*'){
			retnum=3;
		}
		else if(str[i]=='/'){
			retnum=4;
		}
		i+=2;
		return;
	}
}

int main(){
	while(gets(str)){
		
		if(str[0]=='0'&&str[1]==0) break;
		bool retop;
		int retnum;  //when retop=false,cast retnum into double type;
		int i=0;  //index of the string.
		while(!op.empty()) op.pop();
		while(!in.empty()) in.pop();
		while(true){
			getOp(retop,retnum,i);
			if(retop==false){
				in.push((double)retnum);
			}
			else{
				double tmp;
				if(op.empty()||mat[retnum][op.top()]==1){
					op.push(retnum);
				}
				else{
					while(mat[retnum][op.top()]==0){
						int ret=op.top();
						op.pop();
						double b=in.top();
						in.pop();
						double a=in.top();
						in.pop();
						if(ret==1) tmp=a+b;
						else if(ret==2) tmp=a-b;
						else if(ret==3) tmp=a*b;
						else tmp=a/b;
						in.push(tmp);
					}
					op.push(retnum);
				}
			}		
			if(op.size()==2&&op.top()==0) break;
		}
		printf("%.2f\n",in.top());
	}
	return 0;
}