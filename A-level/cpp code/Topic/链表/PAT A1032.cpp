// PAT A1032.cpp Sharing
// 实际运行测试点1, 3不通过
// 错误原因：循环条件错
#include <cstdio>
#include <cstring>
const int MAXSIZE = 100010;

struct	Node
{
	char data;
	int next;
	int flag;	//标志位，标记是否在第一个链表中出现
}node[MAXSIZE];

int main()
{
	int n, addr1, addr2;
	scanf("%d %d %d", &addr1, &addr2, &n);
	int addr, next;
	char ch;
	for (int i = 0; i < n; i++)
	{	//输入
		scanf("%d %c %d", &addr, &ch, &next);
		node[addr].data = ch;
		node[addr].next = next;
	}
	//遍历链表1
	int k = addr1;
	while (k != -1)	// 错误点：node[k].next != -1; 循环条件错
	{
		node[k].flag = 1;	// 结点在第一个链表出现，赋值1
		k = node[k].next;
	}
	k = addr2; 
	while (k != -1)
	{
		if (node[k].flag == 1)
		{
			printf("%05d\n", k);
			return 0;
		}
		k = node[k].next;
	}
	printf("-1\n");
	return 0;
}


//PAT A1052.cpp 1052 Linked List Sorting (25 分)
//
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
const int maxn = 100010;
struct Node
{
	int addr, key, next;
	bool valid;
	friend bool operator < (const Node& a, const Node& b)
	{
		 return a.key < b.key;
	}
};
set<Node> list;
int main()
{
	int n, head;
	cin >> n >> head;
	for (int i = 0; i < n; i++)
	{
		Node temp;
		cin >> temp.addr >> temp.key >> temp.next;
		list.insert(temp);
	}
	printf("%d %05d\n", list.size(), list.begin()->addr);
	printf("%05d %d", list.begin()->addr, list.begin()->key);
	for (auto it = list.begin(); it != list.end(); it++)
	{
		if (it == list.begin()) continue;
		printf(" %05d\n", it->addr);
		printf("%05d %d", it->addr, it->key);
	}
	printf(" -1\n");
	return 0;
}