//PAT A1034.cpp 1034 Head of a Gang (30 分)1034 Head of a Gang (30 分)
//全局变量默认赋值为0
//邻接矩阵存储,计算连通个数
#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

//输入处理：图存储，边权；点权; 邻接矩阵
const int maxn = 2020;
const int INF = 0x3fffffff;//很大的数，防止相加后大于int范围
int G[maxn][maxn];//邻接矩阵
int weight[maxn];//点权
//产生编号，利用map映射
map<int, string> intTostring;
map<string, int> stringToint;
map<string, int> Gang;
//必要变量
int numPerson = 0;
int n, k;
//DFS用
bool vis[maxn] = { false };	//是否已被访问

int change(string str)
{	//建立姓名与连续编号的相互映射，设置计数量
	if (stringToint.find(str) != stringToint.end())
		return stringToint[str];
	else
	{
		stringToint[str] = numPerson;
		intTostring[numPerson] = str;	//建立映射关系
		return numPerson++;//此句理解，很巧妙！
	}
}

void DFS(int now, int& head, int& numMember, int& totalValue)
{	//DFS访问单个连通块
	numMember++;//计数连通块内结点个数！学习，初值为0
	vis[now] = true;
	if (weight[now] > weight[head])
		head = now;
	//隐含递归基，遍历完所有结点自动返回
	for (int i = 0; i < numPerson; i++)
	{	//遍历所有结点，没访问，访问邻近
		if (G[now][i] > 0)
		{	//now -> i
			totalValue += G[now][i];	//边权累加
			G[now][i] = G[i][now] = 0;	//删除这条边，房子回头路
			if (vis[i] == false)//此句置后，为了解决环遍历产生的问题（已遍历结点不累计边权）
				DFS(i, head, numMember, totalValue);
		}
	}
}

void DFSTrave()
{
	for (int i = 0; i < numPerson; i++)
	{//这个遍历，为了找出所有的连通块
		if (vis[i] == false)
		{
			int head = i, numMember = 0, totalVal = 0;
			DFS(i, head, numMember, totalVal);
			if (numMember > 2 && totalVal > k)
			{
				Gang[intTostring[head]] = numMember;
			}
		}
	}
}

int main()
{
	int w;
	string str1, str2;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		cin >> str1 >> str2 >> w;
		int id1 = change(str1);//字符串转换为编号；利用map
		int id2 = change(str2);
		G[id1][id2] += w;	//边权，id1->id2
		G[id2][id1] += w;	//边权，id2->id1
		weight[id1] += w;	//点权，id1
		weight[id2] += w;	//点权，id2
	}	//输入处理，建图
	//遍历操作
	DFSTrave();
	cout << Gang.size() << endl;
	for (auto it = Gang.begin(); it != Gang.end(); it++)
		cout << it->first << " " << it->second << endl;
}
