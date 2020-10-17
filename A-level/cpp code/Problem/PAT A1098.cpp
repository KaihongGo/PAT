//PAT A1098.cpp 
//

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 1000;
vector<int> heap;
int n;//堆大小,元素个数
vector<int> vi;	//中间序列
int A[maxn] = { 0 };//插入序列
vector<int> insert;

void downAdjust(int low, int high)
{
	int i = low, j = 2 * i;//i欲调整元素，j左孩子 
	while (j <= high)
	{
		if (j + 1 <= high && heap[j + 1] > heap[j])
			j = j + 1;
		if (heap[j] > heap[i])
		{
			swap(heap[j], heap[i]);
			i = j;
			j = 2 * i;
		}
		else
			break;
	}
}

void createHeap()
{
	for (int i = n / 2; i >= 1; i--)
	{	//倒着来
		downAdjust(i, n);
	}
}

bool heapSort()
{//不使用0号位置
	createHeap();
	bool flag = false;
	for (int i = n; i > 1; i--)
	{
		swap(heap[i], heap[1]);
		downAdjust(1, i - 1);
		if (flag == true)
		{
			for (int i = 1; i <= n; i++)
			{
				printf("%d", heap[i]);
				if (i < n) printf(" ");
			}
			return true;
		}
		if (vi == heap)
		{
			flag = true;
			printf("Heap Sort\n");
		}
	}
	return false;
}

void insertSort()
{//A,n元素个数，不使用0号位置
	bool flag = false;
	for (int i = 2; i <= n; i++)
	{
		int temp = A[i], j = i;
		while (j > 0 && A[j - 1] > temp)
		{
			A[j] = A[j - 1];
			j--;
		}
		A[j] = temp;
		for (int k = 1; k <= n; k++)
		{
			insert[k] = A[k];
		}
		if (flag == true)
		{
			for (int i = 1; i <= n; i++)
			{
				printf("%d", insert[i]);
				if (i < n) printf(" ");
			}
			printf("\n");
			return;
		}
		if (insert == vi)
		{
			flag = true;
		}
	}

}

int main()
{
	scanf("%d", &n);
	insert.push_back(0);//占用vector 0号位
	insert.resize(n + 1);
	heap.push_back(0);//占用vector 0号位
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &A[i]);
		heap.push_back(A[i]);
	}

	vi.push_back(0);
	for (int i = 1; i <= n; i++)
	{
		int a;
		scanf("%d", &a);
		vi.push_back(a);
	}
	if (!heapSort())
	{
		printf("Insertion Sort\n");
		insertSort();
	}
}