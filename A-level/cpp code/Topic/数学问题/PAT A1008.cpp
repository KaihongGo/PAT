//PAT A1008.cpp 1008 Elevator (20 ·Ö)
//

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{	
	vector<int> floor;
	int n;
	cin >> n;
	floor.resize(n);
	for (int i = 0; i < n; i++)
		cin >> floor[i];
	int pre = 0;
	int time = 0;
	for (int i = 0; i < floor.size(); i++)
	{
		int now = floor[i];
		if (now < pre)
			time += 4 * (pre - now);
		else if(now > pre)
			time += 6 * (now - pre);
		pre = now;
		time += 5;
	}
	printf("%d", time);
}