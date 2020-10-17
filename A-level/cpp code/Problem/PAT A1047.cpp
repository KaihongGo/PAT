//PAT A1047.cpp 1047 Student List for Course (25 ·Ö)
//

#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<string> >vi;

int main()
{
	int n, k, c;
	scanf("%d %d", &n, &k);
	vi.resize(k + 1);
	string name;
	int course;

	for (int i = 0; i < n; i++)
	{
		cin >> name >> c;
		while (c--)
		{
			scanf("%d", &course);
			vi[course].push_back(name);
		}
	}
	
	for (int i = 1; i <= k; i++)
	{
		sort(vi[i].begin(), vi[i].end());
		printf("%d %d\n", i, vi[i].size());
		for (int j = 0; j < vi[i].size(); j++)
		{
			printf("%s\n", vi[i][j].c_str());
			//cout << vi[i][j] << endl;
		}
	}

	return 0;
}