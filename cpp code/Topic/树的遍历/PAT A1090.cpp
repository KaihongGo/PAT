//PAT A1090.cpp 1090 Highest Price in Supply Chain (25 分)
//问题，如果一次层序遍历完成记录一层由多少元素
//BUGS:只通过一个测试点 *( 
//原因：BFS函数中一个变量不是now，
//仅仅给出的测试案例通过；其余未通过；表明是代码问题

#include <cstdio>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

const int maxn = 100010;
int maxlayer = 0;

struct node
{
	int layer;	//根结点层号为1
	vector<int> child;
} Node[maxn];

int layerOrder(int root)
{	//返回最大层数结点数
	int num = 0;
	queue<int> q;
	q.push(root);
	Node[root].layer = 1;
	while (!q.empty())
	{
		int front = q.front();
		q.pop();	
		//相关操作
		if (Node[front].layer > maxlayer)
		{
			num = 0;	//进入新层
			maxlayer = Node[front].layer;//更新最大层数
		}
		else if (Node[front].layer == maxlayer)
			num++;

		for (int i = 0; i < Node[front].child.size(); i++)
		{
			int child = Node[front].child[i];
			Node[child].layer = Node[front].layer + 1;//标记层号
			q.push(child);
		}
	}
	return num;
}


int main()
{
	int n, root = 0;
	double p, r;
	scanf("%d%lf%lf", &n, &p, &r);
	for (int i = 0; i < n; i++)
	{
		int father;
		scanf("%d", &father);
		if (father == -1)
			root = i;	//记住根结点
		else
			Node[father].child.push_back(i);
	}
	int num = layerOrder(root);
	double price = p * pow(1 + 0.01 * r, maxlayer - 1);
	printf("%.2lf %d",price, num);
}