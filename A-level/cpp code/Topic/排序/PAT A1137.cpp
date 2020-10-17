//PAT A1137.cpp 1137 Final Grading (25 分)
// 
#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <map>
#include <cmath>
using namespace std;

const int maxn = 100010;
struct Student
{
	int point = -1;
	int mid = -1, final = -1;
	double total = -1;
	string id;
	bool valid = false;
} stu[maxn];
int num = 0;//人数
map<string, int> idtoi;
map<int, string> itoid;

bool cmp(Student a, Student b)
{
	if (a.valid != b.valid) return a.valid > b.valid;
	else if (a.total != b.total) return a.total > b.total;
	else return a.id < b.id;	
}

int main()
{
	int p, m, n;
	cin >> p >> m >> n;
	string id;
	int score;
	//输入
	for (int i = 0; i < p; i++)
	{
		cin >> id >> score;
		if (idtoi.find(id) == idtoi.end())
		{	//没有记录
			itoid[num] = id;
			idtoi[id] = num++;
		}
		int index = idtoi[id];
		stu[index].id = id;
		stu[index].point = score;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> id >> score;
		if (idtoi.find(id) == idtoi.end())
		{	//没有记录
			itoid[num] = id;
			idtoi[id] = num++;
		}
		int index = idtoi[id];
		stu[index].id = id;
		stu[index].mid = score;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> id >> score;
		if (idtoi.find(id) == idtoi.end())
		{	//没有记录
			itoid[num] = id;
			idtoi[id] = num++;
		}
		int index = idtoi[id];
		stu[index].id = id;
		stu[index].final = score;
	}
	//
	int validcnt = 0;
	for (int i = 0; i < num; i++)
	{
		if (stu[i].mid > stu[i].final)
			stu[i].total = stu[i].mid * 0.4 + stu[i].final * 0.6;
		else
			stu[i].total = stu[i].final;
		stu[i].total = round(stu[i].total);
		if (stu[i].total >= 60 && stu[i].point >= 200)
		{
			stu[i].valid = true;
			validcnt++;
		}
	}
	sort(stu, stu + num, cmp);
	for (int i = 0; i < validcnt; i++)
	{
		printf("%s %d %d %d %.0lf\n", stu[i].id.c_str(), stu[i].point, stu[i].mid, stu[i].final, stu[i].total);
	}
	return 0;
}