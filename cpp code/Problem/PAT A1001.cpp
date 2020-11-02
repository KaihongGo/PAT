//PAT A1001.cpp 1001 A+B Format (20 分)
//三个测试点未过

#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	int sum = a + b;
	//printf("%d\n", sum);
	char str[20];
	sprintf(str, "%d", sum);
	int len = strlen(str);
	int re = 0;
	if (str[0] != '-')
	{
		re = len;
		do {
			re %= 3;
		} while (re >= 3);
		for (int i = 0; i < re; i++)
			printf("%c", str[i]);
		if(re != 0)
			printf(",");
		for (int i = re; i < len; i = i + 3)
		{
			for (int j = 0; j < 3; j++)
				printf("%c", str[i + j]);
			if (i + 2 != len - 1)
				printf(",");
		}
	}
	else
	{
		re = len - 1;
		do {
			re %= 3;
		} while (re >= 3);
		printf("-");
		for (int i = 1; i <= re; i++)
			printf("%c", str[i]);
		if (re != 0)
			printf(",");
		for (int i = re + 1; i < len; i = i + 3)
		{
			for (int j = 0; j < 3; j++)
				printf("%c", str[i + j]);
			if(i + 2 != len-1)
				printf(",");
		}
	}
}