//stack_201802_02_Calculator.cpp
#include <stdio.h>
#include <stack>

using namespace std;  // WARNING!!! This is a bad practice, but will be proper in computer test.
char str[220];
int mat[][5]={			//Priority Matrix
	1,0,0,0,0,
	1,0,0,0,0,
	1,0,0,0,0,
	1,1,1,0,0,
	1,1,1,0,0,
};
stack<int> op;
stack<double> in;
void getOp(bool &reto,int &retn, int &i){  	//reto means return op? 
											//retn means return number of matrix index ,namely 运算符编号
	if(i==0&&op.empty()==true){
		reto = true;
		retn = 0;
		return;
	}
	if(str[i]==0){
		reto = true;
		retn =0;
		return;
	} 
	if(str[i]>='0'&&str[i]<='9'){
		reto=false;
		retn=0;
		for(;str[i] !=' '&&str[i]!=0;++i){
			retn*=10;
			retn+=str[i]-'0';
		}
		if (str[i]==' ')
			++i;
		return;
	}
	else{
		reto = true;
		if(str[i] == '+'){
			retn = 1;
		}
		else if(str[i] == '-'){
			retn =2;
		}
		else if(str[i] == '*'){
			retn =3;
		}
		else if(str[i] == '/'){
			retn = 4;
		}
		i+=2;
		return;

	}
}

int main(){
	while(gets(str)){
		if(str[0]=='0'&&str[1]==0)
			break;
		bool retop; int retnum;
		int idx = 0;
		while(!op.empty()) op.pop();
		while(!in.empty()) in.pop();
		while(true){
			getOp(retop,retnum,idx);
			if(retop==false){
				in.push((double)retnum);
			}
			else{
				double tmp;
				if(op.empty()==true||mat[retnum][op.top()]==1){
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
						if(ret==1) tmp = a+b;
						else if(ret==2) tmp=a-b;
						else if(ret==3)	tmp=a*b;
						else tmp=a/b;
						in.push(tmp);
					}
					op.push(retnum);
				}
			}
			if(op.size()==2&&op.top()==0) break;
		}
		printf("%.2f\n", in.top());
	}
	return 0;
}


























