//PAT A1004.cpp
//����˼·�������������Ӳ�ţ���ز�����ͬ�������ͳ�ƣ������������
//ֱ��AC O(��_��)O
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;	

const int maxn = 110;
int n, m;//n����㣻m����Ҷ���
struct node
{
	int layer;
	vector<int> child;
} Node[maxn];
//�������1����ʹ��0��
int nochild[maxn] = { 0 };//�����Ϊ�±�ͳ���޺��ӽ��
int layerOrder(int root)
{	//����ֵ��������
	queue<int> q;
	q.push(root);
	Node[root].layer = 1;
	int front = 0;
	while (!q.empty())
	{
		front = q.front();
		q.pop();
		//��ز���,��¼ͬ���޺��ӣ���������
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