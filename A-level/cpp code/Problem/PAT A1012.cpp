//PAT A1125.cpp 1125 Chain the Ropes (25 分)
//基本思路：优先级按数据下标安排，遍历时第一个值即合法
//代码冗余！！

#include <map>
#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

const int maxn = 100100;

struct info
{
	int course;
	int rank;
};

struct Student
{
	string id;
	//char id[10];
	struct
	{
		int score;
		int rank;
	} Course[4];	//0,A; 1,C; 2,M; 3,E;
} stu[maxn];
//此处可以采用全局变量改造！！
const int A = 0, C = 1, M = 2, E = 3;//0,A; 1,C; 2,M; 3,E;
int flag;	//分别令flag=A,C,M,E!!!

bool cmp_A(Student a, Student b)
{
	return a.Course[0].score > b.Course[0].score;
}
bool cmp_C(Student a, Student b)
{
	return a.Course[1].score > b.Course[1].score;
}
bool cmp_M(Student a, Student b)
{
	return a.Course[2].score > b.Course[2].score;
}
bool cmp_E(Student a, Student b)
{
	return a.Course[3].score > b.Course[3].score;
}

struct info findBest(int index)
{//传入下标
	struct info ans;
	ans.rank = maxn;
	for (int i = 0; i < 4; i++)
	{//遍历四门课程，一位下标已按优先级实现安排；故找到的第一个关键词合法
		if (stu[index].Course[i].rank < ans.rank)
		{
			ans.rank = stu[index].Course[i].rank;
			ans.course = i;
		}
	}
	switch (ans.course)
	{
	case 0:
		ans.course = 'A'; break;
	case 1:
		ans.course = 'C'; break;
	case 2:
		ans.course = 'M'; break;
	case 3:
		ans.course = 'E'; break;
	default:
		break;
	}
	return ans;
}

void getRank(int index, int n)
{
	stu[0].Course[index].rank = 1;
	for (int i = 1; i < n; i++)
	{
		if (stu[i].Course[index].score == stu[i - 1].Course[index].score)
			stu[i].Course[index].rank = stu[i - 1].Course[index].rank;
		else
			stu[i].Course[index].rank = i + 1;
	}
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m); 
	for (int i = 0; i < n; i++)
	{
		cin >> stu[i].id;
		scanf("%d%d%d", &stu[i].Course[C].score, &stu[i].Course[M].score, &stu[i].Course[E].score);
		stu[i].Course[A].score = (stu[i].Course[C].score + stu[i].Course[M].score + stu[i].Course[E].score)/3;
	}
	sort(stu, stu + n, cmp_A);
	getRank(A, n);
	
	sort(stu, stu + n, cmp_C);
	getRank(C, n);
	
	sort(stu, stu + n, cmp_M);
	getRank(M, n);
	
	sort(stu, stu + n, cmp_E);
	getRank(E, n);

	map<string, int> mp;
	for (int i = 0; i < n; i++)
	{
		mp[stu[i].id] = i;//建立下标与string map
	}

	string id;
	for (int i = 0; i < m; i++)
	{
		cin >> id;
		auto it = mp.find(id);	
		struct info ans = findBest(mp[id]);
		if (it != mp.end())
		{
			printf("%d %c\n", ans.rank, ans.course);
		}
		else
			printf("N/A\n");
	}
	return 0;
}