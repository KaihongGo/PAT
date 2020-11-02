//PAT A1129.cpp 1129 Recommendation System (25 分)
//基本思路：利用vector处理数据后排序；内存超时
//暴力解决；并不可行！
//正确：set 重载小于号，自定义排序规则
//超时原因：find查找采用线性查找，太慢；优化set
//查找是耗时大户，发现；即使现在这样认识线性序列的操作，因此耗时严重
//改进： 采用树形结构 动态查找
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
		{	//找是耗时大户
			Node temp = { x,showTime[x] };
			it = find(vi.begin(), vi.end(), temp);
			//插入移动策略仍然超时
			it->freq = ++showTime[x];
			while (it > vi.begin() && it->freq > (it - 1)->freq)
			{	//更新后，比前一个大 //边界保证
				swap(*it, *(it - 1));
				it--;
			}
		}
		else
		{
			vi.push_back({ x,++showTime[x] });
			it = vi.end() - 1;
		}
		//比较index
		while (it > vi.begin() && it->freq == (it - 1)->freq && it->index < (it - 1)->index)
		{
			swap(*it, *(it - 1));
			it--;
			if (it == vi.begin()) break;
		}
	}
	return 0;
}