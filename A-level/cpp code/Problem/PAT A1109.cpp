//PAT A1109.cpp 1109 Group Photo (25 分)
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
const int maxn = 100010;
struct Student
{
	string name;
	int height;
};
vector<Student> stu;

bool cmp(Student a, Student b)
{
	if (a.height != b.height) return a.height > b.height;
	else return a.name < b.name;
}

void Group(vector<Student> vi)
{
	vector<Student> temp;
	int center = vi.size() / 2 + 1;
	temp.push_back(vi[0]);//插入最高的
	for (int i = 1; i < vi.size(); i++)
	{
		if (i % 2 != 0)
			temp.insert(temp.begin(), vi[i]);//高 左
		else
			temp.insert(temp.end(), vi[i]);//低 右
	}
	for (int i = 0; i < temp.size(); i++)
	{
		cout << temp[i].name;
		if (i != temp.size() - 1)
			printf(" ");
		else printf("\n");
	}
}

int main()
{
	int n, k; cin >> n >> k;
	stu.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> stu[i].name >> stu[i].height;
	}
	sort(stu.begin(), stu.end(), cmp);
	int step = n / k;
	int last = n / k + n % k;//最后一行人数 
	vector<Student> vi;
	for (int i = 0; i < last; i++)
	{
		vi.push_back(stu[i]);
	}
	Group(vi);
	
	for (int i = last; i < n; i += step)
	{
		vi.clear();
		for (int j = 0; j < step; j++)
		{
			vi.push_back(stu[i + j]);
		}
		Group(vi);
	}

}