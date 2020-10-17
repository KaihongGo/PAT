//PAT A1103.cpp 1103 Integer Factorization (30 分)
//一个测试点未通过！！！原因，序列包括n
//典型题目:二元状态，选与不选，达到最优解
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int n, k, p, maxSum = -1;
vector<int> ans, temp, A;

void initA()
{	//产生可选序列
	int i = 0;
	while ((int)pow(i, p) <= n)
	{
		A.push_back((int)pow(i, p));
		i++;
	}
}

void DFS(int index, int nowK, int sum, int facSum)
{
	if (nowK == k && sum == n)
	{//更新最优解
		if (maxSum < facSum)
		{
			maxSum = facSum;
			ans = temp;
		}
		return;
	}
	if (nowK > k || sum > n) return;//剪枝
	if (index >= 1)
	{
		temp.push_back(index);//choose
		DFS(index, nowK + 1, sum + A[index], facSum + index);
		temp.pop_back();//recover
		//not choose
		DFS(index - 1, nowK, sum, facSum);
	}
}

int main()
{
	scanf("%d%d%d", &n, &k, &p);
	initA();
	DFS(A.size() - 1, 0, 0, 0);
	if (maxSum == -1) printf("Impossible\n");
	else
	{
		printf("%d = %d^%d", n, ans[0], p);
		for (int i = 1; i < ans.size(); i++)
		{
			printf(" + %d^%d", ans[i], p);
		}
	}
	return 0;
}