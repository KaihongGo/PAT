//PAT A1089.cpp 1089 Insert or Merge (25 分)
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool insertSort(vector<int> &A, vector<int> &B)
{	//元素个数n，下标由0开始
	int n = A.size();
	bool flag = false;
	for (int i = 1; i < n; i++)
	{
		if (i!= 1 && A == B)
			flag = true;
		int temp = A[i], j = i;
		while (j >= 1 && A[j - 1] > temp)
		{
			A[j] = A[j - 1];
			j--;
		}
		A[j] = temp;
		if (flag) return flag;
	}
	return flag;
}

void mergeSort(vector<int> &A, int left, int right, vector<int> B, int n)
{
	bool flag = false;
	for (int step = 2; step / 2 <= n; step *= 2)
	{
		if (step != 2 && A == B) flag = true;
		for (int i = 0; i < n; i += step)
		{
			sort(A.begin() + i, A.begin() + min(i + step, n));
		}
		if (flag == true)
		{
			for (int k = 0; k < n; k++)
			{
				printf("%d", A[k]);
				if (k != n - 1)printf(" ");
			}
			return;
		}
	}
}

int main()
{
	vector<int> A, B;
	int n; cin >> n;
	A.resize(n); B.resize(n);
	for (int i = 0; i < n; i++)
		cin >> A[i];
	vector<int> temp = A;
	for (int i = 0; i < n; i++)
		cin >> B[i];
	bool flag = insertSort(A, B);
	if (flag == true)
	{
		printf("Insertion Sort\n");
		for (int k = 0; k < n; k++)
		{
			printf("%d", A[k]);
			if (k != n - 1)printf(" ");
		}
	}
	A = temp;
	if (flag == false)
	{
		printf("Merge Sort\n");
		mergeSort(A, 0, n - 1, B, n);
	}
}