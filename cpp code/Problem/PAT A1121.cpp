//PAT A1121.cpp 1121 Damn Single (25 ��)
//һ�����Ե�δͨ����ԭ��δ֪??? %05d���⣻�ú����⣡
//����˼·������setȥ��
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
	int n, k;//������k query��
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
	{//�������з�
		if (st.find(couple[0][i]) != st.end() && st.find(couple[1][i]) != st.end())
		{	//�ҵ��ˣ�ɾ��
			st.erase(couple[0][i]);
			st.erase(couple[1][i]);
		}
	}
	printf("%d\n", st.size());
	int cnt = 0;
	for (auto it = st.begin(); it != st.end(); it++)
	{
		printf("%05d", *it);
		cnt++;//�������
		if (cnt != st.size()) printf(" ");
		else printf("\n");
	}

}