//PAT A1084.cpp 1084 Broken Keyboard (20 分)
//

#include <string>
#include <iostream>
#include <cctype>
using namespace std;

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	int flag[256] = { 0 };
	
	for (int i = 0; i < s2.size(); i++)
	{
		s2[i] = toupper(s2[i]);	//统统大写
		flag[s2[i]]++;
	}
	for (int i = 0; i < s1.size(); i++)
	{
		s1[i] = toupper(s1[i]);
		if (flag[s1[i]] == 0)
		{
			flag[s1[i]]++;
			cout << s1[i];
		}
	}
}