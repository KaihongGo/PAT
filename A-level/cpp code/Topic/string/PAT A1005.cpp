//PAT A1005.cpp 1005 Spell It Right (20 ·Ö)
//

#include <cstring>
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	string num[15] = {"zero", "one","two","three","four","five","six","seven","eight","nine" };
	char a[1000];
	scanf("%s", a);
	char sum[1000];
	int len = strlen(a);
	int b = 0;
	for (int i = 0; i < len; i++)
		b += a[i] - '0';
	sprintf(sum, "%d", b);
	len = strlen(sum);
	for (int i = 0; i < len; i++)
	{
		printf("%s", num[sum[i] - '0'].c_str());
		if (i != len - 1)
			printf(" ");
	}

}