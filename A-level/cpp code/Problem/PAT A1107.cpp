//PAT A1107(1).cpp
//ֻͨ���������Ե㣬����ԭ��δ֪
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1010;
int father[maxn];

int findFather(int x)
{
	int a = x;
	while (x != father[x])
		x = father[x];
	while (a != father[a])
	{
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
}

void Union(int a, int b)
{
	int farA = findFather(a);
	int farB = findFather(b);
	if (farA != farB)
		father[farB] = farA;
}

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	int course[maxn] = { 0 };
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)//��ʼ�����鼯
		father[i] = i;
	for (int i = 1; i <= n; i++)
	{
		int k = 0; scanf("%d:", &k);
		for (int j = 0; j < k; j++)
		{
			int h; scanf("%d", &h);
			if (course[h] == 0)
				course[h] = i;
			Union(i, findFather(course[h]));//�˴���ͬ!!
		}
	}
	int isRoot[maxn] = { 0 };
	for (int i = 1; i <= n; i++)
	{	//ͳ�Ƽ��ϸ�����������hash����
		isRoot[findFather(i)]++;
	}
	sort(isRoot+1, isRoot + n + 1, cmp);
	int count = 0;
	for (int i = 1; i <= n; i++)
	{
		if (isRoot[i] != 0)
			count++;
	}
	printf("%d\n", count);
	for (int i = 1; i <= count; i++)
	{
		printf("%d", isRoot[i]);
		if (i < count) printf(" ");
	}
}