//PAT A1114(1).cpp
//liuchuo

#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

const int maxn = 10010;

struct DATA
{
	int id, dad, mom;
	int child[10];
	int sets, area;
} members[maxn];

struct ANS
{
	int id, num;
	double sets, area;
} ans[maxn];

int father[maxn]; //并查集单独定义，建立结点下标映射关系

int findFather(int x)
{
	while (x != father[x])
		x = father[x];
	return x;
}

bool cmp(ANS a, ANS b)
{
	if (a.area != b.area)
		return a.area > b.area;
	else
		return a.id < b.id;
}

void Union(int a, int b)
{
	int faA = findFather(a);
	int faB = findFather(b);
	father[max(faA, faB)] = min(faA, faB); //保证root结点值最小
}

//返回并查集中有几个单独集合
//返回并查集中一个集合有几个元素

int main()
{
	set<int> person; //存储有效结点
	set<int> root;	 //存储root结点

	for (int i = 0; i < maxn; i++)
		father[i] = i; //初始化并查集
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int k;
		scanf("%d %d %d %d", &members[i].id, &members[i].dad, &members[i].mom, &k);
		person.insert(members[i].id);
		if (members[i].dad != -1)
		{
			Union(members[i].id, members[i].dad);
			person.insert(members[i].dad);
		}
		if (members[i].mom != -1)
		{
			Union(members[i].id, members[i].mom);
			person.insert(members[i].mom);
		}
		for (int j = 0; j < k; j++)
		{
			scanf("%d", &members[i].child[j]);
			Union(members[i].id, members[i].child[j]);
			person.insert(members[i].child[j]);
		}
		scanf("%d %d", &members[i].sets, &members[i].area);
	}
	for (int i = 0; i < n; i++)
	{ //遍历整个有效id
		/*
		此处优化策略，为了不进行全局遍历	
		可对唯一的根给出映射map	
		*/
		int father = findFather(members[i].id);
		root.insert(father);	 //记录根情况，可是vector
		ans[father].id = father; //表明struct默认元素值为0
		ans[father].area += members[i].area;
		ans[father].sets += members[i].sets;
	}
	for (int i = 0; i < maxn; i++)
		ans[findFather(i)].num++; //统计集合元素个数，遍历整个并查集
	printf("%d\n", root.size());
	for (auto i : root)
	{
		ans[i].area /= ans[i].num;
		ans[i].sets /= ans[i].num;
	}
	sort(ans, ans + maxn, cmp);
	for (int i = 0; i < root.size(); i++)
	{
		printf("%04d %d %.3f %.3f\n", ans[i].id, ans[i].num, ans[i].sets, ans[i].area);
	}
	return 0;
}