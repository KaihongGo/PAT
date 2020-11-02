//PAT A1086.cpp 1086 Tree Traversals Again(25 分)
//基本思路：模拟栈过程，产生前序，中序序列；进而输出后序序列
//二叉树，前序中序序列 输出后序序列
#include <cstdio>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;

vector<int> pre, in;
int n;
int k = 0;	//统计输出结点数；用于末尾不输出空格

void PreIn2Post(int preL, int preR, int inL)
{
	if (preL > preR)
		return;
	int k = inL;//找根
	while (in[k] != pre[preL])
		k++;
	int  numleft = k - inL;	//左子树个数
	PreIn2Post(preL + 1, preL + numleft, inL);	//left tree
	PreIn2Post(preL + numleft + 1, preR, k + 1);//right tree
	if (pre[preL] == pre[0])	
		printf("%d\n", pre[preL]);//输出根
	else
		printf("%d ", pre[preL]);
}

int main()
{
	stack<int> st;
	scanf("%d", &n);
	while (pre.size() != n || in.size() != n)
	{
		char op[10];
		int key;
		scanf("%s", op);
		if (strcmp(op, "Push") == 0)
		{
			scanf("%d", &key);
			pre.push_back(key);
			st.push(key);
		}
		else if (strcmp(op, "Pop") == 0)
		{
			in.push_back(st.top());
			st.pop();
		}
	}
	PreIn2Post(0, pre.size() - 1, 0);
	return 0;
	
}