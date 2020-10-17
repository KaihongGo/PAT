//PAT A1101.cpp 1101 Quick Sort (25 分)
//16分，具体原因位置！！
//基本思路：排序后下标不变
//实际，仍有三个测试点未过！
//原因：不仅仅位置不变，并且左右两边不允许有元素不合规

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 100010;

int main()
{
	int n;
	scanf("%d", &n);
	vector<int> data;
	data.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &data[i]);
	vector<int> temp = data;
	sort(data.begin(), data.end());
	vector<int> ans;
	int max = 0;
	for (int i = 0; i < data.size(); i++)
	{
		if (data[i] == temp[i] && temp[i] > max)
			ans.push_back(data[i]);//事实上，存在问题；需要考虑右边最小的数
		if (temp[i] > max)//增加代码，找左侧最大值
			max = temp[i];

	}
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++)
	{
		printf("%d", ans[i]);
		if (i < ans.size() - 1)
			printf(" ");
	}
	printf("\n");
}

