//PAT A1147.cpp 1147 Heaps (30 ��)
//ѧϰliuchuo
//��ֶ��⣬���ö���������
//����˼·:����ĳ�����������ͨ��ö�� ���ı�flag��־
//����˼·���ٷ����ж�˼��
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<int> heap;
int n;
vector<int> post;
void postOrder(int root)
{
	if (root > n) return;
	postOrder(root * 2);
	postOrder(root * 2 + 1);
	printf("%d%s", heap[root], root == 1 ? "\n" : " ");
}

int main()
{
	int m; cin >> m;
	cin >> n; heap.resize(n + 1);
	while (m--)
	{
		for (int i = 1; i <= n; i++)
			cin >> heap[i];
		bool isMax = true, isMin = true;
		for (int i = 2; i <= n; i++)
		{
			if (heap[i] > heap[i / 2]) isMax = false;
			if (heap[i] < heap[i / 2]) isMin = false;
		}
		if (isMin) printf("Min Heap\n");
		else if (isMax) printf("Max Heap\n");
		else printf("Not Heap\n");
		postOrder(1);
	}
}