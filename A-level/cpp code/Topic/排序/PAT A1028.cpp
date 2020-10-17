//PAT A1028.cpp 1028 List Sorting (25 分)
//基础排序题，sort()
//此种情况一个测试点未过！时间损耗大；估计cmp函数问题
// increasing order;non-decreasing order 理解
// 大数据量情况下，string用cout输出会超时
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

int C = 0;
//0,ID; 1,name; 2,grades;
const int maxn = 100010;
struct Student
{
	string items[3];
}stu[maxn];

bool cmp(Student a, Student b)
{
	if (a.items[1] != b.items[1] && a.items[2] != b.items[2])
		return a.items[C - 1] < b.items[C - 1];
	else
		return a.items[0] < b.items[0];
}

int main()
{
	int n;
	scanf("%d %d", &n, &C);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
			cin >> stu[i].items[j];
	}
	sort(stu, stu + n, cmp);
	for (int i = 0; i < n; i++)
	{
		printf("%s %s %s\n", stu[i].items[0].c_str(), stu[i].items[1].c_str(), stu[i].items[2].c_str());
		//cout << stu[i].items[0] << " " << stu[i].items[1] << " " << stu[i].items[2] << endl;
	}
}