//PAT A1110.cpp 1110 Complete Binary Tree (25 分)
//基本思路：层序遍历编号策略

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

struct Node
{
	int left;
	int right;
	int index;
};

bool cmp(Node a, Node b)
{//按编号排序
	return a.index < b.index;
}

int index = 1;//编号
int last = -1;
bool layerOrder(int root, vector<Node> &Tree)
{
	queue<int> q;
	q.push(root);
	Tree[root].index = index++;
	while (!q.empty())
	{
		int front = q.front();
		q.pop();
		int left = Tree[front].left;
		int right = Tree[front].right;
		if (left != -1)
		{
			q.push(left);
			Tree[left].index = index++;
			if (Tree[left].index != Tree[front].index * 2) return false;
		}
		if (right != -1)
		{
			q.push(right);
			Tree[right].index = index++;
			if (Tree[right].index != Tree[front].index * 2 + 1) return false;
		}
		if (q.empty()) last = front;
	}
	return true;
}

int main()
{
	int n; cin >> n;
	vector<Node> Tree(n);
	vector<int> parent(n,-1);
	for (int i = 0; i < n; i++)
	{
		string left, right;
		cin >> left >> right;
		if (left == "-") Tree[i].left = -1;
		else
		{
			Tree[i].left = stoi(left);
			parent[Tree[i].left] = i;
		}
		if (right == "-") Tree[i].right = -1;
		else
		{
			Tree[i].right = stoi(right);
			parent[Tree[i].right] = i;
		}
	}
	int root = -1;//找根
	for (int i = 0; i < n; i++)
	{
		if (parent[i] == -1)
		{
			root = i; break;
		}
	}
	bool flag = layerOrder(root, Tree);
	if (flag) printf("YES %d", last);
	else printf("NO %d", root);
	return 0;
}