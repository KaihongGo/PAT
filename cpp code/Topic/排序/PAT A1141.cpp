//PAT A1141.cpp 1141 PAT Ranking of Institutions (25 分)
//
#include <iostream>
#include <cstdio>
#include <numeric>
#include <vector>
#include <cctype>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

const int maxn = 100010;

struct Test 
{
	int score[3]; //0,A; 1, B; 2, T; score a,b,t;
	int rank;
	int TWS, Ns;
	string code;//all lowcase
} test[maxn];

map<string, int> codetoi;//code to index; lowcase
map<int, string> itocode;//int to code
int num = 0;	//how many school,count;

bool cmp(Test a, Test b)
{
	if (a.TWS != b.TWS) return a.TWS > b.TWS;
	else if (a.Ns != b.Ns) return a.Ns < b.Ns;
	else return a.code < b.code;
}

int main()
{
	int n; cin >> n;
	map<char, int> idtoi;
	idtoi['A'] = 0;
	idtoi['B'] = 1;
	idtoi['T'] = 2;
	
	for (int i = 0; i < n; i++)
	{
		string id, school;
		int score; 
		cin >> id >> score >> school;
		for (auto it = school.begin(); it != school.end(); it++)
		{	//全部变为小写
			*it = tolower(*it);
		}
		
		if (codetoi.find(school)==codetoi.end())
		{	//这么写，不要 == 0
			itocode[num] = school;
			codetoi[school] = num++; //create index;
		}
		int index = codetoi[school];
		test[index].Ns++;
		test[index].code = school;
		test[index].score[idtoi[id[0]]] += score;
	}
	for (int i = 0; i < num; i++)
	{	//ScoreB/1.5 + ScoreA + ScoreT*1.5
		test[i].TWS = test[i].score[0] + test[i].score[1] / 1.5 + test[i].score[2] * 1.5;
	}
	//get rank
	sort(test, test + num, cmp);
	test[0].rank = 1;
	for (int i = 1; i < num; i++)
	{
		if (test[i].TWS == test[i - 1].TWS)
			test[i].rank = test[i - 1].rank;
		else
			test[i].rank = i + 1;
	}
	printf("%d\n", num);
	for (int i = 0; i < num; i++)
	{
		printf("%d %s %d %d\n", test[i].rank, test[i].code.c_str(), test[i].TWS, test[i].Ns);
	}
	return 0;
}