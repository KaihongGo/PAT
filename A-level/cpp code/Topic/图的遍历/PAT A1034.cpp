//PAT A1034.cpp 1034 Head of a Gang (30 ��)1034 Head of a Gang (30 ��)
//ȫ�ֱ���Ĭ�ϸ�ֵΪ0
//�ڽӾ���洢,������ͨ����
#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

//���봦��ͼ�洢����Ȩ����Ȩ; �ڽӾ���
const int maxn = 2020;
const int INF = 0x3fffffff;//�ܴ��������ֹ��Ӻ����int��Χ
int G[maxn][maxn];//�ڽӾ���
int weight[maxn];//��Ȩ
//������ţ�����mapӳ��
map<int, string> intTostring;
map<string, int> stringToint;
map<string, int> Gang;
//��Ҫ����
int numPerson = 0;
int n, k;
//DFS��
bool vis[maxn] = { false };	//�Ƿ��ѱ�����

int change(string str)
{	//����������������ŵ��໥ӳ�䣬���ü�����
	if (stringToint.find(str) != stringToint.end())
		return stringToint[str];
	else
	{
		stringToint[str] = numPerson;
		intTostring[numPerson] = str;	//����ӳ���ϵ
		return numPerson++;//�˾���⣬�����
	}
}

void DFS(int now, int& head, int& numMember, int& totalValue)
{	//DFS���ʵ�����ͨ��
	numMember++;//������ͨ���ڽ�������ѧϰ����ֵΪ0
	vis[now] = true;
	if (weight[now] > weight[head])
		head = now;
	//�����ݹ�������������н���Զ�����
	for (int i = 0; i < numPerson; i++)
	{	//�������н�㣬û���ʣ������ڽ�
		if (G[now][i] > 0)
		{	//now -> i
			totalValue += G[now][i];	//��Ȩ�ۼ�
			G[now][i] = G[i][now] = 0;	//ɾ�������ߣ����ӻ�ͷ·
			if (vis[i] == false)//�˾��ú�Ϊ�˽�����������������⣨�ѱ�����㲻�ۼƱ�Ȩ��
				DFS(i, head, numMember, totalValue);
		}
	}
}

void DFSTrave()
{
	for (int i = 0; i < numPerson; i++)
	{//���������Ϊ���ҳ����е���ͨ��
		if (vis[i] == false)
		{
			int head = i, numMember = 0, totalVal = 0;
			DFS(i, head, numMember, totalVal);
			if (numMember > 2 && totalVal > k)
			{
				Gang[intTostring[head]] = numMember;
			}
		}
	}
}

int main()
{
	int w;
	string str1, str2;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		cin >> str1 >> str2 >> w;
		int id1 = change(str1);//�ַ���ת��Ϊ��ţ�����map
		int id2 = change(str2);
		G[id1][id2] += w;	//��Ȩ��id1->id2
		G[id2][id1] += w;	//��Ȩ��id2->id1
		weight[id1] += w;	//��Ȩ��id1
		weight[id2] += w;	//��Ȩ��id2
	}	//���봦����ͼ
	//��������
	DFSTrave();
	cout << Gang.size() << endl;
	for (auto it = Gang.begin(); it != Gang.end(); it++)
		cout << it->first << " " << it->second << endl;
}
