//PAT A1035.cpp 1035 Password (20 分)
//字符串，查找替换
//这道题告诉我们好好审题
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

char a[6] = { '1','0','l','O' };
char b[6] = { '@','%','L','o' };

struct node
{
	string name, password;
	bool flag = false;
} stu[1010];

bool myRepalce(string &str)
{	//若替换返回true
	bool flag = false;
	for (int i = 0; i < 4; i++)
	{
		int found = str.find(a[i]);
		while (found != string::npos)
		{
			str[found] = b[i];
			found = str.find(a[i], found + 1);
			flag = true;
		}
	}
	return flag;
}

int main()
{
	int n;
	scanf("%d", &n);
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> stu[i].name >> stu[i].password;
		stu[i].flag = myRepalce(stu[i].password);
		if (stu[i].flag == true) cnt++;	//这些人换了
	}
	if (cnt != 0)
		printf("%d\n", cnt);
	for (int i = 0; i < n; i++)
	{
		if (stu[i].flag == true)
			printf("%s %s\n", stu[i].name.c_str(), stu[i].password.c_str());
	}
	if (n == 1 && cnt == 0)//服了！！！，单复数
		printf("There is 1 account and no account is modified\n");
	else if (cnt == 0 && n != 1)
		printf("There are %d accounts and no account is modified\n", n);
}
