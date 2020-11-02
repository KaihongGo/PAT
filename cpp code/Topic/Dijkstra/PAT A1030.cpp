//PAT A1030.cpp 1030 Travel Plan (30 ·Ö)
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXV = 550;
const int INF = 0x3fffffff;

int G[MAXV][MAXV], cost[MAXV][MAXV];
int d[MAXV], c[MAXV];
bool vis[MAXV] = { false };
int n; int pre[MAXV];

void Dijkstra(int s)
{
	fill(d, d + MAXV, INF); d[s] = 0;
	fill(c, c + MAXV, INF); c[s] = 0;
	for (int i = 0; i < n; i++) pre[i] = i;
	for (int i = 0; i < n; i++) {
		int u = -1, MIN = INF;
		for (int j = 0; j < n; j++) {
			if (vis[j] == false && d[j] < MIN) {
				MIN = d[j];
				u = j;
			}
		}
		if (u == -1) return;
		vis[u] = true;
		for (int v = 0; v < n; v++) {
			if (vis[v] == false && G[u][v] != INF) {
				if (d[u] + G[u][v] < d[v]) {
					d[v] = d[u] + G[u][v];
					c[v] = c[u] + cost[u][v];
					pre[v] = u;
				}
				else if (d[u] + G[u][v] == d[v] && c[u] + cost[u][v] < c[v]) {
					c[v] = c[u] + cost[u][v];
					pre[v] = u;
				}
			}
		}
	}
}

void printPre(int v, int st)
{
	if (v == st) {
		printf("%d ", v);
		return;
	}
	printPre(pre[v],st);
	printf("%d ", v);
	return;
}


int main()
{
	int m, st, ed;
	cin >> n >> m >> st >> ed;
	fill(G[0], G[0] + MAXV * MAXV, INF);
	//fill(cost[0], cost[0] + MAXV * MAXV, INF);
	for (int i = 0; i < m; i++) {
		int c1, c2;
		cin >> c1 >> c2;
		cin >> G[c1][c2] >> cost[c1][c2];
		G[c2][c1] = G[c1][c2];
		cost[c2][c1] = cost[c1][c2];
	}
	Dijkstra(st);
	printPre(ed, st);
	printf("%d ", d[ed]);
	printf("%d", c[ed]);
	return 0;
}