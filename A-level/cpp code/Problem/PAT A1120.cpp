//PAT A1120.cpp 1120 Friend Numbers (20 分)
//
#include <cstdio>
#include <set>
#include <vector>
#include <cstring>
using namespace std;

int fiendID(char num[])
{
	int n = strlen(num);
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans += (num[i] - '0');
	}
	return ans;
}

int main()
{
	char num[6];
	int n;
	set<int> st;
	vector<int> vi;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", num);
		int frID = fiendID(num);
		st.insert(frID);
	}
	printf("%d\n", st.size());
	//set访问受限，用vector控制输出
	for (auto it = st.begin(); it != st.end(); it++)
	{
		vi.push_back(*it);
	}
	for (auto it = vi.begin(); it != vi.end(); it++)
	{
		printf("%d", *it);
		if (it != vi.end() - 1)
			printf(" ");
	}
}