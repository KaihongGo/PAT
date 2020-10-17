//PAT A1021.cpp 1021 Deepest Root (25 分)
//2个测试点未过！
//原因：代码并未完全读懂题目意思
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

const int MAXV = 10010;
vector<int> G[MAXV]; //邻接表
bool vis[MAXV];

vector<int> temp;
int maxheight = 0;
void DFS(int u, int height)
{
	if (height > maxheight)
	{				  //更新
		temp.clear(); //temp临时存放DFS最远结点结果
		temp.push_back(u);
		maxheight = height;
	}
	else if (height == maxheight)
		temp.push_back(u);
	vis[u] = true;
	for (int i = 0; i < G[u].size(); i++)
	{
		int v = G[u][i];
		if (vis[v] == false)
			DFS(v, height + 1);
	}
}

int main()
{
	int n; cin >> n;
	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	int block = 0, nextv;
	set<int> vertex;
	for (int u = 1; u <= n; u++)
	{
		if (vis[u] == false)
		{
			block++;
			DFS(u, 1);
			if (u == 1)
			{ //保留第一个结点遍历得到的最远结点
				nextv = temp[0];
				for (int i = 0; i < temp.size(); i++)
					vertex.insert(temp[i]);
			}
		}
	}
	if (block >= 2)
		printf("Error: %d components", block);
	else
	{
		temp.clear();
		maxheight = 0; //再DFS一次
		fill(vis, vis + MAXV, false);
		DFS(nextv, 1);
		for (int i = 0; i < temp.size(); i++)
			vertex.insert(temp[i]);
		for (auto it = vertex.begin(); it != vertex.end(); it++)
			printf("%d\n", *it);
	}
	return 0;
}

