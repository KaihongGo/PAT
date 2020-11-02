//PAT A1129.cpp 1129 Recommendation System (25 ��)
//����˼·������vector�������ݺ������ڴ泬ʱ
//����������������У�
//��ȷ��set ����С�ںţ��Զ����������
//��ʱԭ��find���Ҳ������Բ��ң�̫�����Ż�set
//�����Ǻ�ʱ�󻧣����֣���ʹ����������ʶ�������еĲ�������˺�ʱ����
//�Ľ��� �������νṹ ��̬����
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

const int maxn = 50010;
struct Node
{
	int index;
	int freq;
	friend bool operator == (const Node& a, const Node& b)
	{
		return a.freq == b.freq && a.index == b.index;
	}
};

vector<Node> vi;
int showTime[maxn];

int main()
{
	int n, k; cin >> n >> k;
	int x; cin >> x;
	showTime[x]++;
	vi.push_back({ x,showTime[x] });
	for (int i = 1; i < n; i++)
	{
		cin >> x;
		printf("%d:", x);
		for (int i = 0; i < vi.size() && i < k; i++)
			printf(" %d", vi[i].index);
		printf("\n");	
		vector<Node>::iterator it;
		if (showTime[x] != 0)
		{	//���Ǻ�ʱ��
			Node temp = { x,showTime[x] };
			it = find(vi.begin(), vi.end(), temp);
			//�����ƶ�������Ȼ��ʱ
			it->freq = ++showTime[x];
			while (it > vi.begin() && it->freq > (it - 1)->freq)
			{	//���º󣬱�ǰһ���� //�߽籣֤
				swap(*it, *(it - 1));
				it--;
			}
		}
		else
		{
			vi.push_back({ x,++showTime[x] });
			it = vi.end() - 1;
		}
		//�Ƚ�index
		while (it > vi.begin() && it->freq == (it - 1)->freq && it->index < (it - 1)->index)
		{
			swap(*it, *(it - 1));
			it--;
			if (it == vi.begin()) break;
		}
	}
	return 0;
}