//PAT A1140.cpp 1140 Look-and-say Sequence (20 分)
//
#include <string>
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

string nextSeq(string str)
{
	string ans;
	int len = str.size();
	char pre = str[0];
	int cnt = 0;
	for (int i = 0; i < len; i++)
	{
		if (str[i] == pre)
			cnt++;
		else
		{//遇到新组
			ans += pre;
			ans += (cnt + '0');
			pre = str[i];
			cnt = 0;//恢复
			i--;
		}
	}
	ans += pre;
	ans += (cnt + '0');
	return ans;
}

int main()
{
	string str;
	int n;
	cin >> str >> n;
	for (int i = 1; i < n; i++)
		str = nextSeq(str);
	printf("%s\n", str.c_str());
}