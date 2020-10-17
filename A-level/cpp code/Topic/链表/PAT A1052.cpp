// PAT A1052.cpp 1052 Linked List Sorting (25 分)
// 运行时1，4测试点未通过；
// 错误原因：没有处理特例；无的情况；n并不是有效node，需要计数有效结点
//为什么对有效结点进行标记？可能输入案例提前输入-1；
//结束了已经，但是仍在输入产生无效数据；故需要对链表进行循链标记，而不在输入时标记flag
//一定要对输入有概念，处理的一定是有效输入
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100010;
struct Node
{
	int addr, key, next, valid;	// 无效置0，有效置1
	// 保证无效flag > 有效flag；利于排序
} list[maxn];

bool cmp(Node a, Node b)
{
	if (a.valid == 0 || b.valid == 0) return a.valid > b.valid;	// 有效放左边
	else return a.key < b.key;
}

int main()
{
	int n, head;
	cin >> n >> head;
	for (int i = 0; i < n; i++)
	{
		Node temp;
		cin >> temp.addr >> temp.key >> temp.next;
		list[temp.addr] = temp;
	}
	int cnt = 0;
	for(int p = head; p != -1; p = list[p].next)
	{
		list[p].valid = 1;
		cnt++;
	}
	sort(list, list + maxn, cmp);
	if (cnt == 0) //特判处理，极其重要
		printf("%d %d", 0, -1);
	else
	{
		printf("%d %05d\n", cnt, list[0].addr);
		for (int i = 0; i < cnt; i++)
		{
			if (i!=cnt -1)
				printf("%05d %d %05d\n", list[i].addr, list[i].key, list[i + 1].addr);
			else
				printf("%05d %d -1\n", list[i].addr, list[i].key);	
		}
	}
	return 0;
}