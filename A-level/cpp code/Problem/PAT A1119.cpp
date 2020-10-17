//PAT A1119.cpp 1119 Pre- and Post-order Traversals (30 ·Ö)
//????????

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> pre;
vector<int> in;
vector<int> post;
bool flag = true;
void toIn(int preL, int preR, int postL, int postR)
{
	if (preL == preR)
	{
		in.push_back(pre[preL]);
		return;
	}
	if (pre[preL] == post[postR])
	{
		int k = preL + 1;
		while (k <= preR && pre[k] != post[postR - 1])
			k++;
		int leftnum = k - preL - 1;
		if (k - preL > 1)
			toIn(preL + 1, k - 1, postL, postL + leftnum - 1);//left tree
		else flag = false;
		in.push_back(post[postR]);
		toIn(k, preR, postL + leftnum, postR - 1);//right tree
	}
}

int main()
{
	int n; scanf("%d", &n);
	pre.resize(n);
	post.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &pre[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &post[i]);
	toIn(0, n - 1, 0, n - 1);
	if (flag == true) printf("Yes\n");
	else printf("No\n");
	for (int i = 0; i < in.size(); i++)
	{
		printf("%d", in[i]);
		if (i != in.size() - 1) printf(" ");
	}
	printf("\n");
}