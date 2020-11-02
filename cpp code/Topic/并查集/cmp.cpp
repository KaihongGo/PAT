//PAT A1107.cpp 1107 Social Clusters (30 分)
//20分，原因未知
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 10010;
int father[maxn];

int findFather(int x)
{
	int a = x;
	while (x != father[x])
		x = father[x];
	while (a != father[a])
	{
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
}

void Union(int a, int b)
{
	int faA = findFather(a);
	int faB = findFather(b);
	if (faA != faB)
		father[a] = faB;
}

int have[maxn];
int main()
{
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		father[i] = i;
	for (int i = 1; i <= n; i++)
	{
		int k; scanf("%d:", &k);
		for (int j = 0; j < k; j++)
		{
			int hobby; cin >> hobby;
			if (have[hobby] == 0)
				have[hobby] = i;
			//else
				Union(i, have[hobby]);
		}
	}
	vector<int> isRoot(n + 1);
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		int far = findFather(i);
		//if (isRoot[far] == 0) cnt++;
		isRoot[far]++;
	}
	sort(isRoot.begin(), isRoot.end(), greater<>());
	for (int i = 0; i < n + 1; i++)
	{
		if (isRoot[i] != 0)cnt++;
	}
	printf("%d\n", cnt);
	for (int i = 0; i < cnt; i++)
	{
		printf("%d", isRoot[i]);
		if (i != cnt - 1)printf(" ");
	}
	printf("\n");
	return 0;
}