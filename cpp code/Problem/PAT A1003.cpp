//PAT A1003.cpp Emergency
//
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXV = 550; //最大顶点
const int INF = 0x3fffffff;
int G[MAXV][MAXV];
int weight[MAXV];				 //存储点权
int d[MAXV], num[MAXV], w[MAXV]; //distance, num of path, weight
bool vis[MAXV];
int n;

void Dijkstra(int s)
{ //初始化
	fill(d, d + MAXV, INF);
	fill(num, num + MAXV, 0);
	fill(w, w + MAXV, 0);

	d[s] = 0;
	num[s] = 1;
	w[s] = weight[s];
	
	for (int i = 0; i < n; i++)
	{
		int u = -1, MIN = INF;
		for (int j = 0; j < n; j++)
		{
			if (vis[j] == false && d[j] < MIN)
			{
				u = j;
				MIN = d[j];
			}
		}
		if (u == -1)
			return;

		vis[u] = true;
		for (int v = 0; v < n; v++)
		{
			if (vis[v] == false && G[u][v] != INF)
			{
				if (d[u] + G[u][v] < d[v])
				{
					d[v] = d[u] + G[u][v];
					num[v] = num[u];
					w[v] = w[u] + weight[v];
				}
				else if (d[u] + G[u][v] == d[v])
				{
					if (w[u] + weight[v] > w[v])
						w[v] = w[u] + weight[v];
					num[v] += num[u]; //最短距离相同时，累加num[u]
				}
			}
		}
	}
}

int main()
{
	fill(G[0], G[0] + MAXV * MAXV, INF);
	int m, st, ed;
	cin >> n >> m >> st >> ed;
	for (int i = 0; i < n; i++)
		cin >> weight[i];
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		cin >> G[u][v];
		G[v][u] = G[u][v];
	}
	Dijkstra(st);
	cout << num[ed] << " " << w[ed] << endl;
}
