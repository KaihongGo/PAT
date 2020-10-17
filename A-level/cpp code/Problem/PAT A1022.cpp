//PAT A1022.cpp 1022 Digital Library (30 ��)
//�����߼����࣬ʹ����map<string, vector>��Ϊ���ң�ע��keyword��string�����Ӵ�������set�Ż�
//�����������Ե�δ����������������map������Ŀ
//ԭ�򣺶���һ�� `ID` ��`7-digit number as its ID` �ǵ����`printf("%07d", );`��䣡��ѵ

#include <map>
#include <string>
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

map<string, vector<int> > mp[5];	//0��ʼ
int main()
{
	int n, m;
	scanf("%d", &n);
	int id;
	string title, author, keyWord, pub, pubyear;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &id);
		getchar();
		getline(cin, title);
		getline(cin, author);
		//keyword: a keyword
		getline(cin, keyWord);
		getline(cin, pub);
		getline(cin, pubyear);

		mp[0][title].push_back(id);
		mp[1][author].push_back(id);
		mp[2][keyWord].push_back(id);
		mp[3][pub].push_back(id);
		mp[4][pubyear].push_back(id);
	}
	scanf("%d", &m);
	int formart;
	string item;
	for (int i = 0; i < m; i++)
	{
		scanf("%d: ", &formart);
		getline(cin, item);
		printf("%d: %s\n", formart, item.c_str());
		if (formart == 3)
		{	//a key word
			set<int> st;
			for (auto it = mp[formart - 1].begin(); it != mp[formart - 1].end(); it++)
			{
				if (it->first.find(item) != string::npos)
				{	//��key���Ӵ�; ��Ѱ�Ӵ���
					for (int i = 0; i < it->second.size(); i++)
					{//st����,����set
						st.insert(it->second[i]);
					}
				}
			}
			if (st.size() != 0) {
				for (auto it = st.begin(); it != st.end(); it++)
					printf("%07d\n", *it);
			}
			else
				printf("Not Found\n");
			
		}
		else if (mp[formart - 1][item].size() != 0)
		{//��Ӧ��Ŀ�����ݣ�����
			sort(mp[formart - 1][item].begin(), mp[formart - 1][item].end());
			for (auto it = mp[formart - 1][item].begin(); it != mp[formart - 1][item].end(); it++) 
				printf("%07d\n", *it);
		}
		else
			printf("Not Found\n");
	}
}
