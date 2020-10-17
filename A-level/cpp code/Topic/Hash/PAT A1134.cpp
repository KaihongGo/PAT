//PAT A1134.cpp 1134 Vertex Cover (25 ��)
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int isExist[maxn] = { 0 };//����ǰ����
vector<int> adj[maxn];//����ͼ����
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
			isExist[v] = 1;//�ý�������
			for (int j = 0; j < adj[v].size(); j++)
			{
				if (isExist[adj[v][j]] ==0)//��ǰj��㲢δ����
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