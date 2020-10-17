//PAT A1148.cpp 1148 Werewolf - Simple Version (20 分)
//基本策略：指定两个撒谎者；枚举所有情况；不好！！！！！
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
	int flag;	//1, werewolf; -1, human; 0, nothing
	int judegePlayer; //
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
			judge[i].judegePlayer = stoi(a);
			judge[i].flag = 1;
		}
		else
		{//human
			judge[i].judegePlayer = stoi(a);
			judge[i].flag = -1;
		}
	}
	//liar
	for (int iliar = 1; iliar <= n; iliar++)
	{
		vector<int> tempAns;
		tempAns.resize(n+1);
		int jliar = iliar + 1;
		
		for (; jliar <= n; jliar++)
		{	//i is a liar
			if (judge[iliar].judegePlayer != judge[jliar].judegePlayer)
			{
				if (judge[iliar].flag == 1)
					tempAns[judge[iliar].judegePlayer] = -1;
				else if (judge[iliar].flag == -1)
					tempAns[judge[iliar].judegePlayer] = 1;
				//j is liar
				if (judge[jliar].flag == 1)
					tempAns[judge[jliar].judegePlayer] = -1;
				else if (judge[jliar].flag == -1)
					tempAns[judge[jliar].judegePlayer] = 1;
			}
			for (int k = 1; k <= n; k++)
			{	//not a liar
				if (k != iliar && k != jliar)
				{
					tempAns[judge[k].judegePlayer] = judge[k].flag;
				}
			}
			int cntwolf = 0, cntwolfliar = 0;
			bool rightflag = true;
			for (int j = 1; j <= n; j++)
			{
				if (tempAns[j] == 1)
				{
					cntwolf++;
					if (j == iliar || j == jliar)
						cntwolfliar++;
				}
			}
			if (cntwolf != 2) rightflag = false;
			//if (cntwolfliar != 1) rightflag = false;
			if (rightflag == true)
				vi.push_back(tempAns);
		}
	}
	for (int i = 0; i < vi.size(); i++)
	{
		for (int j = 1; j <= n; j++)
			cout << vi[i][j] <<" ";
		cout << endl;
	}
}