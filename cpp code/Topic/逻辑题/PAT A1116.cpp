//PAT A1116.cpp 1116 Come on! Let's C (20 分)
//

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
const int maxn = 10010;
int person[maxn];
int rankList[maxn] = { 0 };
bool checked[maxn];

bool isPrime(int x)
{
	if (x <= 1) return false;
	int sqr = sqrt(x);
	for (int i = 2; i <= sqr; i++)
	{
		if (x % i == 0)
			return false;
	}
	return true;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> person[i];		
	for (int i = 0; i < n; i++)
		rankList[person[i]] = i + 1;
	int k;
	cin >> k;
	int query;
	for (int i = 0; i < k; i++)
	{
		cin >> query;
		printf("%04d: ", query);
		if (rankList[query] == 0)
		{
			printf("Are you kidding?\n");
		}
		else
		{	//在队列里
			if (!checked[query])
			{
				checked[query] = true;
				if (rankList[query] == 1)
				{
					printf("Mystery Award\n");
				}	
				else
				{
					if (isPrime(rankList[query]))
						printf("Minion\n");
					else
						printf("Chocolate\n");
				}
			}
			else
				printf("Checked\n");
		}
	}
}