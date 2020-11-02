//PAT A1131.cpp 1131 Subway Map (30 分)
//忘记写return，循环重复使用i
//一个测试点未通过！具体原因未知
//原因：得到换乘站的代码问题
//具体原因；换乘站理解错误，我理解为多条线路交叉站为换乘站，实际上此站可以不换乘
//实际：此站前后乘坐线路不同才为换乘站
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
const int MAXV = 10010;

bool vis[MAXV];
int transNum = 0;
map<int, map<int, int> > station;
//station[u][v] u->v(相邻)间几号线路

int getTransfer(vector<int> path)
{
	int cnt = 0;
	int preLine = station[path[0]][path[1]];
	for (int i = 2; i < path.size(); i++)
	{
		int nowLine = station[path[i - 1]][path[i]];
		if (preLine != nowLine)
		{
			cnt++;
			preLine = nowLine;
		}
	}
	return cnt;
}

void DFS(int start, int end, vector<int>& tempPath, vector<int>& path)
{
	if (start == end)
	{	//触及边界，更新
		int tempNum = getTransfer(tempPath);
		if (path.size() == 0 || tempPath.size() < path.size()
			|| (tempPath.size() == path.size() && tempNum < transNum))
		{
			path = tempPath;
			transNum = tempNum;
		}//更新
		return;//绝对不要忘记RETURN
	}
	for (auto it = station[start].begin(); it != station[start].end(); it++)
	{	//遍历所有邻接点
		int next = it->first;
		if (!vis[next])
		{	//下一个结点角度
			vis[next] = true;//防止回头路
			tempPath.push_back(next);//走
			DFS(next, end, tempPath, path);
			tempPath.pop_back();//复原
			vis[next] = false;
		}
	}
}

int main()
{
	int n; cin >> n;
	for (int line = 1; line <= n; line++)
	{
		int m; cin >> m;
		int u; cin >> u;
		for (int i = 1; i < m; i++)
		{
			int v; cin >> v;
			station[u][v] = line;
			station[v][u] = line;
			u = v;//向前走
		}
	}
	int k; cin >> k;
	while (k--)
	{
		int start, end;
		cin >> start >> end;
		transNum = 0;
		vector<int> path, tempPath;
		tempPath.push_back(start);
		fill(vis, vis + MAXV, false);
		DFS(start, end, tempPath, path);

		printf("%d\n", path.size() - 1);
		int preLine = station[path[0]][path[1]], preTransfer = start;
		for (int i = 2; i < path.size(); i++)
		{
			int nowLine = station[path[i - 1]][path[i]];
			if (nowLine != preLine)
			{
				printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, path[i - 1]);
				preLine = nowLine;
				preTransfer = path[i - 1];
			}
		}
		printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, end);
	}
	return 0;
}