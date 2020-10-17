//PAT A1085.cpp 1085 Perfect Sequence (25 分)
//
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, p;
	cin >> n >> p;
	vector<int> vi(n);
	for (int i = 0; i < n; i++)
		cin >> vi[i];
	sort(vi.begin(), vi.end());
	int maxnum = 0;
	for (int i = n - 1; i >= 0; i--)
	{	//枚举最大值
		int Max = vi[i];
		double bound = (double)Max / p;
		int k = lower_bound(vi.begin(), vi.begin() + i + 1, bound) - vi.begin();
		if (i - k + 1 > maxnum)
			maxnum = i - k + 1;
	}
	cout << maxnum;
}
