#include <iostream>
#include <algorithm>
//using std::sort;

int main()
{
	int n,i;
	struct stu
	{
		char name[101]; //why 101 ?
		int age;
		int score;
		bool operator < (const stu &b) const
		{
			if(score!=b.score) return score<b.score;
			else if (!strcmp(name,b.name))	return strcmp(name,b.name);
			else return age<b.age;
		}
	}stu[1000];
	while(scanf("%d",&n))
	{
		for(i=0;i<n;++i)
		{
			scanf("%s%d%d", stu[i].name,&stu[i].age,&stu[i].score);
		}
		std::sort(stu,stu+n);
		for(i=0;i<n;++i)
		{
			printf("%s %d %d\n",stu[i].name,stu[i].age,stu[i].score);
		}
	}

	return 0;
}