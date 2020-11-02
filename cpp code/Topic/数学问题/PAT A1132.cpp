//PAT A1132.cpp 1132 Cut Integer (20 ·Ö)
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	string num;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		int len = num.length();
		string str1 = num.substr(0, len/2);
		string str2 = num.substr(len/2);
		int a = stoi(str1);
		int b = stoi(str2);
		int c = stoi(num);
		if (a * b != 0 && c % (a * b) == 0)
			printf("Yes\n");
		else
			printf("No\n");
	}
}