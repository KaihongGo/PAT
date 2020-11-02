//PAT A1118.cpp 1118 Birds in Forest (25 分)
//

#include <cstdio>
#include <vector>
#include <set>

using namespace std;

const int maxn = 100010;

int father[maxn];
int a[maxn], b[maxn];//buffer

int findFather(int x)
{
	int a = x;
	while (x != father[x])
		x = father[x];
	//压缩路径
	while (a!= father[a])
	{
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
}

void Union(int a, int b)
{
	int faA = findFather(a);
	int faB = findFather(b);
	if (faA != faB)
		father[faA] = faB;
}

bool sameTree(int a, int b)
{
	int faA = findFather(a);
	int faB = findFather(b);
	if (faA == faB)
		return true;
	else
		return false;
}

int main()
{
	set<int> birds;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < maxn; i++)
		father[i] = i;	//初始化
	int first[maxn];
	for (int i = 0; i < n; i++)
	{
		int k;
		scanf("%d", &k);
		for (int j = 0; j < k; j++)
		{
			int bird;
			scanf("%d", &bird);
			birds.insert(bird);
			if (j == 0) first[i] = bird;
			else Union(first[i], bird);
		}
	}
	int q;
	scanf("%d", &q);

	set<int> root;	//统计根
	for (int i = 0; i < n; i++)
		root.insert(findFather(first[i]));
	
	for (int i = 0; i < q; i++)
		scanf("%d %d", &a[i], &b[i]);

	printf("%d %d\n", root.size(), birds.size());
	for (int i = 0; i < q; i++)
	{
		if (sameTree(a[i], b[i]))
			printf("Yes\n");
		else
			printf("No\n");
	}

}