//PAT A1022.cpp 1022 Digital Library (30 分)
//代码逻辑冗余，使用了map<string, vector>作为查找；注意keyword，string查找子串；可用set优化
//仍有两个测试点未过！！！查找利用map建立类目
//原因：对于一切 `ID` 是`7-digit number as its ID` 记得输出`printf("%07d", );`填充！教训

#include <map>
#include <string>
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

map<string, vector<int> > mp[5];	//0开始
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
				{	//是key的子串; 搜寻子串；
					for (int i = 0; i < it->second.size(); i++)
					{//st处理,加入set
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
		{//对应条目有数据，排序
			sort(mp[formart - 1][item].begin(), mp[formart - 1][item].end());
			for (auto it = mp[formart - 1][item].begin(); it != mp[formart - 1][item].end(); it++) 
				printf("%07d\n", *it);
		}
		else
			printf("Not Found\n");
	}
}
