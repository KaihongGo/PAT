//PAT A1018.cpp 1018 Public Bike Management (30 分)
//注意：该题结点编号0-n
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

const int MAXV = 550;
const int INF = 0x3fffffff;
int n;//结点数
int G[MAXV][MAXV], d[MAXV];
bool vis[MAXV];
vector<int> pre[MAXV];
int Capacity;
void Dijkstra(int s)
{
	//初始化
	fill(d, d + MAXV, INF);
	d[s] = 0;
	for (int i = 0; i <= n; i++) {
		int u = -1, MIN = INF;
		for (int j = 0; j <= n; j++) {
			if (vis[j] == false && d[j] < MIN) {
				u = j;
				MIN = d[j];
			}
		}
		if (u == -1) return;
		vis[u] = true;
		for (int v = 0; v <= n; v++) {
			if (vis[v] == false && G[u][v] != INF) {
				if (d[u] + G[u][v] < d[v]) {
					d[v] = d[u] + G[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}
				else if (d[u] + G[u][v] == d[v])
					pre[v].push_back(u);
			}
		}
	}
}

vector<int> tempPath, path;
int optneed = INF, optremain = INF;
int weight[MAXV];//点权
void DFS(int v, int s)
{	//找最大点权
	if (v == s) {
		tempPath.push_back(v);
		int need = 0, remain = 0;
		for (int i = tempPath.size() - 1; i >= 0; i--) {//跳过0号
			int id = tempPath[i];
			if (weight[id] > 0)
				remain += weight[id];
			else {
				if (remain > abs(weight[id]))
					remain -= abs(weight[id]);
				else {
					need += abs(weight[id]) - remain;
					remain = 0;
				}
			}
		}
		if (need < optneed) {
			optneed = need;
			optremain = remain;
			path = tempPath;
		}
		else if (need == optneed && remain < optremain) {
			optremain = remain;
			path = tempPath;
		}
		tempPath.pop_back();
		return;
	}
	tempPath.push_back(v);
	for (int i = 0; i < pre[v].size(); i++)
		DFS(pre[v][i], s);
	tempPath.pop_back();
}

int main()
{
	fill(G[0], G[0] + MAXV * MAXV, INF);
	int ed, m;
	cin >> Capacity >> n >> ed >> m;
	for (int i = 1; i <= n; i++) {
		cin >> weight[i];//点权输入
		weight[i]  -= (Capacity / 2);//-表示需要补给
	}
	for (int i = 0; i < m; i++) {//边权输入，临界矩阵，无向图
		int u, v;
		cin >> u >> v;
		cin >> G[u][v];
		G[v][u] = G[u][v];
	}
	Dijkstra(0);
	DFS(ed, 0);
	cout << optneed << " ";
	cout << path[path.size() - 1];
	for (int i = path.size() - 2; i >= 0; i--)
		cout << "->" << path[i] ;
	cout << " " << optremain;
	return 0;
}