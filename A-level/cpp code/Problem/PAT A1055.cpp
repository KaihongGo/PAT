//PAT A1055.cpp 1055 The World's Richest (25 分)
//基本思路：

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100010;

struct Person
{
	char name[10];
	int age;
	int worth;
} per[maxn];


bool cmp(Person a, Person b)
{
	if (a.worth != b.worth)
	{
		return a.worth > b.worth;
	}
	else
	{
		if (a.age == b.age)
			return strcmp(a.name,b.name) <= 0;
		else return a.age < b.age;
	}
}


int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s%d%d", &per[i].name, &per[i].age, &per[i].worth);
	sort(per, per + n, cmp);
	int x, Amin, Amax;
	for (int i = 0; i < m; i++)
	{
		int num = 0;
		bool flag = false;
		scanf("%d %d %d", &x, &Amin, &Amax);
		printf("Case #%d:\n", i + 1);
		for (int j = 0; j < n; j++)
		{
			if (num == x)
				break;
			if (per[j].age >= Amin && per[j].age <= Amax)
			{
				printf("%s %d %d\n", per[j].name, per[j].age, per[j].worth);
				num++;
				flag = true;
			}
		}
		if (!flag) printf("None\n");//无输出
	}
	return 0;
}

