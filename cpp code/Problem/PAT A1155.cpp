//PAT A1155.cpp	1155 Heap Paths (30 分)
//
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> ans;
void DFS(vector<int> heap, int i, int n)
{
	if (2 * i > n)
	{	//退,叶结点,触及边界
		ans.push_back(heap[i]);
		//相关操作
		for (auto it = ans.begin(); it != ans.end(); it++)
			printf("%d%s", *it, it != ans.end() - 1 ? " " : "\n");
		ans.pop_back();
		return;
	}
	ans.push_back(heap[i]);
	//相关操作，当前处理阶段
	if (2 * i + 1 <= n) DFS(heap, 2 * i + 1, n);
	if (2 * i <= n)	DFS(heap, 2 * i, n);
	ans.pop_back();
	return;
}

bool isMaxHeap(vector<int> heap, int n)
{	//n个元素，下标1开始
	int i = 1, j = 2 * i;//左孩子
	while (i <= n && j <= n)
	{
		if (j + 1 <= n && heap[j + 1] > heap[j])
		{//取孩子最大的
			j = j + 1;
		}
		if (heap[j] > heap[i])
			return false;
		i = i + 1;
		j = 2 * i;
	}
	return true;
}

bool isMinHeap(vector<int> heap, int n)
{
	int i = 1, j = 2 * i;
	while (i<=n && j <=n)
	{
		if (j + 1 <= n && heap[j + 1] < heap[j])
			j = j + 1;
		if (heap[j] < heap[i])
			return false;
		i = i + 1;
		j = 2 * i;
	}
	return true;
}

int main()
{
	int n; cin >> n;
	vector<int> heap(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> heap[i];
	DFS(heap, 1, n);
	if (isMaxHeap(heap, n))
		printf("Max Heap\n");
	else if (isMinHeap(heap, n))
		printf("Min Heap\n");
	else
		printf("Not Heap\n");
	return 0;
}