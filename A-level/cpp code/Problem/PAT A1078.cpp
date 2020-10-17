// PAT A1078.cpp 1078 Hashing (25 ·Ö)
//
#include <vector>
#include <cmath>
#include <iostream>
#include <cstdio>
using namespace std;
bool isPrime(int x)
{
	if (x <= 1) return false;
	int sqr = sqrt(x);
	for (int i = 2; i <= sqr; i++)
	{
		if (x % i == 0) return false;
	}
	return true;
}
int Tsize, n;
int main()
{
	cin >> Tsize >> n;
	while (!isPrime(Tsize))
		Tsize++;
	vector<int> hashTable(Tsize);
	for (int i = 0; i < n; i++)
	{
		int key; cin >> key;
		bool flag = false; 
		int H;
		for (int j = 0; j < Tsize; j++)
		{
			H = (key + j * j) % Tsize;
			if (hashTable[H] == 0)
			{
				hashTable[H] = key;
				flag = true;
				break;
			}
		}
		if (flag == false) printf("-");
		else printf("%d", H % Tsize);
		if (i != n - 1)printf(" ");
		else printf("\n");
	}
	printf("\n");
}