//PAT A1112.cpp 1112 Stucked Keyboard (20 ��)
//ʼ���������Ե�δ����ԭ���߼�����

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
	{	//�����޷�ͳ�����һ��
		if (str[i] == pre)
			cnt++;
		else
		{
			if (cnt % k != 0)//ֻҪ���ǻ��ģ��Ͳ��ǻ���
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