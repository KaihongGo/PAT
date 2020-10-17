//PAT A1102.cpp 1102 Invert a Binary Tree (25 分)
//不好！！
//常规二叉树遍历

#include <cstdio>
#include <queue>
#include <vector>
#include <cctype>
using namespace std;
const int maxn = 15;
vector<int> node[maxn];

void layerOrder(int root)
{
	queue<int> q;
	q.push(root);
	while (!q.empty())
	{
		int now = q.front();//now是树根，node[now]是孩子信息
		q.pop();
		printf("%d", now);
		for (int i = node[now].size() - 1; i >= 0; i--)
		{
			int child = node[now][i];
			q.push(child);
		}
		if (!q.empty()) printf(" ");
	}
}

void inOrder(int root)
{
	if (node[root].size() == 0)
	{	//此处return有问题
		printf("%d ", root);
		return;
	}//此处有问题！！！
	else if (node[root].size() == 2)
	{
		inOrder(node[root][1]);//右子树
		printf("%d ", root);	//根
		inOrder(node[root][0]);
	}
	else if (node[root].size() == 1)
	{
		printf("%d ", root);
		inOrder(node[root][0]);
	}	
}


int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			char a[2];
			scanf("%s", a);
			if(a[0] != '-')
			{
				node[i].push_back(a[0] - '0');
			}
		}		
	}
	//找根
	int Table[maxn] = { 0 };
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < node[i].size(); j++)
		{
			Table[node[i][j]]++;
		}
	}
	int root = 0;
	for (int i = 0; i < n; i++)
	{
		if (Table[i] == 0) root = i;
	}
	layerOrder(root);
	printf("\n");
	inOrder(root);
	return 0;

}


