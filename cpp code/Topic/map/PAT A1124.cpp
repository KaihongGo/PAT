//PAT A1124.cpp 1124 Raffle for Weibo Followers (20 ·Ö)
//

#include <iostream>
#include <cstdio>
#include <map>
#include <string>
using namespace std;

int main()
{
	int m, n, s;
	cin >> m >> n >> s;
	map<string, bool> selected;
	string person[1100];
	for (int i = 1; i <= m; i++)
	{
		cin >> person[i];
		selected[person[i]] = false;
	}
	int i = s;
	bool flag = false;
	while (i <= m)
	{
		flag = true;
		if (selected[person[i]] == false)
		{
			selected[person[i]] = true;
			cout << person[i] << endl;
			i += n;
		}
		else
		{
			i = i + 1;
		}
	}
	if (flag == false)
	{
		printf("Keep going...\n");
	}
}
