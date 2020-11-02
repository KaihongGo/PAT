//PAT A1090.cpp 1090 Highest Price in Supply Chain (25 ��)
//���⣬���һ�β��������ɼ�¼һ���ɶ���Ԫ��
//BUGS:ֻͨ��һ�����Ե� *( 
//ԭ��BFS������һ����������now��
//���������Ĳ��԰���ͨ��������δͨ���������Ǵ�������

#include <cstdio>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

const int maxn = 100010;
int maxlayer = 0;

struct node
{
	int layer;	//�������Ϊ1
	vector<int> child;
} Node[maxn];

int layerOrder(int root)
{	//���������������
	int num = 0;
	queue<int> q;
	q.push(root);
	Node[root].layer = 1;
	while (!q.empty())
	{
		int front = q.front();
		q.pop();	
		//��ز���
		if (Node[front].layer > maxlayer)
		{
			num = 0;	//�����²�
			maxlayer = Node[front].layer;//����������
		}
		else if (Node[front].layer == maxlayer)
			num++;

		for (int i = 0; i < Node[front].child.size(); i++)
		{
			int child = Node[front].child[i];
			Node[child].layer = Node[front].layer + 1;//��ǲ��
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
			root = i;	//��ס�����
		else
			Node[father].child.push_back(i);
	}
	int num = layerOrder(root);
	double price = p * pow(1 + 0.01 * r, maxlayer - 1);
	printf("%.2lf %d",price, num);
}