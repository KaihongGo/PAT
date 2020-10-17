//PAT A1093.cpp 1093 Count PAT's (25 分)
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
//APPAPT
const int maxn = 100010;
struct Node
{
	int cntP;//左侧P
	int cntT;//右侧T
} PT[maxn];

int main()
{
	string str; cin >> str;
	int cnt = 0;
	for (int i = 1; i < str.size(); i++)
	{//正向遍历，统计一个结点的左侧P
		char prech = str[i - 1];
		if (prech == 'P')
			PT[i].cntP = PT[i - 1].cntP + 1;
		else
			PT[i].cntP = PT[i - 1].cntP;
	}
	for (int i = str.size() - 2; i >= 0; i--)
	{
		char prech = str[i + 1];
		if (prech == 'T')
			PT[i].cntT = PT[i + 1].cntT + 1;
		else
			PT[i].cntT = PT[i + 1].cntT;
	}
	for(int i =0;i<str.size();i++)
	{
		if (str[i] == 'A')
			cnt = (cnt + (PT[i].cntT * PT[i].cntP)) % 1000000007;
	}
	/*size_t findA = str.find('A');
	while (findA!= string::npos)
	{
		int cntP = count(str.begin(), str.begin() + findA, 'P');//记录A左边P
		int cntT = count(str.begin() + findA, str.end(), 'T');
		cnt += (cntP * cntT) % 1000000007;
		findA = str.find('A',findA + 1);
	}
	*/
	printf("%d", cnt);
}