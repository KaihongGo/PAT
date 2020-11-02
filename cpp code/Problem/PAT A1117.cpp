//PAT A1117.cpp 1117 Eddington Number (25 ·Ö)
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <numeric>
#include <vector>
using namespace std;
vector<int> dist;

int main()
{
	int n; cin >> n;
	dist.resize(n);
	for (int i = 0; i < n; i++)
		cin >> dist[i];
	sort(dist.begin(), dist.end(), greater<int>());
	int maxE = 0;
	for (int i = 0; i < n; i++)
	{
		if (dist[i] > i + 1)
		{
			if (maxE < i + 1)
				maxE = i + 1;
		}
	}
	cout << maxE;
	return 0;
}