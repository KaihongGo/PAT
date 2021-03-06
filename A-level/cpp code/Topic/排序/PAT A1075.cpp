//PAT A1075.cpp 1075 PAT Judge (25 分)
//
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int n, k, m;
const int maxn = 100010;

struct Student
{
	bool pass;
	int id = 0;
	int rank = 0;
	int problem[10];//弃用0下标
	int total;
	int perfect;
	
	Student() {
		fill(problem, problem + 10, -2);	// -2, not answer; -1, not pass complier; 0-100;
		total = 0;
		perfect = 0;
		pass = false;
	}
} stu[maxn];
	
bool cmp(Student a, Student b)
{	//此句is the reason thar cauase a bug!! caution to it!! when you think of unvalid data
	if (a.pass != b.pass) return a.pass > b.pass;
	else if (a.total != b.total) return a.total > b.total;
	else if (a.perfect != b.perfect) return a.perfect > b.perfect;
	else return a.id < b.id;
}

int main()
{
	int full[10] = { 0 };
	cin >> n >> k >> m;
	for (int i = 1; i <= k; i++)
		cin >> full[i];

	for (int i = 0; i < m; i++)
	{
		int uid, pid, socre;
		cin >> uid >> pid >> socre;
		stu[uid].id = uid;
		
		if (socre != -1)
			stu[uid].pass = true;
		else
			socre = 0;
		
		stu[uid].problem[pid] = max(stu[uid].problem[pid], socre);
	}
	//cal total score
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if (stu[i].problem[j] != -2)
			{
				stu[i].total += stu[i].problem[j];
				if (stu[i].problem[j] == full[j])
					stu[i].perfect++;
			}
		}
	}
	//sort ans ranking 
	sort(stu, stu + n+1, cmp);
	stu[0].rank = 1;
	for (int i = 1; i < n && stu[i].pass; i++)
	{
		if (stu[i].total == stu[i - 1].total)
			stu[i].rank = stu[i - 1].rank;
		else
			stu[i].rank = i + 1;
	}
	
	for (int i = 0; i < n && stu[i].pass; i++)
	{
		printf("%d %05d %d", stu[i].rank, stu[i].id, stu[i].total);
		for (int j = 1; j <= k; j++)
		{
			if (stu[i].problem[j] != -2)
				printf(" %d", stu[i].problem[j]);
			else
				printf(" -");
		}
		printf("\n");
	}
}