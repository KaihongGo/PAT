//PAT A1018.cpp 1018 Public Bike Management (30 ��)
//ע�⣺��������0-n
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

const int MAXV = 550;
const int INF = 0x3fffffff;
int n;//�����
int G[MAXV][MAXV], d[MAXV];
bool vis[MAXV];
vector<int> pre[MAXV];
int Capacity;
void Dijkstra(int s)
{
	//��ʼ��
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
int weight[MAXV];//��Ȩ
void DFS(int v, int s)
{	//������Ȩ
	if (v == s) {
		tempPath.push_back(v);
		int need = 0, remain = 0;
		for (int i = tempPath.size() - 1; i >= 0; i--) {//����0��
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
		cin >> weight[i];//��Ȩ����
		weight[i]  -= (Capacity / 2);//-��ʾ��Ҫ����
	}
	for (int i = 0; i < m; i++) {//��Ȩ���룬�ٽ��������ͼ
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