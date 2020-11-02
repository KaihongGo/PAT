//PAT A1131.cpp 1131 Subway Map (30 ��)
//����дreturn��ѭ���ظ�ʹ��i
//һ�����Ե�δͨ��������ԭ��δ֪
//ԭ�򣺵õ�����վ�Ĵ�������
//����ԭ�򣻻���վ�����������Ϊ������·����վΪ����վ��ʵ���ϴ�վ���Բ�����
//ʵ�ʣ���վǰ�������·��ͬ��Ϊ����վ
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
const int MAXV = 10010;

bool vis[MAXV];
int transNum = 0;
map<int, map<int, int> > station;
//station[u][v] u->v(����)�伸����·

int getTransfer(vector<int> path)
{
	int cnt = 0;
	int preLine = station[path[0]][path[1]];
	for (int i = 2; i < path.size(); i++)
	{
		int nowLine = station[path[i - 1]][path[i]];
		if (preLine != nowLine)
		{
			cnt++;
			preLine = nowLine;
		}
	}
	return cnt;
}

void DFS(int start, int end, vector<int>& tempPath, vector<int>& path)
{
	if (start == end)
	{	//�����߽磬����
		int tempNum = getTransfer(tempPath);
		if (path.size() == 0 || tempPath.size() < path.size()
			|| (tempPath.size() == path.size() && tempNum < transNum))
		{
			path = tempPath;
			transNum = tempNum;
		}//����
		return;//���Բ�Ҫ����RETURN
	}
	for (auto it = station[start].begin(); it != station[start].end(); it++)
	{	//���������ڽӵ�
		int next = it->first;
		if (!vis[next])
		{	//��һ�����Ƕ�
			vis[next] = true;//��ֹ��ͷ·
			tempPath.push_back(next);//��
			DFS(next, end, tempPath, path);
			tempPath.pop_back();//��ԭ
			vis[next] = false;
		}
	}
}

int main()
{
	int n; cin >> n;
	for (int line = 1; line <= n; line++)
	{
		int m; cin >> m;
		int u; cin >> u;
		for (int i = 1; i < m; i++)
		{
			int v; cin >> v;
			station[u][v] = line;
			station[v][u] = line;
			u = v;//��ǰ��
		}
	}
	int k; cin >> k;
	while (k--)
	{
		int start, end;
		cin >> start >> end;
		transNum = 0;
		vector<int> path, tempPath;
		tempPath.push_back(start);
		fill(vis, vis + MAXV, false);
		DFS(start, end, tempPath, path);

		printf("%d\n", path.size() - 1);
		int preLine = station[path[0]][path[1]], preTransfer = start;
		for (int i = 2; i < path.size(); i++)
		{
			int nowLine = station[path[i - 1]][path[i]];
			if (nowLine != preLine)
			{
				printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, path[i - 1]);
				preLine = nowLine;
				preTransfer = path[i - 1];
			}
		}
		printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, end);
	}
	return 0;
}