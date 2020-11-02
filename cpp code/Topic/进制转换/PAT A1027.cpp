//PAT A1027.cpp 1027 Colors in Mars (20 分)
//

#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
	int a[3];
	cin >> a[0] >> a[1] >> a[2];
	vector<int> num[3];
	for (int i = 0; i < 3; i++)
	for (int i = 0; i < 3; i++)
	{
		do {
			num[i].push_back(a[i] % 13);
			a[i] = a[i] / 13;
		} while (a[i] != 0);
	}
	for (int i = 0; i < 3; i++)
	{
		num[i].resize(2);
		reverse(num[i].begin(), num[i].end());//高位在前
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < num[i].size(); j++)
		{
			switch (num[i][j])
			{
			case 10:
				num[i][j] = 'A'; break;
			case 11:
				num[i][j] = 'B'; break;
			case 12:
				num[i][j] = 'C'; break;
			default:
				num[i][j] += '0';
				break;
			}
		}
	}
	printf("#");
	for (int i = 0; i < 3; i++)
	{
		printf("%c%c", num[i][0], num[i][1]);
	}

	return 0;
}