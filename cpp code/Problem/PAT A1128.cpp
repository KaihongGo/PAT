//PAT A1128.cpp 1128 N Queens Puzzle (20 ·Ö)
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int queen[10010];

int main()
{
	int k, n;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> queen[i];
		bool flag = true;
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				if (abs(queen[i] - queen[j]) == abs(i - j))
					flag = false;
				if (queen[i] == queen[j])
					flag = false;
			}
		}
		if (flag == false)
			printf("NO\n");
		else
			printf("YES\n");
	}
	
	return 0;
}