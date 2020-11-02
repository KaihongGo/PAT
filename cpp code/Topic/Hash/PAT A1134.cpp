//PAT A1134.cpp 1134 Vertex Cover (25 分)
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int isExist[maxn] = { 0 };//点先前存在
vector<int> adj[maxn];//无向图处理
int main()
{
	int n, m;//n vertices; m edges;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int k;
	cin >> k;
	while (k--)
	{//k queries
		int cnt = 0;//count edge
		int nv; cin >> nv;
		fill(isExist, isExist + maxn, 0);
		for (int i = 0; i < nv; i++)
		{
			int v;
			cin >> v;
			isExist[v] = 1;//该结点访问了
			for (int j = 0; j < adj[v].size(); j++)
			{
				if (isExist[adj[v][j]] ==0)//先前j结点并未访问
				{
					cnt++;
				}
			}
		}
		if (cnt != m)
			printf("No\n");
		else
			printf("Yes\n");
	}
}