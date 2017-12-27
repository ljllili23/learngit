//recursion
#include <iostream>
using namespace std;
float arrayavg(float A[],int i,int j)
{
	if(i==j)
		return A[i];
	else
		return ((A[i]+(j-i)*arrayavg(A,i+1,j))/j-i+1);

}
int main()
{
	float A[]={23,23,23,23,23,23,23};
	
	cout<<arrayavg(A,0,6)<<endl;
	return 0;
}