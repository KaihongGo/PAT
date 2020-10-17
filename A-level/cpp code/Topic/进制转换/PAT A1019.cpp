//PAT A1019.cpp 1019 General Palindromic Number (20 ·Ö)
//????????
#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int n, base;
	cin >> n >> base;
	vector<int> num;
	do {
		num.push_back(n % base);
		n /= base;
	} while (n != 0);
	vector<int> rnum = num;
	reverse(rnum.begin(), rnum.end());
	printf("%s\n",rnum == num ? "Yes":"No");
	for (int i = 0; i < rnum.size(); i++)
	{
		printf("%d", rnum[i]);
		if (i < rnum.size() - 1) printf(" ");
	}
}