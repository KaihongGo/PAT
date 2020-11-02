//PAT A1041.cpp 1041 Be Unique (20 ·Ö)
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 100010;
const int INF = 0x3fffffff;
int hashTable[MAXN] = { 0 };

int main()
{
	vector<int> vi;
	int n;
	cin >> n;
	vi.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> vi[i];
		hashTable[vi[i]]++;
	}
	for (int i = 0; i < n; i++)
	{
		int key = vi[i];
		if (hashTable[key] == 1)
		{
			printf("%d", key);
			return 0;
		}
	}
	printf("None");
	return 0;

}