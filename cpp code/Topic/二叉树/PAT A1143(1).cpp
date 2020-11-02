//PAT A1143.cpp 1143 Lowest Common Ancestor (30 ·Ö)
//
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

vector<int> preBST;
set<int> inBST;

int main()
{
	int m, n;
	cin >> m >> n;
	for (int i = 0; i < n; i++)
	{
		int a; cin >> a;
		preBST.push_back(a);
		inBST.insert(a);
	}
	
	for (int i = 0; i < m; i++)
	{
		int u, v; cin >> u >> v;
		auto findu = inBST.find(u);
		auto findv = inBST.find(v);
		if (findu == inBST.end() && findv == inBST.end())
			printf("ERROR: %d and %d are not found.\n", u, v);
		else if (findu == inBST.end() && findv != inBST.end())
			printf("ERROR: %d is not found.\n", u);
		else if(findu != inBST.end() && findv == inBST.end())
			printf("ERROR: %d is not found.\n", v);
		else
		{
			int j = 0;
			for ( ; j < n; j++)
			{
				if ((preBST[j] >= u && preBST[j] <= v) || (preBST[j] >= v && preBST[j] <= u))
					break;
			}
			if (preBST[j] == u) printf("%d is an ancestor of %d.\n", u, v);
			else if (preBST[j] == v) printf("%d is an ancestor of %d.\n", v, u);
			else
				printf("LCA of %d and %d is %d.\n", u, v, preBST[j]);
		}
	}
}