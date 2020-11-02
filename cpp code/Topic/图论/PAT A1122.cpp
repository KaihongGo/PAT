//PAT A1122.cpp 1122 Hamiltonian Cycle (25 ��)
//һ�����Ե�δ����
//ԭ�����ǳ�ʼ���ڽӾ���

#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXV = 300;
const int INF = 0x3fffffff;
int G[MAXV][MAXV];
int n, m;

bool judge(vector<int> query)
{
	bool flag = true;
	//�Ƿ���ͨ
	for (int i = 0; i < query.size()-1; i++)
	{
		int id = query[i], idNext = query[i + 1];
		if (G[id][idNext] == INF)
			return false;
			//����ͨ
	}
	if (query[0] != query[query.size() - 1])
		return false;//��β��ͬ
	set<int> st;
	for (int i = 0; i < query.size(); i++)
		st.insert(query[i]);//�����ظ�Ԫ��
	if (st.size() + 1 != query.size())
		return false;
	if (query.size() - 1 != n)
		return false;//���������н��
	return flag;
}

int main()
{
	fill(G[0], G[0] + MAXV * MAXV, INF);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		G[v][u] = G[u][v] = 1;
	}
	int k;
	cin >> k;
	vector<vector<int> >query;
	query.resize(k);
	for (int i = 0; i < k; i++)
	{
		int num;
		cin >> num;
		query[i].resize(num);
		for(int j = 0;j<num;j++)
			cin >> query[i][j];
		bool flag = judge(query[i]);
		if (flag == true)
			printf("YES\n");
		else printf("NO\n");
	}
}