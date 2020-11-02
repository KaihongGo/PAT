//PAT A1133.cpp 1133 Splitting A Linked List (25 ·Ö)
//

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100010;
struct Node
{
	int addr, key, next;
	int order = 2 * maxn;//invalid nodes
} node[maxn];

bool cmp(Node a, Node b)
{
	return a.order < b. order;
}

int main()
{
	int first, n, k;
	cin >> first >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int addr, data, next;
		cin >> addr >> data >> next;
		node[addr].addr = addr;
		node[addr].key = data;
		node[addr].next = next;	
	}
	int p = first;
	int cnt1 = 0, cnt2 = 0, cnt3 = 0;
	while (p != -1)
	{
		if (node[p].key < 0)
			node[p].order = -maxn + cnt1++;
		else if (node[p].key >= 0 && node[p].key <= k)
			node[p].order = cnt2++;
		else
			node[p].order = maxn + cnt3++;
		p = node[p].next;
	}
	int cnt = cnt1 + cnt2 + cnt3;
	sort(node, node + maxn, cmp);
	for (int i = 0; i < cnt; i++)
	{
		if (i != cnt - 1)
			printf("%05d %d %05d\n", node[i].addr, node[i].key, node[i + 1].addr);
		else
			printf("%05d %d -1\n", node[i].addr, node[i].key);
	}
}