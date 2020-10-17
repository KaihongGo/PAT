//PAT A1044.cpp 1044 Shopping in Mars (25 分)
//晴神代码
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 100010;
int sum[N];
int n, S, nearS = 100000010;
int upperBound(int L, int R, int x)
{	//返回在[L,R)内第一个大于x 的位置
	int left = L, right = R;
	while (left < right)
	{
		int mid = (left + right) / 2;
		if (sum[mid] > x)
			right = mid;
		else
			left = mid + 1;
	}
	return left;
}

int main()
{
	scanf("%d%d", &n, &S);
	sum[0] = 0;//初始化
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &sum[i]);
		sum[i] += sum[i - 1];
	}
	for (int i = 1; i <= n; i++)
	{	//枚举左端点
		int j = upperBound(i, n + 1, sum[i - 1] + S);
		if (sum[j - 1] - sum[i - 1] == S)//upBound返回大于值 
		{	//查找成功，注意是j-1而不是j
			nearS = S;
			break;
		}
		else if (j <= n && sum[j] - sum[i - 1] < nearS)
		{	//存在大于S 的解并小于nearS
			nearS = sum[j] - sum[i - 1];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		int j = upperBound(i, n + 1, sum[i - 1] + S);
		if (sum[j - 1] - sum[i - 1] == nearS)
			printf("%d-%d\n", i, j - 1);
	}

}