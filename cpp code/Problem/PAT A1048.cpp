//PAT A1048.cpp 1048 Find Coins (25 分)
//

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int have[6000] = { 0 };//面额硬币出现次数
int n, m;//n total number of coins; m,the amount of money he has to pay

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int a; cin >> a;
		have[a]++;
	}
	bool flag = false;
	for (int i = 1; i <= m / 2; i++)
	{
		if (have[i] != 0)
		{	
			have[i]--;
			if (have[m - i] != 0)
			{
				printf("%d %d\n", i, m - i);
				flag = true;
				break;
			}
		}
	}
	if (!flag)
		printf("No Solution\n");
}