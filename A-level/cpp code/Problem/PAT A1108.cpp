//PAT A1108.cpp 1108 Finding Average (20 分)
//

#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cstdio>
using namespace std;


bool legal(string str)
{	
	int len = str.size();
	if(str[0]!='-' && !isdigit(str[0]))//此处条件短路
		return false;
	int cnt = 0;
	for (int i = 1; i < len; i++)
	{
		if(!isdigit(str[i]) && str[i]!='.')
			return false;
		if (str[i] == '.')
			cnt++;
	}
	if (cnt > 1)
		return false;
	else if (cnt == 1)
	{
		if (str.find('.') + 1 < len - 2)
			return false;
	}
	if (atof(str.c_str()) < -1000 || atof(str.c_str()) > 1000)
		return false;
	return true;
}

int main()
{	
	int n;
	string str[110];
	scanf("%d", &n);
	double sum = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> str[i];
		if (legal(str[i]))
		{
			sum += atof(str[i].c_str());
			cnt++;
		}
		else
			printf("ERROR: %s is not a legal number\n", str[i].c_str());
	}
	if (cnt == 0)
	{
		printf("The average of 0 numbers is Undefined\n");
	}
	else if (cnt == 1)
		printf("The average of 1 number is %.2lf\n", sum / cnt);
	else 
		printf("The average of %d numbers is %.2lf\n", cnt, sum/cnt);
}