//PAT A1088.cpp 1088 Rational Arithmetic (20 分)
//两个测试点未过，具体原因未知；代码和晴神一样
//原因：头文件导致的编译问题！！！换成以下ok
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

struct Frac
{
	ll up, down;
};

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
		ll d = gcd(abs(a.up), abs(a.down));
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

Frac sub(Frac a, Frac b)
{
	Frac result;
	result.up = a.up * b.down - a.down * b.up;
	result.down = a.down * b.down;
	reduction(result);
	return result;
}

Frac multi(Frac a, Frac b)
{
	Frac result;
	result.up = a.up * b.up;
	result.down = a.down * b.down;
	reduction(result);
	return result;
}

Frac divide(Frac a, Frac b)
{
	Frac result;
	result.up = a.up * b.down;
	result.down = a.down * b.up;
	reduction(result);
	return result;
}

void showResult(Frac r)
{
	reduction(r);
	if (r.up < 0)
		printf("(");
	if (r.down == 1)
		printf("%lld", r.up);
	else if (abs(r.up) > r.down)
		printf("%lld %lld/%lld", r.up / r.down, abs(r.up) % r.down, r.down);
	else
		printf("%lld/%lld", r.up, r.down);
	if (r.up < 0)
		printf(")");
}

int main()
{
	Frac a, b;
	scanf("%lld/%lld %lld/%lld", &a.up, &a.down, &b.up, &b.down);
	showResult(a);
	printf(" + ");
	showResult(b);
	printf(" = ");
	showResult(add(a, b));
	printf("\n");

	showResult(a);
	printf(" - ");
	showResult(b);
	printf(" = ");
	showResult(sub(a, b));
	printf("\n");

	showResult(a);
	printf(" * ");
	showResult(b);
	printf(" = ");
	showResult(multi(a, b));
	printf("\n");

	showResult(a);
	printf(" / ");
	showResult(b);
	printf(" = ");
	if (b.up == 0)
		printf("Inf");
	else
		showResult(divide(a, b));
}