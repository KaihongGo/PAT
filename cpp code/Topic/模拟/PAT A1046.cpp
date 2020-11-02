//PAT A1046.cpp 1046 Shortest Distance (20 ��)
//�ֲ��ø��Ӷȱ�������

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100010;
int D[MAXN];
int n;
int dist[MAXN];

int main()
{
	int sum = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{	//����0�±�
		scanf("%d", &D[i]);
		sum += D[i];
		dist[i] = sum;
	}
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{//10^9��ը�ˣ�����
		int low, high;
		cin >> low >> high;
		if (low > high)
			swap(low, high);
		int mindist = dist[high-1] - dist[low - 1];
		mindist = min(mindist, sum - mindist);
		printf("%d\n", mindist);
	}

}