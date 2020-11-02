//PAT A1072.cpp 1072 Gas Station (30 分)
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

const int MAXV = 1050;
const int INF = 0x3fffffff;

int G[MAXV][MAXV];
int d[MAXV];
bool vis[MAXV] = { false };
int n, m;
int N;	//总结点个数编号1开始 n+m

void Dijkstra(int s)
{	//s为源结点
	fill(vis, vis + MAXV, false);
	fill(d, d + MAXV, INF); d[s] = 0;
	for (int i = 1; i <= N; i++) {
		int u = -1, MIN = INF;
		for (int j = 1; j <= N; j++) {
			if (vis[j] == false && d[j] < MIN) {
				MIN = d[j];
				u = j;
			}
		}
		if (u == -1) return;
		vis[u] = true;
		for (int v = 1; v <= N; v++) {
			if (vis[v] == false && G[u][v] != INF && d[u] + G[u][v] < d[v]) {
				d[v] = d[u] + G[u][v];
			}
		}
	}
}

int change(string str)
{
	int id = 0;
	if (str[0] == 'G') {
		str.erase(str.begin());
		id = n+ stoi(str);
	}
	else
		id = stoi(str);
	return id;
}

struct Station
{
	int index;
	double minDist;
	double averageDist;
	double maxDist;
};

bool cmp(Station a, Station b)
{
	if (a.minDist != b.minDist)
		return a.minDist > b.minDist;
	else if (a.averageDist != b.averageDist)
		return a.averageDist < b.averageDist;
	else
		return a.index < b.index;
}

int main()
{
	cin >> n >> m;
	N = n + m;
	fill(G[0], G[0] + MAXV * MAXV, INF);
	int k, Ds;
	cin >> k >> Ds;
	string p1, p2;
	int dist;
	for (int i = 0; i < k; i++) {
		cin >> p1 >> p2;
		int u, v;
		u = change(p1);
		v = change(p2);
		cin >> G[u][v];
		G[v][u] = G[u][v];
	}
	vector<Station> vi;
	for (int i = 1; i <= m; i++) {
		Dijkstra(n + i);
		int sumDist = 0;
		int minDist = INF;
		int maxDist = 0;
		for (int j = 1; j <= n; j++) {//距离数组中房屋
			if (d[j] < minDist)
				minDist = d[j];
			if (d[j] > maxDist)
				maxDist = d[j];
			sumDist += d[j];
		}
		double averageDist = (double)sumDist / n;
		vi.push_back({ i, (double)minDist,averageDist ,(double)maxDist});
	}
	sort(vi.begin(), vi.end(), cmp);
	//合法标记
	int index = -1;
	for (int i = 0; i < vi.size(); i++) {
		if (vi[i].maxDist <= Ds) {
			index = i;
			break;
		}
	}
	if (index == -1)
		printf("No Solution\n");
	else {
		printf("G%d\n", vi[index].index);
		printf("%.1f %.1f\n", vi[index].minDist, vi[index].averageDist);
	}
	return 0;
}

