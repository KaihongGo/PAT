//PAT A1061.cpp 1061 Dating (20 ��)
//������֣������������Ǵ�д��ĸ������

#include <string>
#include <cstdio>
#include <iostream>
#include <cctype>
#include <algorithm>
using namespace std;

const string DAY[8] = {"MON","TUE", "WED","THU" ,"FRI","SAT", "SUN" };//ʹ��0���±�
const string HOUR = { "0123456789ABCDEFGHIJKLMN" };//ʹ��0�±�
int main()
{
	string str[4];
	for (int i = 0; i < 4; i++)
		cin >> str[i];
	//�������DAY
	int index = 0;
	while (index < str[0].size() && index < str[1].size())
	{
		if (str[0][index] == str[1][index] && (str[0][index] >= 'A' && str[0][index] <= 'G'))
			break;
		index++;
	}
	int day = str[0][index] - 'A';
	//��ȡ����
	index++;
	while (index < str[0].size() && index < str[1].size())
	{
		if (str[0][index] == str[1][index] && ((str[0][index] >= 'A' && str[0][index] <= 'N') || isdigit(str[0][index])))
			break;
		index++;
	}
	int hour = 0;
	for (int i = 0; i < 24; i++)
	{
		if (HOUR[i] == str[0][index])
		{
			hour = i;
			break;
		}
	}
	//��ȡ����
	index = 0;
	while (index < str[2].size() && index < str[3].size())
	{
		if (str[2][index] == str[3][index] && isalpha(str[2][index]))
			break;
		index++;
	}
	int minute = index;
	printf("%s %02d:%02d",DAY[day].c_str(), hour, minute);


}