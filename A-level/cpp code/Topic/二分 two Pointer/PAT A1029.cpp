//PAT A1029.cpp 1029 Median (25 ·Ö)
//?????cin,scanf()??????
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 0x7fffffff;
const int maxn = 200010;
int A[maxn], B[maxn];

int main()
{
	int a, b; 
	cin >> a;
	for (int i = 1; i <= a; i++)
		scanf("%d", &A[i]);
	cin >> b;
	for (int i = 1; i <= b; i++)
		scanf("%d", &B[i]);
	//a trick
	A[a + 1] = INF; B[b + 1] = INF;//???????????
	int L = (a + b + 1) / 2 ;
	//i,j?????????????
	int i = 1, j = 1, cnt = 1;
	while (i - 1 + j - 1 < L)//???1??
	{//i); j)??????????i?j??????
		if (A[i] < B[j]) i++;
		else j++;
		cnt++;
	}
	printf("%d", max(A[i-1], B[j-1]));
	return 0;
}
