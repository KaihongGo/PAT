//PAT A1139.cpp 1139 First Contact (30 ��)
//����set��������ǰ������������
//const�������峣ֵ

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;

const int boy = 1;
const int girl = 0;
const int maxn = 10010;

struct Person
{
	int id;
	int gender;//1,boy; 0,girl;
	friend bool operator < (Person a, Person b)
	{	//�������Ѱ���id����
		return a.id < b.id;
	}
};
//����set������
set<Person> frien[maxn];
Person convert(string str)
{//���ַ���ת��Ϊ���
	Person a;
	if (str[0] == '-') {
		a.gender = girl;
		str.erase(str.begin());
	}
	else a.gender = boy;
	a.id = stoi(str);
	return a;
}

int main()
{
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		string s1, s2; cin >> s1 >> s2;
		Person a, b;
		a = convert(s1);
		b = convert(s2);
		//���a����,b;
		frien[a.id].insert(b);
		//���b����, a
		frien[b.id].insert(a);
	}
	int k; cin >> k;
	for (int i = 0; i < k; i++)
	{	// k queries
		string s1, s2; cin >> s1 >> s2;
		Person a, b;
		a = convert(s1);
		b = convert(s2);
		int cnt = 0; 
		vector<string> ans;
		for (auto afrien = frien[a.id].begin(); afrien != frien[a.id].end(); afrien++)
		{	//����a������
			if (afrien->gender != a.gender) continue;//������ͬ�Ա�
			else if (afrien->id == b.id) continue;	//�����ҵ�b
			else
			{	//����a���ѵ����ѣ������Ա���b�Ƿ���ͬ������Ϊb������
				for (auto aff = frien[afrien->id].begin(); aff != frien[afrien->id].end(); aff++)
				{
					if (aff->id == a.id) continue;	//����a
					if (aff->gender == b.gender && frien[b.id].find(*aff) != frien[b.id].end())
					{	//�ַ�����vectorƴ�Ӵ�
						cnt++;
						char str[100];
						sprintf(str,"%04d %04d\n", afrien->id, aff->id);
						ans.push_back(str);
					}
				}
			}
		}
		cout << ans.size() << endl;
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i];
	}
}