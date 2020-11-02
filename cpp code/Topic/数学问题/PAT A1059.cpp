//PAT A1059.cpp 1059 Prime Factors (25 ·Ö)
//

#include <vector>
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

struct factor
{
	int x, cnt = 0;
}fac[10];

const int maxn = 100010;
int prime[maxn], pNum = 0;
bool p[maxn] = { 0 };

void Find_Prime()
{
	for (int i = 2; i < maxn; i++)
	{
		if (p[i] == false)
		{
			prime[pNum++] = i;
			for (int j = i + i; j < maxn; j += i)
				p[j] = true;
		}
	}
}

int main()
{
	Find_Prime();
	int n;
	cin >> n;
	if (n == 1)
	{
		printf("%d=%d", n, n);
		return 0;
	}
	int orign = n;
	int num = 0;
	for (int i = 0; i < pNum && prime[i] <= (int)sqrt(1.0 * n); i++)
	{
		if (n % prime[i] == 0)
		{
			fac[num].x = prime[i];
			fac[num].cnt = 0;
			while (n % prime[i] == 0)
			{
				fac[num].cnt++;
				n /= prime[i];
			}
			num++;
		}
	}
	if (n != 1)
	{
		fac[num].x = n;
		fac[num++].cnt = 1;
	}
	if (fac[0].cnt > 1)
		printf("%d=%d^%d", orign, fac[0].x, fac[0].cnt);
	else
		printf("%d=%d", orign, fac[0].x);
	for (int i = 1; i < num; i++)
	{
		if (fac[i].cnt > 1)
			printf("*%d^%d", fac[i].x, fac[i].cnt);
		else
			printf("*%d", fac[i].x);
	}
}