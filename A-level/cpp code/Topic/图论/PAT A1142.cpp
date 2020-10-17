//PAT A1142.cpp 1142 Maximal Clique (25 ��)
//�������,���ֶδ��󣡣�
//����Խ�磬����û���ǵ���ʼ������±�Ŷ
//��������ʱ���ˣ�����ֵ�ˣ���������Խ��
#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

const int MAXV = 300;
const int INF = 0x3fffffff;

set<int> Adj[MAXV];
int showNum[MAXV] = { 0 };//�����ڽӵ���д���
int nv, ne;

bool judge(vector<int> query)
{
	int flag = true;
	for (int i = 0; i < query.size(); i++)
	{	//�����Ƚ�
		for (int j = i + 1; j < query.size(); j++)
		{
			int u = query[i], v = query[j];
			if (Adj[u].find(v) == Adj[u].end())
			{	//������
				flag = false;
				break;
			}
		}
	}
	return flag;
}

int main()
{
	cin >> nv >> ne;
	for (int i = 0; i < ne; i++)
	{
		int u, v;
		cin >> u >> v;
		Adj[u].insert(v);
		Adj[v].insert(u);
	}
	int m, k;
	cin >> m;
	while (m--)
	{
		cin >> k;	//k����
		vector<int> query;
		query.resize(k);
		fill(showNum, showNum + nv + 7, 0);	//��ԭ
		for (int i = 0; i < k; i++)
		{
			cin >> query[i];
			int u = query[i];
			for (auto it = Adj[u].begin(); it != Adj[u].end(); it++)
			{	//�ý�������ڽӵ�
				int v = *it;
				showNum[v]++;	//���ִ���++
			}
		
		}
		bool flagOther = false;
		for (int i = 1; i <= nv; i++)
		{	//�ж��Ƿ��������ڽӵ�
			if (showNum[i] == k)
				flagOther = true;
		}

		bool flag = judge(query);
		if (flag == true)
		{
			if (flagOther == true)
				printf("Not Maximal\n");
			else 
				printf("Yes\n");
		}
		else
			printf("Not a Clique\n");
	}
}

