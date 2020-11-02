//PAT A1138.cpp 1138 Postorder Traversal (25 ·Ö)
//??????????????flag???
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector<int> pre, in, post;

bool flag = false;
void toPost(int preL, int preR, int inL, int inR)
{
	if (preL > preR || flag == true) return ;
	int k = 0;
	while (in[k] != pre[preL]) k++;
	int leftnum = k - inL;
	toPost(preL + 1, preL + leftnum, inL, k - 1);
	toPost(preL + leftnum + 1, preR, k + 1, inR);
	if (flag == false)
	{
		cout << pre[preL];
		flag = true;
	}
	return;
}

int main()
{
	int n; cin >> n;
	pre.resize(n);
	in.resize(n);
	for (int i = 0; i < n; i++)
		cin >> pre[i];
	for (int i = 0; i < n; i++)
		cin >> in[i];
	toPost(0, n - 1, 0, n - 1);
}