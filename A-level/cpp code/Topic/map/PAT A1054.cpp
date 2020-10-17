//PAT A1054.cpp 1054 The Dominant Color (20 ·Ö)
//

#include <vector>
#include <map>
#include <cstdio>
#include <algorithm>
using namespace std;

map<int, int> mp;

struct node
{
	int color, cnt;
};
bool cmp(node a, node b)
{
	return a.cnt > b.cnt;
}

int main()
{
	int m, n;
	scanf("%d %d", &m, &n);
	int color;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{//Ò»ÐÐ
			scanf("%d", &color);
			mp[color]++;
		}
	}
	vector<node> vi;
	for (auto it = mp.begin(); it != mp.end(); it++)
		vi.push_back(node{ it->first,it->second });
	sort(vi.begin(), vi.end(), cmp);
	printf("%d\n", vi[0]);
}