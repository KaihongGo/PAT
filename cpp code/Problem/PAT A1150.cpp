//PAT A1150.cpp 1150 Travelling Salesman Problem (25 分)
//仔细审题！！切记
//缺少了一个判断逻辑，必要时可以画图
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

const int MAXV = 300;
const int INF = 0x3fffffff;
int G[MAXV][MAXV];
int n;

int Travel(vector<int> path)
{
	int pre = path[0], dist = 0;
	for (int i = 1; i < path.size(); i++)
	{
		int now = path[i];
		if (G[pre][now] != INF)
			dist += G[pre][now];
		else return -1;//无路可走
		pre = now;
	}
	return dist;
}

int main()
{
	vector<vector<int> > path;
	fill(G[0], G[0] + MAXV * MAXV, INF);
	int m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int c1, c2;
		cin >> c1 >> c2;
		cin >> G[c1][c2];
		G[c2][c1] = G[c1][c2];
	}
	int k; cin >> k;//k条路径
	path.resize(k);
	for (int i = 0; i < k; i++)
	{
		int num;//结点数	
		cin >> num;
		path[i].resize(num);
		for (int j = 0; j < num; j++)
			cin >> path[i][j];
	}
	int mindist = INF, index = 0;
	for (int i = 0; i < k; i++)
	{
		set<int> st;
		for (auto it = path[i].begin(); it != path[i].end(); it++)
			st.insert(*it);
			
		int dist = Travel(path[i]);
		printf("Path %d: ", i + 1);

		if (dist != -1)
			printf("%d ", dist);
		else printf("NA ");

		if (path[i][0] == path[i][path[i].size() - 1] && dist != -1)
		{
			if (path[i].size() - 1 < n || st.size() != n)
				printf("(Not a TS cycle)\n");
			else
			{
				if (path[i].size() - 1 == n)
					printf("(TS simple cycle)\n");
				else
					printf("(TS cycle)\n");
				if (dist < mindist && dist != -1)
				{
					mindist = dist;
					index = i + 1;
				}
			}
		}
		else
			printf("(Not a TS cycle)\n");
	}
	printf("Shortest Dist(%d) = %d", index, mindist);
}