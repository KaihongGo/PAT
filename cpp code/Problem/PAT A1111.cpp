//PAT A1111.cpp 1111 Online Map (30 分)
//基本思路：代码冗余，采用两次Dijkstra+ DFS
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXV = 550;
const int INF = 0x3fffffff;

int G[MAXV][MAXV], Time[MAXV][MAXV], d[MAXV];
bool vis[MAXV];
int n;
vector<int> pre[MAXV];

void Dijkstra_Dis(int s)
{
	fill(d, d + MAXV, INF); d[s] = 0;
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
					pre[v].clear();
					pre[v].push_back(u);
				}
				else if (d[u] + G[u][v] == d[v]) {
					pre[v].push_back(u);
				}
			}
		}
	}
}

int t[MAXV];
void Dijkstra_Time(int s)
{
	fill(vis, vis + MAXV, false);
	fill(t, t + MAXV, INF); t[s] = 0;
	for (int i = 0; i < n; i++) {
		int u = -1, MIN = INF;
		for (int j = 0; j < n; j++) {
			if (vis[j] == false && t[j] < MIN) {
				MIN = t[j];
				u = j;
			}
		}
		if (u == -1) return;
		vis[u] = true;
		for (int v = 0; v < n; v++) {
			if (vis[v] == false && Time[u][v] != INF) {
				if (t[u] + Time[u][v] < t[v]) {
					t[v] = t[u] + Time[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}
				else if (t[u] + Time[u][v] == t[v]) {
					pre[v].push_back(u);
				}
			}
		}
	}
}

vector<int> tempPath, path;
int minTime = INF;
void DFS_Dis(int v, int st)
{	//st源头结点，逆向进行
	if (v == st) {
		tempPath.push_back(v);
		int tempTime = 0;
		for (int i = tempPath.size() - 1; i > 0; i--) {
			int id = tempPath[i], idNext = tempPath[i - 1];
			tempTime += Time[id][idNext];
		}
		if (tempTime < minTime) {
			minTime = tempTime;
			path = tempPath;
		}
		else if (tempTime == minTime && tempPath.size() < path.size())
				path= tempPath;
		tempPath.pop_back();
		return;
	}
	tempPath.push_back(v);
	for (int i = 0; i < pre[v].size(); i++)
		DFS_Dis(pre[v][i], st);
	tempPath.pop_back();
}

void DFS_Time(int v, int st)
{	//st源头结点，逆向进行
	if (v == st) {
		tempPath.push_back(v);
		if (tempPath.size() < path.size())
			path = tempPath;
		tempPath.pop_back();
		return;
	}
	tempPath.push_back(v);
	for (int i = 0; i < pre[v].size(); i++)
		DFS_Dis(pre[v][i], st);
	tempPath.pop_back();
}

int main()
{
	int m;
	cin >> n >> m;
	fill(G[0], G[0] + MAXV * MAXV, INF);
	fill(Time[0], Time[0] + MAXV * MAXV, INF);
	for (int i = 0; i < m; i++)
	{
		int v1, v2, oneWay;
		cin >> v1 >> v2 >> oneWay;
		if (oneWay == 0)
		{
			cin >> G[v1][v2] >> Time[v1][v2];
			G[v2][v1] = G[v1][v2];
			Time[v2][v1] = Time[v1][v2];
		}
		else if (oneWay == 1)
		{
			cin >> G[v1][v2] >> Time[v1][v2];
		}
	}

	int st, ed;	
	cin >> st >> ed;
	Dijkstra_Dis(st);
	DFS_Dis(ed, st);
	vector<int> pathDis = path;

	Dijkstra_Time(st);
	tempPath.clear();
	path.resize(MAXV);
	DFS_Time(ed, st);
	vector<int> pathTime = path;

	if (pathDis == pathTime) {
		printf("Distance = %d; ", d[ed]);
		printf("Time = %d: ", t[ed]);
		for (int i = pathTime.size() - 1; i > 0; i--)
			printf("%d -> ", pathTime[i]);
		printf("%d\n", pathTime[0]);
	}
	else {
		printf("Distance = %d: ", d[ed]);
		for (int i = pathDis.size() - 1; i > 0; i--)
			printf("%d -> ", pathDis[i]);
		printf("%d\n", pathDis[0]);
		printf("Time = %d: ", t[ed]);
		for (int i = pathTime.size() - 1; i > 0; i--)
			printf("%d -> ", pathTime[i]);
		printf("%d\n", pathTime[0]);

	}
	return 0;
}