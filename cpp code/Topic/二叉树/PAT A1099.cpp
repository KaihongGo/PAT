//1099 Build A Binary Search Tree (30 分)
//BUGS:两个测试点未通过；并不需要先序建树；输入就是树！！！！！！
//利用填格子法
/*
9
1 6
2 3
-1 -1
-1 4
5 -1
-1 -1
7 -1
-1 8
-1 -1
73 45 11 58 82 25 67 38 42
*/

#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;
const int maxn = 110;
struct node
{
	int data;
	int lchild;
	int rchild;
} Node[maxn];

int in[maxn];//中序序列
void inOrder(int root, int& index)
{
	if (root == -1)	return;
	inOrder(Node[root].lchild, index);
	Node[root].data = in[index++];
	inOrder(Node[root].rchild, index);
}

void layerorder(int root)
{
	queue<int> q;
	q.push(root);
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		printf("%d", Node[now].data);
		if (Node[now].lchild != -1) q.push(Node[now].lchild);
		if (Node[now].rchild != -1) q.push(Node[now].rchild);
		if (!q.empty()) printf(" ");		
	}
}

int main()
{
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &Node[i].lchild, &Node[i].rchild);
	for (int i = 0; i < n; i++)
		scanf("%d", &in[i]);
	sort(in, in + n);	//由小到大排序，即为中序序列
	int index = 0;
	inOrder(0, index);
	layerorder(0);
	return 0;
}
