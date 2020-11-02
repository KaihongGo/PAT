//PAT A1049.cpp 1049 Counting Ones (30 分)
//

#include <algorithm>
#include <cstdio>
using namespace std;

const int maxn = 1000010;

int low[100] = {  10,100,1000,10000,100000,1000000,10000000,10000000,100000000,1000000000 };
int high[100] = { 19,199,1999,19999,199999,1999999,19999999,19999999,199999999,1999999999 };
int cntPre[100] = { 1, 8 + 1 + 10 };
//low[i]之前有多少，不包括low[i]
int main()
{
	for (int i = 2; i < 10; i++)
	{
		cntPre[i] = cntPre[i - 1] + low[i - 1] + 8;
	}
	int n = 12;
	//scanf("%d", n);
	int index = 0;
	int flag = 0;
	for (int i = 0; i < 10; i++)
	{
		if (n >= low[i] && n <= high[i])
		{
			index = i; 
			flag = 1;
		}
		else if (n >= high[i] && n <= low[i + 1])
		{
			index = i; 
			flag = 2;
		}
	}
	int cnt = 0;
	if (flag == 1)
	{//情况一，介于之间
		cnt = n - low[index] + 1;
	}
	else if (flag == 2)
	{
		//cnt = 
	}

	printf("%d %d\n", index, flag);
	for (int i = 0; i < 10; i++)
		printf("%d ", cntPre[i]);
	return 0;
}