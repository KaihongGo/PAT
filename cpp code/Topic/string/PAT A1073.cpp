//PAT A1073.cpp 1073 Scientific Notation (20 分)
//

//+1.23400E-03
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
	string str;
	cin >> str;
	if (str[0] == '-') printf("-");

	int pos = str.find('E');
	string front = str.substr(1, pos - 1);//略去符号位置
	int exp = stoi(str.substr(pos + 1));

	if (exp < 0)
	{
		int dot = front.find('.');//del dor
		front.erase(front.begin() + dot);

		front.insert(0, abs(exp), '0');//insert 0
		front.insert(front.begin() + 1, '.');//插入	
		printf("%s\n", front.c_str());
	}
	else
	{
		cout << front[0];
		int cnt = 0, i = 0;
		for (i = 2; i < front.size() && cnt < exp; i++, cnt++)
			printf("%c", front[i]);
		if (i == front.size())
		{
			for (int j = 0; j < exp - cnt; j++)
				printf("0");
		}
		else
		{
			printf(".");
			for (int j = i; j < front.size(); j++)
				printf("%c", front[j]);
		}
	}
}
