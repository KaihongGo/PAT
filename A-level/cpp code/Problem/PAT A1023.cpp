//PAT A1023.cpp 1023 Have Fun with Numbers (20 分)
//大整数运算

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

struct bign
{//整数高位存储在数组的高位，整数的低位存储在数组的低位
	int d[1000];
	int len;
	bign() {
		memset(d, 0, sizeof(d));
		len = 0;
	}
	
};

bign change(char str[])
{
	bign a;
	a.len = strlen(str);
	for (int i = 0; i < a.len; i++)
		a.d[i] = str[a.len - i - 1] - '0';//逆着赋值
	return a;
}

bign add(bign a, bign b)
{
	bign c;
	int carry = 0;//carry是进位
	for (int i = 0; i < a.len || i < b.len; i++)
	{	//以较长的为界限
		int temp = a.d[i] + b.d[i] + carry;
		c.d[c.len++] = temp % 10;//个位数为该位结果
		carry = temp / 10;	//新的进位
	}
	if (carry != 0)
		c.d[c.len++] = carry;//如果最后进位不为0，则直接赋值给结果的最高为
	return c;
}

int main()
{
	char str[30];
	scanf("%s", str);
	bign a = change(str);
	bign b = add(a, a);
	vector<int> viA(a.d, a.d + a.len);
	vector<int> viB(b.d, b.d + b.len);
	sort(viA.begin(), viA.end());
	sort(viB.begin(), viB.end());
	if (viA == viB)
	{
		printf("Yes\n");
		for (int i = b.len - 1; i >= 0; i--)
			printf("%d",b.d[i]);
		printf("\n");
	}
	else
	{
		printf("No\n");
		for (int i = b.len - 1; i >= 0; i--)
			printf("%d", b.d[i]);
		printf("\n");
	}
		

}