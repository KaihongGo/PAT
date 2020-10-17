//PAT A1079.cpp 1079 Total Sales of Supply Chain (25 ��)
//vector ��һ�����ƣ�Ԫ��Ĭ��ȫ��ֵ0
//BUGS: double ��������scanf()��%lf;���%f�����˾Ͳ��У�����bug
//����˼·�����ò����������ͳ��Ҷ�ӽ����ȣ���ֵ�������أ�sale�ۼ����ۼ�
#include <queue>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
const int maxn = 100010;
struct node
{
	double product;
	int layer;//��¼retailer��ȣ�Ҷ�ӽ��
	vector<int> child;
}Node[maxn];

int n;
double p, r;
double sale = 0;	//�ܼ�ֵ���ۼ�
void layerOrder(int root)
{
	queue<int> q;
	q.push(root);
	Node[root].layer = 0;//layer��0��ʼ
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		
		//��ز���
		if (Node[now].child.size() == 0)
		{	//�޺��ӣ��ڼ��㣻���۳��۸�(1+r)^���*p
			sale += p * pow((1 + 0.01 * r), Node[now].layer) * Node[now].product;
		}

		for (int i = 0; i < Node[now].child.size(); i++)
		{
			int child = Node[now].child[i];
			Node[child].layer = Node[now].layer + 1;
			//��¼����
			q.push(child);
		}
	}
}

int main()
{
	scanf("%d%lf%lf", &n, &p, &r);
	for (int i = 0; i < n; i++)
	{
		int k = 0;
		scanf("%d", &k);
		if (k != 0)
		{
			for (int j = 0; j < k; j++)
			{
				int child;
				scanf("%d", &child);
				Node[i].child.push_back(child);
			}
		}
		else //k==0����¼��Ʒ��,Ҷ�ӽ�㣬�޺���
		{
			double product;
			scanf("%lf", &product);
			Node[i].product = product;
		}
	}
	layerOrder(0);	//�������0
	printf("%.1f", sale);
}

