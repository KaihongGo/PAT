//PAT A1096.cpp 1096 Consecutive Factors (20 ·Ö)
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxn = 1e5;

int prime[maxn], pNum = 0;
bool primeFlag[maxn];

void findPrime()
{
	fill(primeFlag, primeFlag + maxn, true);
	for (int i = 2; i < maxn; i++)
	{
		if (primeFlag[i] == true)
		{
			prime[pNum++] = i;
			for (int j = 2 * i; j < maxn; j += i)
			{
				primeFlag[j] = false;
			}
		}
	}
}

struct factor
{
	int x, cnt;
} fac[maxn];

int main()
{
	findPrime();
	int n;
	cin >> n;
	int num = 0;
	int sqr = (int)sqrt(1.0 * n);
	for (int i = 0; i < pNum; i++)
	{
		if (n % prime[i] == 0)
		{
			fac[num].x = prime[i];
			fac[num].cnt = 0;
			while (n%prime[i]==0)
			{
				fac[num].cnt++;
				n /= prime[i];
			}
			num++;
		}
		if (n == 1)
			break;

	}
	for (int i = 0; i < num; i++)
	{
		printf("%d^%d", fac[i].x,fac[i].cnt);
		if (i < num - 1)printf(" * ");
	}
}