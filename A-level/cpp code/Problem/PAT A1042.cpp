//PAT A1042.cpp 1042 Shuffling Machine (20 ·Ö)
//

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
	vector<int> card;
	card.resize(55);
	for (int i = 1; i <= 54; i++) //·¢ÅÆ
		card[i] = i;
	int order[55];
	int n;
	cin >> n;
	for (int i = 1; i <= 54; i++)
		cin >> order[i];
	for (int i = 0; i < n; i++)
	{	//Ï´ÅÆn´Î
		vector<int> temp;
		temp.resize(55);
		for (int i = 1; i <= 54; i++)
		{
			temp[order[i]] = card[i];
		}
		card = temp;
	}
	char alpha[5] = { 'S','H','C','D','J' };
	for (int i = 1; i <= 54; i++)
	{
		int high = card[i] / 13;
		int low = card[i] % 13;
		if (low != 0)
		{
			printf("%c", alpha[high]);
			printf("%d", low);
		}
		else if (low == 0)
		{
			printf("%c", alpha[high - 1]);
			printf("13");
		}
		if (i != 54)
			printf(" ");
	}
}