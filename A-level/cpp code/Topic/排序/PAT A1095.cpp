//PAT A1095.cpp 1095 Cars on Campus (30 分)
//
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
const int maxn = 10010;

struct Node
{
	int time;
	string status;
	string platenum;
	bool valid = true;//开始假设所有元素均有效,做标记剔除无效元素
};
vector<Node> record;
map<string, int> isIn;	  //第i条记录登记了
map<string, int> duration;//停留时间 
map<string, int> intime;  //进入时间
map<string, int> outtime; //出时间

int tosec(int hh, int mm, int ss)
{
	return hh * 3600 + mm * 60 + ss;
}

string tohour(int time)
{
	char str[20];
	int hh = time / 3600;
	int ss = time % 60;
	int mm = (time / 60) - hh * 60;
	sprintf(str, "%02d:%02d:%02d", hh, mm, ss);
	string ans(str);
	return ans;
}

bool cmp1(Node a, Node b)
{
	return a.time < b.time;
}

int main()
{
	int n, k, num = 0;//num，车辆台数
	cin >> n >> k;
	record.resize(n);
	for (int i = 0; i < n; i++)
	{
		string platenum;
		int hh, mm, ss;
		string status;
		cin >> platenum;
		scanf("%d:%d:%d", &hh, &mm, &ss);
		cin >> status;
		
		isIn[platenum] = -1;//记录均为进行模拟
		record[i].time = tosec(hh, mm, ss);
		record[i].status = status;
		record[i].platenum = platenum;
	}
	sort(record.begin(), record.end(), cmp1); //按进入时间排序，进行模拟
	for (int i = 0; i < n; i++)
	{	//删除无效数据
		string platenum = record[i].platenum;
		if (record[i].status == "in")
		{
			if (isIn[platenum] != -1)
			{	//先前进来了,先前记录无效
				record[isIn[platenum]].valid = false;
			}//删除元素又用到数组长度作为操作区间；很危险！！！
			else
				isIn[platenum] = i;//传入下标
		}
		else
		{	//out 
			if (isIn[platenum] != -1)
			{	//先前进来了
				isIn[platenum] = -1;
			}
			else//已经出去了，当前记录无效
				record[i].valid = false;
		}
	}
	vector<int> ans;
	while (k--)
	{	//k query
		int hh, mm, ss;
		scanf("%d:%d:%d", &hh, &mm, &ss);
		int query = tosec(hh, mm, ss);
		int i = 0;//index 
		int incnt = 0;//car in campus 
		
		while (i < n && record[i].time <= query)
		{
			if (record[i].valid)
			{
				string platenum = record[i].platenum;
				if (record[i].status == "in")
					incnt++;
				else if (record[i].status == "out")
					incnt--;
			}
			i++;
		}
		ans.push_back(incnt);
	}
	for (int i = 0; i < ans.size(); i++)
		printf("%d\n", ans[i]);
	//find the max duration 
	for (int i = 0; i < n; i++)
	{
		if (record[i].valid)
		{
			string platenum = record[i].platenum;
			if (record[i].status == "in")
				intime[platenum] = record[i].time;
			else
			{
				outtime[platenum] = record[i].time;
				duration[platenum] += outtime[platenum] - intime[platenum];
			}
		}
	}
	int max = duration.begin()->second;
	for (auto it = duration.begin(); it != duration.end(); it++)
	{
		if (it->second > max)
			max = it->second;
	}
	for (auto it = duration.begin(); it != duration.end(); it++)
	{
		if(it->second == max)
			cout << it->first << " ";
	}
	cout <<tohour(max);
	return 0;
}