//PAT A1004.cpp
//基本思路：层序遍历，添加层号；相关操作对同层结点进行统计；借助数组计数
//直接AC O(∩_∩)O
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;	

const int maxn = 110;
int n, m;//n个结点；m个非叶结点
struct node
{
	int layer;
	vector<int> child;
} Node[maxn];
//根结点编号1，不使用0号
int nochild[maxn] = { 0 };//层号作为下标统计无孩子结点
int layerOrder(int root)
{	//返回值；最大层数
	queue<int> q;
	q.push(root);
	Node[root].layer = 1;
	int front = 0;
	while (!q.empty())
	{
		front = q.front();
		q.pop();
		//相关操作,记录同层无孩子；存于数组
		if (Node[front].child.size() == 0)
			nochild[Node[front].layer]++;
		
		for (int i = 0; i < Node[front].child.size(); i++)
		{
			int child = Node[front].child[i];
			Node[child].layer = Node[front].layer + 1;
			q.push(child);
		}
	}
	return Node[front].layer;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int id, k;
		scanf("%d%d", &id, &k);
		for (int i = 0; i < k; i++)
		{
			int child = -1;
			scanf("%d", &child);
			Node[id].child.push_back(child);
		}
	}
	int maxlayer = layerOrder(1);
	for (int i = 1; i <= maxlayer; i++)
	{
		if (i != maxlayer)
			printf("%d ", nochild[i]);
		else printf("%d\n", nochild[i]);
	}
	return 0;
}