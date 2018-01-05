//typeSetting_02.cpp
#include <iostream>
using namespace std;
int main(){
	int outPutBuf[82][82];  //CAUTION!!!!!!! WHY INT type NOT CHAR type???!!!!
	char a,b;
	int n;
	bool firstCase = true;
	while(scanf("%d %c %c",&n,&a,&b)==3){   //WHY HERE NEEDS SPACING?? 在用"%c"输入时，空格和“转义字符”均作为有效字符。
		cout<<a<<b<<endl;
		if(firstCase==true){
			firstCase=false;
		}else
		printf("\n");
		for(int i=1,j=1;i<=n;i+=2,++j){
			int x=n/2+1, y=x;
			x-=j-1;y-=j-1;
			char c=j%2==1?a:b;
			for(int k=1;k<=i;++k){
				outPutBuf[x+k-1][y]=c;
				outPutBuf[x][y+k-1]=c;
				outPutBuf[x+k-1][y+i-1]=c;
				outPutBuf[x+i-1][y+k-1]=c;
			}
		}
		if(n!=1){
			outPutBuf[1][1]=' ';
			outPutBuf[1][n]=' ';
			outPutBuf[n][1]=' ';
			outPutBuf[n][n]=' ';
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
printf("%c",outPutBuf[i][j]);
			}
			printf("\n");
		}
	}
	return 0;

}