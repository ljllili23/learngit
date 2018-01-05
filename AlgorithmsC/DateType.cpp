//DateType.cpp
#include<iostream>
using namespace std;
#define ISLEAP(x) x%100!=0 && x%4==0 || x%400==0
//#define ABS(x) (x)<0?-(x):(x);

int dayOfMonth[13][2]=
{
	0,0,
	31,31,
	28,29,
	31,31,
	30,30,
	31,31,
	30,30,
	31,31,
	31,31,
	30,30,
	31,31,
	30,30,
	31,31,
};

struct Date
{
	int Day;
	int Month;
	int Year;

	void nextDay()
	{
		++Day;
		if(Day>dayOfMonth[Month][ISLEAP(Year)])
		{
			Day = 1;
			++Month;
			if(Month>12)
			{
				Month = 1;
				++Year;
			}
		}
}
};


int buf[5001][13][32];

int ABS(int x)
{
	return x<0?(-x):x;
}
int main()
{
	int i,j,k;
	int y1,m1,d1;
	int y2,m2,d2;
	Date tmp;  //temporary Data Object
	int cnt=0; //means count;
	tmp.Day=1;
	tmp.Month=1;
	tmp.Year=0;
	while(tmp.Year!=5001)
	{														/**************************************/
		buf[tmp.Year][tmp.Month][tmp.Day]=cnt; 				//CAUTION!!!!!!!!!!
		cout<<buf[tmp.Year][tmp.Month][tmp.Day]<<endl;		//be careful of the array index!!!!!!别写反了
		//cout<<tmp.Day<<endl;								/*************************************/
		// cout<<cnt<<endl;
		tmp.nextDay();

		cnt++;
	}
	// for(i=1;i<5001;++i)
	// 	for(j=1;j<13;++j)
	// 		for(k=1;k<31;++k)
	// 		{
	// 			cout<<buf[i][j][k]<<endl;
	// 		}
	while(scanf("%4d%2d%2d",&y1,&m1,&d1)!=EOF)
	{
		scanf("%4d%2d%2d",&y2,&m2,&d2);
		printf("How many days?%d\n",ABS(buf[y2][m2][d2]-buf[y1][m1][d1])+1);
	}
	return 0;
}
