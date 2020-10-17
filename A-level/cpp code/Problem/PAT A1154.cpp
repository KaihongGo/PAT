//PAT A1154.cpp 1154 Vertex Coloring (25 分)
//

#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXV = 10010;
int n, m;

struct node
{
	int color = -1;
	vector<int> next;
} Adj[MAXV];

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		Adj[u].next.push_back(v);
		Adj[v].next.push_back(u);
	}
	int k;
	cin >> k;
	while (k--)
	{
		bool flag = true;
		set<int> colorNum;
		for (int i = 0; i < n; i++)
		{
			int color;
			cin >> color;
			colorNum.insert(color);
			Adj[i].color = color;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < Adj[i].next.size(); j++)
			{	//相邻结点
				int id = Adj[i].next[j];
				if (Adj[i].color == Adj[id].color)
					flag = false;
			}
		}
		if (flag == true)
			printf("%d-coloring\n", colorNum.size());
		else
			printf("No\n");
	}
	return 0;
	
}