//PAT A1144.cpp 1144 The Missing Number (20 ·Ö)
//

#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	map<int, bool> mp;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		if(a > 0)
			mp[a] = true;
	}
	int i = 1;
	while (true)
	{
		if (mp[i] == true)
			i++;
		else
		{
			cout << i;
			break;
		}
	}
}