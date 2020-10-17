//PAT A1087.cpp 1087 All Roads Lead to Rome (30 分)
//常规思路：

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

const int MAXV = 300;
const int INF = 0x3fffffff;

int G[MAXV][MAXV];
int c[MAXV]; //cost相当于d[]
bool vis[MAXV] = { false };
int n; //结点数，编号由0-n-1
vector<int> pre[MAXV];

void Dijkstra(int s)
{	//s源头结点
	fill(c, c + MAXV, INF); c[s] = 0;
	for (int i = 0; i < n; i++) {
		int u = -1, MIN = INF;
		for (int j = 0; j < n; j++) {
			if (vis[j] == false && c[j] < MIN) {
				MIN = c[j];
				u = j;
			}
		}
		if (u == -1) return;
		vis[u] = true;
		for (int v = 0; v < n; v++) {
			if (vis[v] == false && G[u][v] != INF) {
				if (c[u] + G[u][v] < c[v]) {
					c[v] = c[u] + G[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}
				else if (c[u] + G[u][v] == c[v])
					pre[v].push_back(u);
			}
		}
	}
}

vector<int> tempPath, path;
int happines[MAXV];
int maxHap = 0, averageHap = 0;
int numPath = 0;
void DFS(int v, int st)
{	//v当前结点，st源头
	if (v == st) {
		numPath++;
		tempPath.push_back(v);
		int tempHap = 0;
		for (int i = tempPath.size()-1; i >= 0; i--) {
			int id = tempPath[i];
			tempHap += happines[id];
		}
		if (tempHap > maxHap) {
			maxHap = tempHap;
			path = tempPath;
			averageHap = maxHap / (path.size()-1);
		}
		else if (tempHap == maxHap) {
			int tempAverage = tempHap / (tempPath.size()-1);
			if (tempAverage > averageHap) {
				maxHap = tempHap;
				path = tempPath;
				averageHap = maxHap / (path.size() - 1);
			}
		}
		tempPath.pop_back();
		return;
	}
	tempPath.push_back(v);
	for (int i = 0; i < pre[v].size(); i++)
		DFS(pre[v][i], st);
	tempPath.pop_back();
}

int num = 0;	//计数用
map<string, int> stringToint;
map<int, string> intTostring;
int change(string str)
{
	stringToint[str] = num;
	intTostring[num] = str;
	return num++;
}

int main()
{
	fill(G[0], G[0] + MAXV * MAXV, INF);
	int m;
	string st;
	cin >> n >> m >> st;
	change(st);
	for (int i = 1; i < n; i++) {
		string c1; cin >> c1;
		change(c1);
		cin >> happines[stringToint[c1]];
	}
	for (int i = 0; i < m; i++) {
		string c1, c2;
		cin >> c1 >> c2;
		int u = stringToint[c1];
		int v = stringToint[c2];
		cin >> G[u][v];
		G[v][u] = G[u][v];
	}
	Dijkstra(stringToint[st]);
	DFS(stringToint["ROM"], stringToint[st]);
	cout << numPath<<" "<< c[stringToint["ROM"]]<<" " << maxHap <<" " <<averageHap << endl;
	for (int i = path.size() - 1; i > 0; i--)
		cout << intTostring[path[i]] << "->";
	cout << intTostring[path[0]];
	return 0;
}