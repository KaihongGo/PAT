//PAT A1152.cpp 1152 Google Recruitment (20 ·Ö)
//

#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;

bool isPrime(int n)
{
	if (n <= 1) return false;
	int sqr = (int)sqrt(1.0 * n);
	for (int i = 2; i <= sqr; i++)
	{
		if (n % i == 0) return false;
	}
	return true;
}

int main()
{
	int L, K;
	cin >> L >> K;
	string str;
	cin >> str;
	long long num;
	bool flag = false;
	for (int i = 0; i <= L - K; i++)
	{
		num = atoll(str.substr(i, K).c_str());
		if (isPrime(num))
		{
			printf("%s\n", str.substr(i,K).c_str());
			return 0;
		}
	}
	printf("404\n");
	return 0 ;
}