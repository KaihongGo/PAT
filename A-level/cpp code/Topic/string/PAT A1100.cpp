//PAT A1100.cpp Mars Numbers
//常规字符串处理，用数组下标建立映射，substr用法
#include <iostream>
#include <cstdio>
#include <string>
#include <cctype>
using namespace std;

string low[] = { "tret" ,"jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
string high[] = {"", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };

int func(string s)
{
	for (int i = 0; i < 13; i++) {
		if (low[i] == s)
			return i;
	}
	for (int i = 0; i < 13; i++) {
		if (high[i] == s)
			return i * 13;
	}
}

int main()
{
	int n; cin >> n;//cin保留了换行
	getchar();
	while (n--)
	{
		string str; getline(cin, str);
		if (isdigit(str[0]))
		{
			int num = stoi(str);
			if (num / 13 != 0)
			{
				cout << high[num / 13];
				if (num % 13 != 0)
					cout << " " << low[num % 13];
				cout << endl;
			}else
				cout << low[num % 13] << endl;
		}
		else
		{
			int find = str.find(' ');
			int num = 0;
			if (find == -1)
				num = func(str);
			else
			{
				num = func(str.substr(find + 1));
				num += func(str.substr(0, find));
			}
			cout << num << endl;
			
		}
	}
}