//PAT A1065.cpp 1065 A+B and C (64bit) (20 分)
//大整数怎么看都不对

#include <climits>
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

const int MAXN = 1000;

struct bign
{
	bool sign = true;	//符号位，正数0 为true
	int num[MAXN] = { 0 };
	int n = 0;
};

int compare(bign a, bign b)
{	//1 > ; 0 = ; -1 <;
	if (a.sign < b.sign) return -1;
	else if (a.sign > b.sign) return 1;
	else
	{
		if (a.sign == false)
		{//两个都是负数
			swap(a, b);
		}
		else
		{	//两个都是正数
			if (a.n < b.n) return -1;
			else if (a.n > b.n) return 1;
			else
			{
				for (int i = a.n-1	; i >=0; i--)
				{	//高位开始枚举
					if (a.num[i] < b.num[i])
						return -1;
					else if (a.num[i] > b.num[i])
						return 1;
				}
				return 0;
			}
		}
	}
}

bign change(string str)
{	
	bign a;
	if (str[0] == '-')
	{
		a.sign = false;
		str.erase(str.begin());
	}
	for (int i = str.size() - 1; i >= 0; i--)
		a.num[a.n++] = str[i] - '0';
	return a;
}

bign add(bign a, bign b)
{
	bign c;
	int carry = 0;
	for (int i = 0; i < a.n || i < b.n; i++)
	{	//最长的为准
		int temp = a.num[i] + b.num[i] + carry;
		carry = temp / 10;
		c.num[c.n++] = temp % 10;
	}
	if (carry != 0)
		c.num[c.n++] = carry;
	return c;
}

bign sub(bign a, bign b)
{
	bign c;
	
	for (int i = 0; i < a.n || i < b.n; i++)
	{
		if (a.num[i] < b.num[i])
		{	//不够减
			a.num[i + 1]--;
			a.num[i] = 10 + a.num[i];
		}
		c.num[c.n++] = a.num[i] - b.num[i];
	}
	while (c.n > 1 && c.num[c.n-1] == 0)
		c.n--;
	return c;
}

int main()
{

	string s1, s2;
	while (cin >> s1 >> s2)
	{
		bign a = change(s1);
		bign b = change(s2);
		for (int i = c.n - 1; i >= 0; i--)
		cout << c.num[i];
	}
	

}