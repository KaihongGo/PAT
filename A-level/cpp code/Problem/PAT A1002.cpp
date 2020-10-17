//PAT A1002.cpp 1002 A+B for Polynomials (25 分)
//

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector<double> poly[2]; //下标表示指数
struct Node
{
	int exp;
	double coe;
};
int main()
{
	for (int i = 0; i < 2; i++)
	{
		poly[i].resize(1010);
		int k; cin >> k;
		int exp;
		double coe;
		for (int j = 0; j < k; j++)
		{
			cin >> exp >> coe;
			poly[i][exp] = coe;
		}
	}
	vector<Node> ans;
	for (int i = 0; i < 1010; i++)
	{
		double temp = poly[0][i] + poly[1][i];
		if (temp != 0)
			ans.push_back({ i,temp });
	}
	cout << ans.size();
	for (int i = ans.size() - 1; i >= 0; i--)
	{
		printf(" %d %.1f", ans[i].exp, ans[i].coe);
	}
	return 0;
}