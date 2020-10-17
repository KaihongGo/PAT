//PAT A1112.cpp 1112 Stucked Keyboard (20 分)
//始终两个测试点未过，原因：逻辑问题

#include <string>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
	int k;
	string str;
	cin >> k >> str;
	str = str + '#';
	int len = str.length();
	char pre = str[0];
	int cnt = 1;
	map<char, bool> NoBroken;
	for (int i = 1; i < len; i++)
	{	//这样无法统计最后一个
		if (str[i] == pre)
			cnt++;
		else
		{
			if (cnt % k != 0)//只要不是坏的，就不是坏的
				NoBroken[pre] = true;
			pre = str[i];
			cnt = 1;
		}
	}
	len = len - 1;
	map<char, bool> printed;
	for (int i = 0; i < len; i++)
	{
		if (!NoBroken[str[i]] && !printed[str[i]])
		{		
			printf("%c", str[i]);
			printed[str[i]] = true;
		}
	}
	printf("\n");
	for (int i = 0; i < len; i++)
	{
		printf("%c", str[i]);
		if (!NoBroken[str[i]])
		{
			i = i + k - 1;
		}
	}
}