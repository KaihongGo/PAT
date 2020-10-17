//PAT A1145.cpp 1145 Hashing - Average Search Time (25 分)
//
#include <iostream>
#include <cstdio>
#include <numeric>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 100010;
bool isPrime(int x)
{
	if (x <= 1) return false;
	int sqr = sqrt(x);
	for (int i = 2; i <= sqr; i++) {
		if (x % i == 0)
			return false;
	}
	return true;
}

int main()
{
	int Tsize, n, m;
	cin >> Tsize >> n >> m;
	while (!isPrime(Tsize))
		Tsize++;
	vector<int> hashTable(Tsize);
	for (int i = 0; i < n; i++)
	{
		int key; cin >> key;
		bool flag = false;
		for (int k = 0; k < Tsize; k++)
		{
			int H = (key + k * k) % Tsize;
			if (hashTable[H] == 0)
			{
				hashTable[H] = key;
				flag = true;
				break;
			}
		}
		if (!flag) printf("%d cannot be inserted.\n", key);
	}
	//平均查找长度
	double AST = 0;
	for (int i = 0; i < m; i++)
	{
		int key; cin >> key;
		for (int k = 0; k <= Tsize; k++)
		{
			AST++;
			int H = (key + k * k) % Tsize;
			if (hashTable[H] == key || hashTable[H] == 0) break;
		}
	}
	printf("%.1f\n", AST / m);
	return 0;
}