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

int father[maxn]; //���鼯�������壬��������±�ӳ���ϵ

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
	father[max(faA, faB)] = min(faA, faB); //��֤root���ֵ��С
}

//���ز��鼯���м�����������
//���ز��鼯��һ�������м���Ԫ��

int main()
{
	set<int> person; //�洢��Ч���
	set<int> root;	 //�洢root���

	for (int i = 0; i < maxn; i++)
		father[i] = i; //��ʼ�����鼯
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
	{ //����������Чid
		/*
		�˴��Ż����ԣ�Ϊ�˲�����ȫ�ֱ���	
		�ɶ�Ψһ�ĸ�����ӳ��map	
		*/
		int father = findFather(members[i].id);
		root.insert(father);	 //��¼�����������vector
		ans[father].id = father; //����structĬ��Ԫ��ֵΪ0
		ans[father].area += members[i].area;
		ans[father].sets += members[i].sets;
	}
	for (int i = 0; i < maxn; i++)
		ans[findFather(i)].num++; //ͳ�Ƽ���Ԫ�ظ����������������鼯
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