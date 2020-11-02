//PAT A1121.cpp 1121 Damn Single (25 分)
//一个测试点未通过？原因未知??? %05d问题；好好审题！
//基本思路：利用set去重
#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
const int maxn = 100010;

int couple[2][maxn];
int main()
{
	set<int> st;
	int n, k;//人数，k query；
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> couple[0][i] >> couple[1][i];
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int person;
		cin >> person;
		st.insert(person);
	}
	for (int i = 0; i < n; i++)
	{//遍历所有夫妇
		if (st.find(couple[0][i]) != st.end() && st.find(couple[1][i]) != st.end())
		{	//找到了，删除
			st.erase(couple[0][i]);
			st.erase(couple[1][i]);
		}
	}
	printf("%d\n", st.size());
	int cnt = 0;
	for (auto it = st.begin(); it != st.end(); it++)
	{
		printf("%05d", *it);
		cnt++;//输出控制
		if (cnt != st.size()) printf(" ");
		else printf("\n");
	}

}