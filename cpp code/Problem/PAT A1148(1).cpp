//PAT A1148.cpp 
//for every two wolf, traverse all possible answer;

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

const int maxn = 110;
bool liar[maxn];	//who is liar;
vector<vector<int> > vi;//possible answer

struct Node
{
	int wolf;	//1, werewolf; 0, human;
	int player; //
} judge[maxn];

int main()
{
	int n = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		string a;
		cin >> a;
		if (a[0] == '-')
		{//wolf
			a.erase(a.begin());
			judge[i].player = stoi(a);
			judge[i].wolf = 1;
		}
		else
		{//human
			judge[i].player = stoi(a);
			judge[i].wolf = 0;
		}
	}
	
	for (int i = 1; i <= n; i++)
	{	// i is a wolf
		for (int j = i + 1; j <= n; j++)
		{	//j is a wolf
			vector<int> wolf;
			wolf.clear();
			wolf.resize(n + 1, 0);
			wolf[i] = 1;
			wolf[j] = 1;
			
			int cntliar = 0;
			int wolfliar = 0;
			for (int k = 1; k <= n; k++)
			{
				int p = judge[k].player;
				if (wolf[p] != judge[k].wolf)
				{	//k is a liar
					if (wolf[k] == true) //k is a liar and wolf
						wolfliar++;
					cntliar++;
				}
			}
			
			bool flag = true;
			if (cntliar != 2 || wolfliar != 1) flag = false;
			if (flag == true)
				vi.push_back(wolf);
		}
	}
	if (vi.size() == 0)
		printf("No Solution\n");
	else
	{
		int spacecnt = 0;
		for (int j = 1; j <= n; j++)
		{
			if (vi[0][j] == 1)
			{
				cout << j;
				spacecnt++;
				if (spacecnt != 2)
					cout << " ";
			}
		}
		cout << endl;
	}
}
