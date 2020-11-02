//PAT A1114.cpp 1114 Family Property (25 ��)
//

#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
const int maxn = 10010;

struct node
{
	int sets = 0;
	int area = 0;
	int father;
} person[maxn];

struct ansNode
{
	int root = 0;
	int id;
	int m;
	int sets;
	int area;
} ans[maxn];
int findFather(int x)
{
	int a = x;
	while (x != person[x].father)
		x = person[x].father;
	while (a != person[a].father)
	{
		int z = a;
		a = person[a].father;
		person[z].father = x;
	}
	return x;
}

void Union(int a, int b)
{
	int faA = findFather(a);
	int faB = findFather(b);
	if (faA != faB)
	{
		person[faB].father = faA;
	}
}

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	set<int> allID;//�洢��������г�Ա����������	
	int n;
	scanf("%d", &n);
	for (int i = 0; i <= maxn; i++)
		person[i].father = i;
	//��ʼ�����鼯;��ʼ�������⣻�±겻��1��ʼ����������
	//����ӳ�����⣬����Ա��ӳ��Ϊ����
	int id[maxn] = { 0 };
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &id[i]);
		allID.insert(id[i]);
		int dad, mom;
		scanf("%d %d", &dad, &mom);
		if (dad != -1)
		{
			allID.insert(dad);
			Union(id[i], dad);
		}
		if (mom != -1)
		{
			allID.insert(mom);
			Union(id[i], mom);
		}
		int k;
		scanf("%d", &k);
		for (int j = 0; j < k; j++)
		{//���뺢�ӣ�k==0���Զ���ִ��
			int child;
			scanf("%d", &child);
			allID.insert(child);
			Union(id[i], child);
		}
		//���ز���Ϣ������root����ͳ��root����Ϣ
		/*
		int root = findFather(id);
		int sets, area;
		scanf("%d %d", &sets, &area);
		person[root].area = area;//root��Ϣ�ۼ�
		person[root].sets = sets;//��ʵ�ϣ�root��δ�̶����˾�������
		*/
		scanf("%d %d", &person[id[i]].sets, &person[id[i]].area);
		//���ԣ����ݴ���id�У����ͳ��id��Ϣ
	}
	
	//��Ϣͳ��
	int isRoot[maxn] = { 0 };
	for (auto it = allID.begin();it!= allID.end();it++)
	{	//�˴�������!
		isRoot[findFather(*it)]++;
	}

	int j = 0;
	for (int i = 0; i < maxn; i++)
	{
		if (isRoot[i] != 0)
		{
			ans[j].root = i;	//�ҵ���
			j++;
		}
	}
	for (int i = 1; i <= n; i++)
	{	//ͳ��set
		int father = findFather(id[i]);
		person[father].area += person[id[i]].area;
		person[father].sets += person[id[i]].sets;
	}
	//sort(isRoot, isRoot + maxn, cmp);
	return 0;
}