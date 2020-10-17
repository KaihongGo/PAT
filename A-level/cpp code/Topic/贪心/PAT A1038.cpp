//PAT A1038.cpp 1038 Recover the Smallest Number (30 ��)
//��˼·��һ�����Ե�δ����ԭ��δ֪

#include <iostream>
#include <cstdio>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
	string num;
	int flag;//��������ָ���
};
vector<Node> seg;

bool cmpless(Node a, Node b)
{
	return a.num < b.num;
}

int main()
{
	int n; cin >> n;
	seg.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> seg[i].num;
		char ch = seg[i].num[0];
		while (seg[i].num.size() <= 8)
		{	//���λ�ã���ͬ������һ�鴦��
			seg[i].num.push_back(ch);
			seg[i].flag++;
		}
	}
	sort(seg.begin(), seg.end(), cmpless);
	string ans;
	for (int i = 0; i < n; i++)
	{	//ɾ�����
		while (seg[i].flag != 0)
		{
			seg[i].num.pop_back();
			seg[i].flag--;
		}
		ans += seg[i].num;
	}
	while (ans.size() != 0 && ans[0] == '0')
	{
		ans.erase(ans.begin());
	}
	if (ans.size() == 0) cout << 0;
	else
		cout << ans;
}