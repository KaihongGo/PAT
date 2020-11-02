//PAT A1149.cpp 1149 Dangerous Goods Packaging (25 分)
//
#include <map>
#include <set>
#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
vector<int> vi[maxn];

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		vi[a].push_back(b);
		vi[b].push_back(a);
	}
	map<int, int> mp;
	for (int i = 0; i < m; i++)
	{
		int k; cin >> k;
		mp.clear();
		for (int i = 0; i < k; i++)
		{
			int id; cin >> id;
			mp[id] = 1;
		}
		bool flag = true;
		for (auto it = mp.begin(); it != mp.end(); it++)
		{
			int id = it->first;
			for (int j = 0; j < vi[id].size(); j++)
			{
				if (mp.find(vi[id][j]) != mp.end())
				{	//不想容的出现了
					flag = false;
					break;
				}
			}
		}
		if (flag == true)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
