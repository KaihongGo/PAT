//PAT A1139.cpp 1139 First Contact (30 分)
//利用set自排序，提前处理输入数据
//const常量定义常值

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;

const int boy = 1;
const int girl = 0;
const int maxn = 10010;

struct Person
{
	int id;
	int gender;//1,boy; 0,girl;
	friend bool operator < (Person a, Person b)
	{	//将其朋友按照id排序
		return a.id < b.id;
	}
};
//利用set自排序
set<Person> frien[maxn];
Person convert(string str)
{//将字符串转换为结点
	Person a;
	if (str[0] == '-') {
		a.gender = girl;
		str.erase(str.begin());
	}
	else a.gender = boy;
	a.id = stoi(str);
	return a;
}

int main()
{
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		string s1, s2; cin >> s1 >> s2;
		Person a, b;
		a = convert(s1);
		b = convert(s2);
		//添加a朋友,b;
		frien[a.id].insert(b);
		//添加b朋友, a
		frien[b.id].insert(a);
	}
	int k; cin >> k;
	for (int i = 0; i < k; i++)
	{	// k queries
		string s1, s2; cin >> s1 >> s2;
		Person a, b;
		a = convert(s1);
		b = convert(s2);
		int cnt = 0; 
		vector<string> ans;
		for (auto afrien = frien[a.id].begin(); afrien != frien[a.id].end(); afrien++)
		{	//遍历a的朋友
			if (afrien->gender != a.gender) continue;//跳过不同性别
			else if (afrien->id == b.id) continue;	//避免找到b
			else
			{	//遍历a朋友的朋友，看其性别与b是否相同，且其为b的朋友
				for (auto aff = frien[afrien->id].begin(); aff != frien[afrien->id].end(); aff++)
				{
					if (aff->id == a.id) continue;	//跳过a
					if (aff->gender == b.gender && frien[b.id].find(*aff) != frien[b.id].end())
					{	//字符串，vector拼接答案
						cnt++;
						char str[100];
						sprintf(str,"%04d %04d\n", afrien->id, aff->id);
						ans.push_back(str);
					}
				}
			}
		}
		cout << ans.size() << endl;
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i];
	}
}