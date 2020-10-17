//PAT A1013.cpp 1013 Battle Over Cities (25 ��)
//����˼·�������ã�ͨ��ʵ��ɾ���߽��в�����������ֱ�ӱ�����ʱ��return��
//���������ʸý�㣻��vis[v]��Ϊtrue	
//���ַ�������(��ɾ��)���
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int maxv = 2010;

int G[maxv][maxv];
bool vis[maxv] = { false };

int n, m, k;//n����㣬m��·��

void DFS(int now)
{
	vis[now] = true;
	for (int i = 1; i <= n; i++)
	{//����Ŵ�1��ʼ
		//G[now][i] = G[i][now] = 0;
		if (G[now][i] > 0 && vis[i] == false)
			DFS(i);//ɾ���𣡣�����Ҫ
	}
}

int DFSTrave()
{
	int num = 0;
	for (int i = 1; i <= n; i++) {
		if (vis[i] == false) {//������ͨ����
			num++;
			DFS(i);
		}
	}
	return num;
}

vector<int> getAdj(int v)
{
	vector<int> vi;
	for (int i = 1; i <= n; i++) {
		if (G[v][i] > 0)
			vi.push_back(i);
	}
	return vi;
}

int main()
{
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++)
	{
		int v1, v2;
		cin >> v1 >> v2;
		G[v1][v2] = 1;
		G[v2][v1] = 1;
	}
	//int oriNum = DFSTrave();
	//fill(vis, vis + maxv, false);//��ԭvis
	int v;
	for (int i = 0; i < k; i++)
	{
		cin >> v;
		vector<int> adjv = getAdj(v);
		//for (int j = 0; j < adjv.size(); j++)
		//{//�ı�
			//���������ʸý��
		//	G[adjv[j]][v] = 0;
		//	G[v][adjv[j]] = 0;
		//}
		vis[v] = true;//
		int nowNum = DFSTrave();
		fill(vis, vis + maxv, false);//��ԭvis
		//for (int j = 0; j < adjv.size(); j++)
		//{//��ԭ
		//	G[adjv[j]][v] = 1;
		//	G[v][adjv[j]] = 1;
		//}//�˲��Բ����ã�ʵ���ϲ�û��ɾ���㣻����ɾ���˱�
		printf("%d\n", nowNum -1);//����һ����㣡
	}
}