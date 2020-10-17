//PAT A1126.cpp 1126 Eulerian Path (25 分)
//一个测试点未过
//原因：未判断图的连通性

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXV = 550;
const int INF = 0x3fffffff;
int n, m;
vector<int> Adj[MAXV];

int vis[MAXV] = { false };
int cnt = 0;
void DFS(int v)
{
	cnt++;
	vis[v] = true;
	for (int i = 0; i < Adj[v].size(); i++)
	{
		if(vis[Adj[v][i]] == false)
			DFS(Adj[v][i]);
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		Adj[u].push_back(v);
		Adj[v].push_back(u);
	}
	vector<int> degree;
	int numOdd = 0;
	for (int i = 1; i <= n; i++)
	{	//遍历所有结点
		degree.push_back(Adj[i].size());
		if (Adj[i].size() % 2 != 0)
			numOdd++;
	}
	for (int i = 0; i < degree.size(); i++)
	{
		printf("%d", degree[i]);
		if (i != degree.size() - 1)
			printf(" ");
	}
	printf("\n");
	DFS(1);
	if (cnt != n)
	{
		printf("Non-Eulerian\n");
	}
	else
	{
		if (numOdd == 0)
			printf("Eulerian\n");
		else if (numOdd == 2)
			printf("Semi-Eulerian\n");
		else
			printf("Non-Eulerian\n");
	}
	
}