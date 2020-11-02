//PAT A1074.cpp 1074 Reversing Linked List (25 分)
//two pointer二路推进策略
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 100010;
struct Node
{
	int key, addr, next;
} list[MAXN];

int main()
{
	int head, n, k;
	cin >> head >> n >> k;
	for (int i = 0; i < n; i++)
	{
		Node temp;
		cin >> temp.addr >> temp.key >> temp.next;
		list[temp.addr] = temp;
	}
	vector<int> vi, temp;
	for (int p = head; p != -1; p = list[p].next)
		vi.push_back(p); //顺序存放
	int i = 0, j = 0; // i pre; j after;
	while (j < vi.size())
	{	//二路推进原理, two pointer
		j = j + k;//j递增k单位
		if (j > vi.size())
		{	//最后一组
			while (i < vi.size())
				temp.push_back(vi[i++]);
		}
		else
		{	//反序添加
			for (int pos = j - 1; pos >= i; pos--)
				temp.push_back(vi[pos]);				
		}		
		i = i + k;
	}
	
	for (int i = 0; i < temp.size(); i++)
	{
		printf("%05d %d", temp[i], list[temp[i]].key);
		if (i == temp.size() - 1) printf(" -1");
		else printf(" %05d", temp[i + 1]);
		printf("\n");
	}
	return 0;
}