//PAT A1130.cpp 1130 Infix Expression (25 ·Ö)
//
#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
const int maxn = 25;
struct Node
{
	string data;
	int lchild;
	int rchild;
} Tree[maxn];

string inOrder(int root)
{
	string ans;
	if (root == -1) return "";
	if (Tree[root].lchild != -1 || Tree[root].rchild != -1) ans.push_back('(');
	ans += inOrder(Tree[root].lchild) + Tree[root].data + inOrder(Tree[root].rchild);
	if(Tree[root].lchild != -1 || Tree[root].rchild != -1) ans.push_back(')');
	return ans;
}

int main()
{
	int n; cin >> n;
	int parent[maxn];
	fill(parent, parent + maxn, -1);
	for (int i = 1; i <= n; i++)
	{
		string data;
		int lchild, rchild;
		cin >> data >> lchild >> rchild;
		Tree[i].data = data;
		Tree[i].lchild = lchild;
		Tree[i].rchild = rchild;
		if (lchild != -1) parent[lchild] = i;
		if (rchild != -1) parent[rchild] = i;
	}
	int root = 1;
	while (parent[root]!=-1)
	{
		root++;
	}
	string left = inOrder(Tree[root].lchild);
	string right = inOrder(Tree[root].rchild);
	string str =  left + Tree[root].data + right;
	cout << str << endl;
	return 0;
}