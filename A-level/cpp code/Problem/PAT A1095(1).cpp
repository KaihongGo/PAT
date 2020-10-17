//PAT A1095.cpp 1095 Cars on Campus (30 分)
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Node
{
	int time;
	bool valid;//
	string status;
	string platenum;
};

vector<Node> record;

bool cmp1(Node a, Node b)
{
	if (a.platenum != b.platenum)
		return a.platenum < b.platenum;
	else
		return a.time < b.time;
}

bool cmp2(Node a, Node b)
{
	return a.time < b.time;
}

int toSec(int hh, int mm, int ss)
{
	return hh * 3600 + mm * 60 + ss;
}

int main()
{
	int n, k;
	cin >> n >> k;
	record.resize(n);
	for (int i = 0; i < n; i++)
	{
		string platenum, status;
		int hh, mm, ss;
		cin >> platenum;
		scanf("%d:%d:%d", &hh, &mm, &ss);
		cin >> status;
		record[i].platenum = platenum;
		record[i].status = status;
		record[i].valid = false;
		record[i].time = toSec(hh, mm, ss);
	}
	sort(record.begin(), record.end(), cmp1);
	//筛选有效数据
	map<string, int> parkTime;
	int maxParktime = 0;
	for (int i = 0; i < n - 1; i++)
	{
		if (record[i].platenum == record[i + 1].platenum && record[i].status == "in" && record[i + 1].status == "out")
		{
			record[i].valid = true;
			record[i + 1].valid = true;
			parkTime[record[i].platenum] += record[i + 1].time - record[i].time;
		}
		maxParktime = max(maxParktime, parkTime[record[i].platenum]);
	}
	
	//统计
	sort(record.begin(), record.end(), cmp2);
	int i = 0, incnt = 0;
	while (k--)
	{	//k query
		int query, hh, mm, ss;
		scanf("%d:%d:%d", &hh, &mm, &ss);
		query = toSec(hh, mm, ss);
		while (i < n && record[i].time <= query)
		{
			if (record[i].valid)
			{
				if (record[i].status == "in")
					incnt++;
				else
					incnt--;
			}
			i++;
		}
		printf("%d\n", incnt);
	}
	for (auto it = parkTime.begin(); it != parkTime.end(); it++)
	{
		if (it->second == maxParktime)
			printf("%s ", it->first.c_str());
	}
	printf("%02d:%02d:%02d", maxParktime / 3600, maxParktime % 3600 / 60, maxParktime % 60);
	return 0;
	
}