//PAT A1114.cpp 1114 Family Property (25 分)
//

#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
const int maxn = 10010;

struct node
{
	int sets = 0;
	int area = 0;
	int father;
} person[maxn];

struct ansNode
{
	int root = 0;
	int id;
	int m;
	int sets;
	int area;
} ans[maxn];
int findFather(int x)
{
	int a = x;
	while (x != person[x].father)
		x = person[x].father;
	while (a != person[a].father)
	{
		int z = a;
		a = person[a].father;
		person[z].father = x;
	}
	return x;
}

void Union(int a, int b)
{
	int faA = findFather(a);
	int faB = findFather(b);
	if (faA != faB)
	{
		person[faB].father = faA;
	}
}

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	set<int> allID;//存储输入的所有成员，遍历基础	
	int n;
	scanf("%d", &n);
	for (int i = 0; i <= maxn; i++)
		person[i].father = i;
	//初始化并查集;初始化有问题；下标不从1开始并连续；？
	//需解决映射问题，将成员仍映射为？？
	int id[maxn] = { 0 };
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &id[i]);
		allID.insert(id[i]);
		int dad, mom;
		scanf("%d %d", &dad, &mom);
		if (dad != -1)
		{
			allID.insert(dad);
			Union(id[i], dad);
		}
		if (mom != -1)
		{
			allID.insert(mom);
			Union(id[i], mom);
		}
		int k;
		scanf("%d", &k);
		for (int j = 0; j < k; j++)
		{//输入孩子，k==0；自动不执行
			int child;
			scanf("%d", &child);
			allID.insert(child);
			Union(id[i], child);
		}
		//房地产信息均赋给root；后统计root内信息
		/*
		int root = findFather(id);
		int sets, area;
		scanf("%d %d", &sets, &area);
		person[root].area = area;//root信息累加
		person[root].sets = sets;//事实上，root并未固定，此句无意义
		*/
		scanf("%d %d", &person[id[i]].sets, &person[id[i]].area);
		//策略，仍暂存在id中，最后统计id信息
	}
	
	//信息统计
	int isRoot[maxn] = { 0 };
	for (auto it = allID.begin();it!= allID.end();it++)
	{	//此处有问题!
		isRoot[findFather(*it)]++;
	}

	int j = 0;
	for (int i = 0; i < maxn; i++)
	{
		if (isRoot[i] != 0)
		{
			ans[j].root = i;	//找到根
			j++;
		}
	}
	for (int i = 1; i <= n; i++)
	{	//统计set
		int father = findFather(id[i]);
		person[father].area += person[id[i]].area;
		person[father].sets += person[id[i]].sets;
	}
	//sort(isRoot, isRoot + maxn, cmp);
	return 0;
}