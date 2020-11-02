//PAT A1092.cpp 1092 To Buy or Not to Buy (20 ·Ö)
//

#include <string>
#include <iostream>
using namespace std;

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	int flag[256] = { 0 };
	for (int i = 0; i < s1.size(); i++)
		flag[s1[i]]++;
	
	int cnt = 0;
	for (int i = 0; i < s2.size(); i++)
	{
		if (flag[s2[i]] == 0)
			cnt++;
		else
			flag[s2[i]]--;
	}
	if (cnt == 0)
		cout << "Yes "<<s1.size() - s2.size();
	else
		cout << "No " << cnt;
}