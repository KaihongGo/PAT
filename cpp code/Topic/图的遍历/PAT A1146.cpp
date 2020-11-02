//PAT A1146.cpp 1146 Topological Order (25 分)
//
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxv = 1010;
vector<int> adj[maxv];
bool vis[maxv];//是否访问了

int main()
{
	int n, m;
	cin >> n >> m;//n vertex; m edge;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
	int k; cin >> k;
	vector<int> ans;
	for (int i = 0; i < k; i++)
	{//m次query
		fill(vis, vis + maxv, false);
		bool flag = true;
		for (int j = 0; j < n; j++)
		{	//输入序列的每个点
			int u; cin >> u;
			vis[u] = true;//访问u
			for (auto it = adj[u].begin(); it != adj[u].end(); it++)
			{	//u能到到的所有顶点
				int v = *it;
				if (vis[v] == true)
					flag = false;
			}
		}
		if (flag == false)
			ans.push_back(i);//第i次不是
	}
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i];
		if (i != ans.size() - 1) cout << " ";
	}
}