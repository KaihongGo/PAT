//PAT A1081.cpp 1081 Rational Sum (20 ·Ö)
//

#include <iostream>
#include <cstdio>
#include <math.h>

struct Frac
{
	long long up = 0, down = 1;
};

long long gcd(long long a, long long b)
{
	if (b == 0) return a;
	else return gcd(b, a % b);
}

Frac reduction(Frac &a)
{
	if (a.down < 0)
	{
		a.up = -a.up;
		a.down = -a.down;
	}
	if (a.up == 0)
		a.down = 1;
	else
	{
		long long d = gcd(abs(a.up), abs(a.down));
		a.up = a.up / d;
		a.down = a.down / d;
	}
	return a;
}

Frac add(Frac a, Frac b)
{
	Frac result;
	result.up = a.up * b.down + a.down * b.up;
	result.down = a.down * b.down;
	reduction(result);
	return result;
}

int main()
{
	using namespace std;
	int n;
	cin >> n;
	Frac result;
	for (int i = 0; i < n; i++)
	{
		Frac temp;
		scanf("%lld/%lld", &temp.up, &temp.down);
		result = add(result, temp);
	}
	if (result.down == 1) printf("%lld", result.up);
	else if (abs(result.up) > result.down)
		printf("%lld %lld/%lld", result.up / result.down, abs(result.up) % result.down, result.down);
	else
		printf("%lld/%lld", result.up, result.down);
}