//PAT A1009.cpp 1009 Product of Polynomials (25 分)
//数组开小了

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
	int exp;
	double coe;
};

int main()
{
	vector<Node> poly[2];
	int exp;
	double coe;
	for (int i = 0; i < 2; i++)
	{
		int k; cin >> k;//k个非0项
		for (int j = 0; j < k; j++) {
			cin >> exp >> coe;
			poly[i].push_back({ exp,coe });
		}
	}
	vector<double> ans(2010);//下标对应exp
	for (int i = 0; i < poly[0].size(); i++)
	{
		for (int j = 0; j < poly[1].size(); j++)
		{
			exp = poly[0][i].exp + poly[1][j].exp;
			coe = poly[0][i].coe * poly[1][j].coe;
			ans[exp] += coe;
		}
	}
	int cnt = 0;
	for (int i = 0; i < 2010; i++)
	{
		if (ans[i] != 0) cnt++;
	}
	printf("%d", cnt);
	for (int i = 2001; i >= 0; i--)
	{
		if (ans[i] != 0)
		{
			printf(" %d %.1f", i, ans[i]);
		}
	}
	return 0;
}