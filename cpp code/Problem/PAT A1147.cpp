//PAT A1147.cpp 1147 Heaps (30 分)
//记住：！！！先有思路再去写
//基本思路未实现
//9.4评 看来当时还是懂得少，思路不清楚就敢来
#include <cstdio>
#include <vector>
using namespace std;

int const maxn = 1010;
vector<int> heap;
int m, n;

void postOrder(int i)
{	//i root结点
	if (i > n)	//空结点，返回
		return;
	postOrder(2 * i);
	postOrder(2 * i + 1);
	printf("%d ", heap[i]);
}

int judge(int i)
{	//返回1，maxHeap；-1，minHeap；0，not
	//返回当前结点flag，叶子-2
	int leftflag = 0, rightflag = 0, flag = 0;
	//递归基
	
	//判断当前树是那种堆


	//判断左右子树是哪种堆
	leftflag = judge(2 * i);
	rightflag = judge(2 * i + 1);
	//告诉上层自己是那种堆
	if (flag == 1 && leftflag == 1 && rightflag == 1)
		return 1;
	else if (flag == -1 && leftflag == -1 && rightflag == -1)
		return -1;
	else if (leftflag == -2)
		return flag;
}


int main()
{
	scanf("%d%d", &m, &n);
	heap.resize(n+1);	//弃用0号位
	for (int i = 0; i < m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &heap[j]);
		}
		int flag = judge(1);
		printf("%d\n", flag);
		//postOrder(1);
		//printf("\n");
	}
	return 0;
}