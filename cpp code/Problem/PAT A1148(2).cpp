//PAT A1148.cpp 1148 Werewolf - Simple Version (20 ·Ö)
//

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;
const int maxn = 110;

struct Node
{
	int flag; // 1, wolf; 0, human; 
	int person;
} say[maxn];

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		say[i].person = abs(a);
		if (a < 0)	//wolf
			say[i].flag = 1;
		else//human
			say[i].flag = 0;
	}
	for (int i = 1; i <= n; i++)
	{	//for every possible answer
		for (int j = i + 1; j <= n; j++)
		{	//i, j is wolf
			vector<int> tempAns;
			tempAns.clear();
			tempAns.resize(n + 1);
			
			tempAns[i] = 1;
			tempAns[j] = 1;
			
			int cntliar = 0, wolfliar = 0;
			for (int k = 1; k <= n; k++)
			{
				int id = say[k].person;
				if (say[k].flag != tempAns[id])
				{	//k is a liar
					cntliar++;
					if (tempAns[k] == 1)
						wolfliar++;//k is a wolfliar
				}
	   		}
			bool ansflag = true;
			if (cntliar != 2 || wolfliar != 1)
				ansflag = false;
			if (ansflag == true)
			{	// true ans
				int cntspace = 0;
				for (int k = 1; k <= n; k++)
				{
					if (tempAns[k] == 1)
					{
						printf("%d", k);
						cntspace++;
						if (cntspace != 2)
							printf(" ");
					}
				}
				return 0;
			}
		}
	}
	printf("No Solution\n");
	return 0;
}