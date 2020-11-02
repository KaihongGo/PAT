//PAT A1070.cpp 1070 Mooncake (25 ·Ö)
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Cake
{
	double amount;
	double price;
	double unit;
};
bool cmp(Cake a, Cake b)
{
	return a.unit > b.unit;
}
int main()
{
	int n;
	double D; 
	cin >> n >> D;
	vector<Cake> mooncake(n);
	for (int i = 0; i < n; i++)
		cin >> mooncake[i].amount;
	for (int i = 0; i < n; i++)
	{
		cin >> mooncake[i].price;
		mooncake[i].unit = mooncake[i].price / mooncake[i].amount;
	}
	sort(mooncake.begin(), mooncake.end(), cmp);
	double profit = 0;
	for (int i = 0; i < n; i++)
	{
		if (D > mooncake[i].amount)
		{
			D -= mooncake[i].amount;
			profit += mooncake[i].price;
		}
		else
		{
			profit += mooncake[i].unit * D;
			break;
		}
	}
	printf("%.2f\n", profit);
		
}