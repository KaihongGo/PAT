//PAT A1038.cpp 1038 Recover the Smallest Number (30 分)
//该思路有一个测试点未过，原因未知

#include <iostream>
#include <cstdio>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
	string num;
	int flag;//填充首数字个数
};
vector<Node> seg;

bool cmpless(Node a, Node b)
{
	return a.num < b.num;
}

int main()
{
	int n; cin >> n;
	seg.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> seg[i].num;
		char ch = seg[i].num[0];
		while (seg[i].num.size() <= 8)
		{	//添加位置，相同首数字一组处理
			seg[i].num.push_back(ch);
			seg[i].flag++;
		}
	}
	sort(seg.begin(), seg.end(), cmpless);
	string ans;
	for (int i = 0; i < n; i++)
	{	//删除填充
		while (seg[i].flag != 0)
		{
			seg[i].num.pop_back();
			seg[i].flag--;
		}
		ans += seg[i].num;
	}
	while (ans.size() != 0 && ans[0] == '0')
	{
		ans.erase(ans.begin());
	}
	if (ans.size() == 0) cout << 0;
	else
		cout << ans;
}