//PAT A1135.cpp 1135 Is It A Red-Black Tree (30 分)
//
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct Node
{
	int val;
	Node* left;
	Node* right;
};

void build(Node*& root, int val)
{
	if (root == NULL)
	{
		root = new Node;
		root->val = val;
		root->left = root->right = NULL;
		return;
	}
	if (abs(val) < abs(root->val))
		build(root->left, val);
	else
		build(root->right, val);
}
//判断每个红色结点孩子是黑色的
bool judge1(Node *root)
{
	if (root == NULL) return true;
	if (root->val < 0)
	{
		if (root->left != NULL && root->left->val < 0) return false;
		if (root->right != NULL && root->right->val < 0) return false;
	}
	return judge1(root->left) && judge1(root->right);
}

int getBlackNum(Node* root)
{
	if (root == NULL) return 0;
	int l = getBlackNum(root->left);
	int r = getBlackNum(root->right);
	if (root->val > 0) return max(l, r) + 1;
	else return max(l, r);
}

bool judge2(Node* root)
{	//判断左右黑色结点数
	if (root == NULL) return true;
	int l = getBlackNum(root->left);
	int r = getBlackNum(root->right);
	if (l != r) return false;
	//else return true;//疑问不应该这样
	return judge2(root->left) && judge2(root->right);
}

int main()
{
	int k; cin >> k;
	while (k--)
	{
		int n; cin >> n;
		vector<int> vi(n);
		Node* root = NULL;
		for (int i = 0; i < n; i++)
		{
			cin >> vi[i];
			build(root, vi[i]);
		}
		if (vi[0] > 0 && judge1(root) && judge2(root))
			printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}