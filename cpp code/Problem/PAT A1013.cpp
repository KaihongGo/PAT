//PAT A1013.cpp 1013 Battle Over Cities (25 分)
//基本思路：并不好；通过实际删除边进行操作！！可以直接遍历的时候return！
//如果不想访问该结点；将vis[v]设为true	
//三种方法跳过(假删除)结点
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int maxv = 2010;

int G[maxv][maxv];
bool vis[maxv] = { false };

int n, m, k;//n个结点，m条路，

void DFS(int now)
{
	vis[now] = true;
	for (int i = 1; i <= n; i++)
	{//结点编号从1开始
		//G[now][i] = G[i][now] = 0;
		if (G[now][i] > 0 && vis[i] == false)
			DFS(i);//删边吗！？不需要
	}
}

int DFSTrave()
{
	int num = 0;
	for (int i = 1; i <= n; i++) {
		if (vis[i] == false) {//计算连通个数
			num++;
			DFS(i);
		}
	}
	return num;
}

vector<int> getAdj(int v)
{
	vector<int> vi;
	for (int i = 1; i <= n; i++) {
		if (G[v][i] > 0)
			vi.push_back(i);
	}
	return vi;
}

int main()
{
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++)
	{
		int v1, v2;
		cin >> v1 >> v2;
		G[v1][v2] = 1;
		G[v2][v1] = 1;
	}
	//int oriNum = DFSTrave();
	//fill(vis, vis + maxv, false);//复原vis
	int v;
	for (int i = 0; i < k; i++)
	{
		cin >> v;
		vector<int> adjv = getAdj(v);
		//for (int j = 0; j < adjv.size(); j++)
		//{//改变
			//如果不想访问该结点
		//	G[adjv[j]][v] = 0;
		//	G[v][adjv[j]] = 0;
		//}
		vis[v] = true;//
		int nowNum = DFSTrave();
		fill(vis, vis + maxv, false);//复原vis
		//for (int j = 0; j < adjv.size(); j++)
		//{//复原
		//	G[adjv[j]][v] = 1;
		//	G[v][adjv[j]] = 1;
		//}//此策略并不好；实际上并没有删除点；而是删除了边
		printf("%d\n", nowNum -1);//包含一个结点！
	}
}