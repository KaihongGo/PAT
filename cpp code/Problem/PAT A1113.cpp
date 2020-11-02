//PAT A1113.cpp 1113 Integer Set Partition (25 ·Ö)
//s1 = accumulate(vi.begin(), vi.end(), 0);º¯Êý

#include <cstdio>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

const int maxn = 100010;

int main()
{
	int n;
	scanf("%d", &n);
	vector<int> vi;
	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);
		vi.push_back(a);
	}
	sort(vi.begin(), vi.end());
	int n1, n2, s1, s2;
	n1 = n / 2;
	n2 = n - n1;
	s1 = accumulate(vi.begin(), vi.begin() + n1, 0);
	s2 = accumulate(vi.begin() + n1, vi.end(), 0);

	printf("%d %d", abs(n1 - n2), s2 - s1);
}