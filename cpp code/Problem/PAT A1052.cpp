// PAT A1052.cpp 1052 Linked List Sorting (25 ��)
// ����ʱ1��4���Ե�δͨ����
// ����ԭ��û�д����������޵������n��������Чnode����Ҫ������Ч���
//Ϊʲô����Ч�����б�ǣ��������밸����ǰ����-1��
//�������Ѿ��������������������Ч���ݣ�����Ҫ���������ѭ����ǣ�����������ʱ���flag
//һ��Ҫ�������и�������һ������Ч����
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100010;
struct Node
{
	int addr, key, next, valid;	// ��Ч��0����Ч��1
	// ��֤��Чflag > ��Чflag����������
} list[maxn];

bool cmp(Node a, Node b)
{
	if (a.valid == 0 || b.valid == 0) return a.valid > b.valid;	// ��Ч�����
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
	if (cnt == 0) //���д���������Ҫ
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