//PAT A1023.cpp 1023 Have Fun with Numbers (20 ��)
//����������

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

struct bign
{//������λ�洢������ĸ�λ�������ĵ�λ�洢������ĵ�λ
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
		a.d[i] = str[a.len - i - 1] - '0';//���Ÿ�ֵ
	return a;
}

bign add(bign a, bign b)
{
	bign c;
	int carry = 0;//carry�ǽ�λ
	for (int i = 0; i < a.len || i < b.len; i++)
	{	//�Խϳ���Ϊ����
		int temp = a.d[i] + b.d[i] + carry;
		c.d[c.len++] = temp % 10;//��λ��Ϊ��λ���
		carry = temp / 10;	//�µĽ�λ
	}
	if (carry != 0)
		c.d[c.len++] = carry;//�������λ��Ϊ0����ֱ�Ӹ�ֵ����������Ϊ
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