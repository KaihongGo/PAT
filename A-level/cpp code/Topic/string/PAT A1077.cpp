//PAT A1077.cpp 1077 Kuchiguse (20 分)
//常规思路：逐个比较字符；用数组配合长度变量；末尾字符作为比较标志
//柳神先将字符串反序，定第一个串为标准；失败就截取；机智啊！！
//正着不行反着来！
#include <string>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	string str[110];
	int n;
	cin >> n;
	vector<int> len;//长度数组
	getchar();
	for (int i = 0; i < n; i++)
	{
		getline(cin, str[i]);
		len.push_back(str[i].size());
	}
	int minlen = 0x3fffffff;
	for (int i = 0; i < n; i++)
	{
		if (len[i] < minlen)
			minlen = len[i];
	}
	string kuchiguse;
	char temp;
	int index = 0;
	while (index < minlen)
	{
		for (int i = 0; i < n; i++)
		{//遍历所有字符串
			temp = str[n - 1][len[n - 1] - 1];//最后一个字符串 尾
			if (str[i][len[i] - 1] != temp)
				break;	//似乎没有空格处理
			if (i == n - 1)
			{//尾字符串
				kuchiguse += temp;
			}
			len[i]--;//更新长度
		}
		index++;
	}
	reverse(kuchiguse.begin(), kuchiguse.end());//字符串反序
	if (kuchiguse.size() != 0)
		printf("%s", kuchiguse.c_str());
	else
		printf("nai");
}