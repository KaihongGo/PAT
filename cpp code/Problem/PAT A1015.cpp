//PAT A1015.cpp 1015 Reversible Primes (20 分)
//素数


#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

bool isPrime(int a)
{
	if (a <= 1) return false;
	int sqr = (int)sqrt(1.0 * a);
	for (int i = 2; i <= sqr; i++)
		if (a % i == 0) return false;
	return true;
}


int main()
{
	int n, d;
	while (cin >> n >> d)
	{
		if (n < 0) break;
		if (!isPrime(n))
			printf("No\n");
		else
		{
			vector<int> dnum;//存储d进制数
			do {
				dnum.push_back(n % d);
				n = n / d;
			} while (n != 0);
			int rn, product = 1;
			for (int i = 0; i < dnum.size(); i++)
				n = n * d + dnum[i];
			if (isPrime(n)) printf("Yes\n");
			else printf("No\n");
		}
	}
}