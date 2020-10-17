//PAT A1106.cpp  1106 Lowest Price in Supply Chain (25 ��)
//һ�����Ե�δͨ��

#include <queue>
#include <vector>
#include <cmath>
#include <cstdio>
using namespace std;

const int maxn = 100010;
struct node
{
	int layer;
	vector<int> child;
}Node[maxn];

int num[maxn] = { 0 };//�����ã��±�Ϊ������ֵΪ�ò�Ҷ�ӽ����
void layerOrder(int root)
{
	queue<int> q;
	q.push(root);
	Node[root].layer = 1;//root����Ϊ1
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		//��ز���
		if(Node[now].child.size()==0)
			num[Node[now].layer]++;	//�޺��ӣ�Ҷ���

		for (int i = 0; i < Node[now].child.size(); i++)
		{
			int child = Node[now].child[i];
			Node[child].layer = Node[now].layer + 1;
			q.push(child);
		}
	}
}

int main()
{
	int n; double p, r;
	scanf("%d %lf %lf", &n, &p, &r);
	for (int i = 0; i < n; i++)
	{
		int k;
		scanf("%d", &k);
		for (int j = 0; j < k; j++)
		{
			int child;
			scanf("%d", &child);
			Node[i].child.push_back(child);
		}
	}
	layerOrder(0);
	int lowlayer = maxn;
	for (int i = 1; i <= n; i++)
	{	//num���飬������Ϣ����ʼ��һ��
		if (num[i] != 0)
		{
			lowlayer = i;
			break;
		}
	}
	printf("%.4f %d",p * pow(1+0.01*r,lowlayer-1), num[lowlayer]);
	return 0;
}