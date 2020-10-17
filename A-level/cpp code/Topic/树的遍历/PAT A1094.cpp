//PAT A1094.cpp 1094 The Largest Generation (25 ��)
//BUGS��ͨ���������Ե�; 
//����������hashTableͳ�ƣ����������±������ͬ��
//����˼·���򵥵Ĳ����������ز���

#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

const int maxn = 110;
int num[maxn] = { 0 };

struct node
{
	int layer;
	vector<int> child;
} Node[maxn];

void layerOrder(int root)
{
	queue<int> q;
	q.push(root);
	Node[root].layer = 1;
	while (!q.empty())
	{
		int front = q.front();
		q.pop();
		//��ز���
		num[Node[front].layer]++;

		for (int i = 0; i < Node[front].child.size(); i++)
		{
			int child = Node[front].child[i];
			Node[child].layer = Node[front].layer + 1;
			q.push(child);
		}
	}
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int root, k;
		scanf("%d%d", &root, &k);
		for (int j = 0; j < k; j++)
		{
			int child;
			scanf("%d", &child);
			Node[root].child.push_back(child);
		}
	}

	layerOrder(01);
	int maxnum = 0, level = 0;
	for (int i = 0; i < maxn; i++)
	{
		if (maxnum < num[i])
		{
			maxnum = num[i];
			level = i;
		}
	}

	printf("%d %d", maxnum, level);
}