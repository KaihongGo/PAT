//PAT A1153.cpp 1153 Decode Registration Card of PAT (25 分)
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;

struct Student
{
	string id;
	int socre;
};
const int maxn = 1000;
map<char, vector<Student> > level;//按等级划分
map<int, vector<Student> > site;//按site划分
map<int, map<int, int> > date;
//日期-> 映射 site -> (人数)

bool cmp_score(Student a, Student b)
{
	if (a.socre != b.socre) return a.socre > b.socre;
	else return a.id < b.id;
}
struct Node
{
	int site;
	int num;
};
bool cmp_date(Node a, Node b)
{
	if (a.num != b.num) return a.num > b.num;
	else return a.site < b.site;
}

int main()
{
	int n, m; cin >> n >> m;
	string id; int score;
	for (int i = 0; i < n; i++)
	{
		cin >> id >> score;
		char L = id[0];//level;
		int sitenum = stoi(id.substr(1, 3));
		int year = stoi(id.substr(4, 6));
		Student stu{ id,score };
		level[L].push_back(stu);
		site[sitenum].push_back(stu);
		date[year][sitenum]++;
	}
	for (int i = 0; i < m; i++)
	{
		int type; cin >> type;
		printf("Case %d: %d ", i + 1,type);
		if (type == 1)
		{
			char L; cin >> L;
			printf("%c\n", L);
			if (level.find(L) == level.end())
			{
				printf("NA\n"); continue;
			}
			sort(level[L].begin(), level[L].end(), cmp_score);
			for (int j = 0; j < level[L].size(); j++)
				printf("%s %d\n", level[L][j].id.c_str(), level[L][j].socre);
		}
		else if (type == 2)
		{
			int sitenum; cin >> sitenum;
			printf("%03d\n", sitenum);
			if (site.find(sitenum) == site.end())
			{
				printf("NA\n"); continue;
			}
			int totalscore = 0;
			for (int j = 0; j < site[sitenum].size(); j++)
				totalscore += site[sitenum][j].socre;
			printf("%d %d\n", site[sitenum].size(), totalscore);
		}
		else if (type == 3)
		{
			int year; cin >> year;
			printf("%06d\n", year);
			if (date.find(year) == date.end())
			{
				printf("NA\n"); continue;
			}
			vector<Node> ans;
			for (auto it = date[year].begin(); it != date[year].end(); it++)
				ans.push_back({ it->first, it->second });
			sort(ans.begin(), ans.end(), cmp_date);
			for (auto it = ans.begin(); it != ans.end(); it++)
				printf("%d %d\n", it->site, it->num);
		}
	}
	return 0;
}

