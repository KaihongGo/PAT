//PAT A1024.cpp 1024 Palindromic Number (25 分)
//大整数相加
//两个测试点未通过，具体原因未知
//判断顺序出错！！！
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> add(vector<int> a, vector<int> b)
{
	vector<int> c;
	int carry = 0;
	for (int i = 0; i < a.size() || i < b.size(); i++)
	{
		int temp = a[i] + b[i] + carry;
		carry = temp / 10;
		c.push_back(temp % 10);
	}
	if (carry != 0)
		c.push_back(carry);
	return c;
}

int main()
{
	string n;
	int k;
	cin >> n >> k;
	vector<int> num;
	for (int i = n.size() - 1; i >= 0; i--)
		num.push_back(n[i]-'0');

	int cnt = -1;//记录次数
	vector<int> a = num;
	vector<int> b;
	for (int i  = 0; i < k; i++)
	{
		b = a;
		reverse(b.begin(), b.end());
		if (a == b)
		{//自己得理理这里判断逻辑
			cnt = i;
			break;
		}
		a = add(a, b);
	}
	for (int i = a.size() - 1; i >= 0; i--)
		printf("%d", a[i]);
	if (cnt != -1)
		printf("\n%d\n", cnt);
	else
		printf("\n%d\n", k);
}