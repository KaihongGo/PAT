//PAT A1062.cpp 1062 Talent and Virtue (25 分)
//基本思路：输入时按low bound对数据预处理，按规则排序，利用flag标记

#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 100010;

int N, L, H;//low, high;
struct Person
{
	int ID, Virtue, Talent, total;
	int flag;	//1,2,3,4;四级
};
vector<Person> per;

bool cmp(Person a, Person b)
{
	if (a.total != b.total)
	{
		return a.total > b.total;
	}
	else if (a.Virtue != b.Virtue)
		return a.Virtue > b.Virtue;
	else
			return a.ID < b.ID;
}

void outPut(vector<Person> vi, int flag)
{
	for (int i = 0; i < vi.size(); i++)
	{
		if (vi[i].flag == flag)
			printf("%d %d %d\n", vi[i].ID, vi[i].Virtue, vi[i].Talent);
	}
}

int main()
{
	scanf("%d %d %d", &N, &L, &H);
	Person temp;
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d %d", &temp.ID, &temp.Virtue, &temp.Talent);
		temp.total = temp.Virtue + temp.Talent;
		if (temp.Virtue >= L && temp.Talent >= L)
			per.push_back(temp);
	}
	for (int i = 0; i < per.size(); i++)
	{//遍历所有，添加flag
		if (per[i].Virtue >= H && per[i].Talent >= H)
			per[i].flag = 1; //sages
		else if (per[i].Virtue >= H && per[i].Talent < H)
			per[i].flag = 2;//noblemen
		else if (per[i].Virtue < H&& per[i].Talent < H&& per[i].Virtue >= per[i].Talent)
			per[i].flag = 3; //fool men
		else
			per[i].flag = 4;//others;
	}
	sort(per.begin(), per.end(), cmp);
	
	printf("%d\n", per.size());
	for (int i = 1; i <= 4; i++)
	{
		outPut(per, i);
	}
}