//PAT A1011.cpp 1011 World Cup Betting (20 分)
//调胜率最大的
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<char, double> game[3];

int main()
{
	char buy[3];
	for (int i = 0; i < 3; i++)
	{
		cin >> game[i]['W'] >> game[i]['T'] >> game[i]['L'];
		double maxOdd = 0;
		for (auto it = game[i].begin(); it != game[i].end(); it++)
		{
			if (maxOdd < it->second)
			{
				maxOdd = it->second;
				buy[i] = it->first;
			}
		}
	}
	double profit = (game[0][buy[0]] * game[1][buy[1]] * game[2][buy[2]] * 0.65 - 1) * 2;
	printf("%c %c %c %.2f", buy[0], buy[1], buy[2], profit);
}