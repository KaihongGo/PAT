//PAT A1053.cpp 1053 Path of Equal Weight (30 ��)
//BUGS��δ�������Ҫ�����ⲻ���棬���Ҷ��㣻����Ҫ�ж��Ƿ�ΪҶ���·��
//BUGS����ͨ�����������ݽ��д���ʹ���������Ҫ��
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 110;
int N, M, S;	//������������������ĺ�
vector<int> path;	//��¼·��

struct node
{
	int weight;
	vector<int> child;
} Node[maxn];

bool cmp(int a, int b)
{	//���������ݽ��г�ȥ����Ȩ������
	return Node[a].weight > Node[b].weight;
}

void DFS(int root, int sum)
{	//��ǰ���ʽ��δindex, numNodeΪ��ǰ·��path�ϵĽ�����
	//sumΪ��ǰ���ͣ��Ľ�Ϊÿ�εݹ鴫�ݲ�����������������ȡ�����Ч��
	if (sum == S)
	{	//�����߽�
		if (Node[root].child.size() != 0) return;	//����Ҷ�ӽ�㣬return�����ǣ�������
		for (int i = 0; i < path.size(); i++)
		{
			if (i != path.size() - 1) printf("%d ", Node[path[i]].weight);
			else printf("%d\n", Node[path[i]].weight);
		}
		return;
	}
	if (sum > S) return; //����ͬ
	for (int i = 0; i < Node[root].child.size(); i++)
	{	//ö�������ӽ��
		int child = Node[root].child[i];
		path.push_back(child);//��
		DFS(child,sum+Node[child].weight);
		path.pop_back();	//��Ҫ��ԭ����
	}
}

int main()
{	
	scanf("%d %d %d", &N, &M, &S);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &Node[i].weight);
	}
	for (int i = 0; i < M; i++)
	{
		int root, k;
		scanf("%d %d", &root, &k);
		for (int j = 0; j < k; j++)
		{	
			int child = 0;
			scanf("%d", &child);
			Node[root].child.push_back(child);
		}
		sort(Node[root].child.begin(), Node[root].child.end(), cmp);
	}
	path.push_back(0);	//�׽����У���ʼԪ��
	DFS(0,Node[0].weight);
	return 0;
}
