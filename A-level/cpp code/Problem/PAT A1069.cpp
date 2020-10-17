//PAT A1069.cpp 1069 The Black Hole of Numbers (20 分)
//BUGS：应该用do while保证第一次执行

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

bool cmp_decrease(char a, char b)
{
	return a > b;
}

bool cmp_increase(char a, char b)
{
	return a < b;
}

int main()
{
	char num[10];
	cin >> num;
	int len = strlen(num);
	if (len < 4)
	{	//填充字符
		num[4] = '\0';
		for (int i = len; i < 4; i++)
			num[i] = '0';
	}
	int ans = atoi(num);
	
	do {
		sort(num, num + 4, cmp_decrease);
		int a = atoi(num);
		sort(num, num + 4, cmp_increase);
		int b = atoi(num);
		if (a == b)
		{
			printf("%04d - %04d = 0000", a, b);
			break;
		}
		ans = a - b;
		sprintf(num, "%04d", ans);
		printf("%04d - %04d = ", a, b);
		printf("%04d\n", ans);
		
	} while (ans != 6174);
	return 0;
}
