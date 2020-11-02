//PAT A1076.cpp 1076 Forwards on Weibo (30 ��)
//
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Node
{
	int v;
	int level;
};

const int maxn = 1010;
vector<vector<int> > G;
int inq[maxn];

int BFS(int v, int L)
{	//L��������
	int numForward = 0;
	queue<Node> q;
	q.push({ v,0 });
	inq[v] = true;
	while (!q.empty())
	{
		Node now = q.front();
		q.pop();
		int u = now.v;
		for (int i = 0; i < G[u].size(); i++)
		{
			Node next;
			next.v = G[u][i];
			next.level = now.level + 1;//�˴�Ӧ���ڽӽ����ƣ�
			//��ͬ���v �����洢�Ĳ������ܲ�ͬ
			if (inq[next.v] == false && next.level <= L)
			{	//next
				q.push(next);
				inq[next.v] = true;
				numForward++;
			}
		}
	}
	return numForward;
}

int main()
{
	int n, l;
	cin >> n >> l;
	G.resize(n+1);//���1��ʼ 
	for (int i = 1; i <= n; i++)
	{
		int k, id;
		cin >> k;
		for (int j = 0; j < k; j++)
		{
			cin >> id;
			G[id].push_back(i);
		}
	}
	int numQurey, v;
	cin >> numQurey;
	for (int i = 0; i < numQurey; i++)
	{
		fill(inq, inq + maxn, false);
		cin >> v;
		int numForward = BFS(v, l);
		cout << numForward << endl;
	}

	return 0;
}