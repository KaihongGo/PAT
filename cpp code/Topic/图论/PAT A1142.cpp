//PAT A1142.cpp 1142 Maximal Clique (25 分)
//暴力解决,出现段错误！？
//数组越界，往往没考虑到起始与结束下标哦
//变量输入时错了，赋错值了；导致数组越界
#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

const int MAXV = 300;
const int INF = 0x3fffffff;

set<int> Adj[MAXV];
int showNum[MAXV] = { 0 };//所有邻接点出行次数
int nv, ne;

bool judge(vector<int> query)
{
	int flag = true;
	for (int i = 0; i < query.size(); i++)
	{	//两两比较
		for (int j = i + 1; j < query.size(); j++)
		{
			int u = query[i], v = query[j];
			if (Adj[u].find(v) == Adj[u].end())
			{	//不连接
				flag = false;
				break;
			}
		}
	}
	return flag;
}

int main()
{
	cin >> nv >> ne;
	for (int i = 0; i < ne; i++)
	{
		int u, v;
		cin >> u >> v;
		Adj[u].insert(v);
		Adj[v].insert(u);
	}
	int m, k;
	cin >> m;
	while (m--)
	{
		cin >> k;	//k个点
		vector<int> query;
		query.resize(k);
		fill(showNum, showNum + nv + 7, 0);	//复原
		for (int i = 0; i < k; i++)
		{
			cin >> query[i];
			int u = query[i];
			for (auto it = Adj[u].begin(); it != Adj[u].end(); it++)
			{	//该结点所有邻接点
				int v = *it;
				showNum[v]++;	//出现次数++
			}
		
		}
		bool flagOther = false;
		for (int i = 1; i <= nv; i++)
		{	//判断是否有其他邻接点
			if (showNum[i] == k)
				flagOther = true;
		}

		bool flag = judge(query);
		if (flag == true)
		{
			if (flagOther == true)
				printf("Not Maximal\n");
			else 
				printf("Yes\n");
		}
		else
			printf("Not a Clique\n");
	}
}

