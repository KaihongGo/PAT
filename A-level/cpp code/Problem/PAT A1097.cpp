//PAT A1097.cpp 1097 Deduplication on a Linked List (25 分)
//only pass 2 test case; don't know the reason;
//链表题的bug就在于静态实现，没让你自己真用链表实现操作；
//借助vector控制不是更好！
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int maxn = 100010;
bool hashTable[maxn];
struct Node
{
	int data, next;
	bool flag;//flag: true need del
} list[maxn];

void printlist(int first)
{
	int p = first;
	while (p!=-1)
	{
		printf("%05d %d", p, list[p].data);
		if (list[p].next != -1)
			printf(" %05d", list[p].next);
		else
			printf(" -1");
		printf("\n");
		p = list[p].next;
	}
}

int append(int rear, int q)
{	//append q; 传入尾巴指针,return rear pointer
	int p = rear;
	list[p].next = q;
	list[q].next = -1;
	return q;
}

int main()
{
	int first, n;
	cin >> first >> n;
	for (int i = 0; i < n; i++)
	{	//input file contain invalid node!!
		int addr, data, next;
		cin >> addr >> data >> next;
		list[addr].data = data;
		list[addr].next = next;
 	}
	int p = -1, q = -1;
	p = first;
	while (p!= -1)
	{
		if (hashTable[abs(list[p].data)] == false)
			hashTable[abs(list[p].data)] = true;
		else
			list[p].flag = true;//need del
		p = list[p].next;
	}

	p = first;
	int removeList = -1;
	while (p != -1)
	{
		if (list[p].flag)
		{
			removeList = p;
			break;
		}
		p = list[p].next;
	}
	p = first;
	q = list[p].next;
	int rp = removeList, rq = -1;
	while (q != -1)
	{	//del q!! 前指针
		if (list[q].flag == true)
		{
			rq = q;
			list[p].next = list[q].next;
			q = list[q].next;
			//append to removed list
			rp = append(rp, rq);
		}
		p = list[p].next;
		q = list[q].next;
	}
	printlist(first);
	printlist(removeList);
	return 0;
}