//PAT A1151.cpp  1151 LCA in a Binary Tree (30 分)
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Node
{
	int key;
	Node* lchild;
	Node* rchild;
};
vector<int> in;
vector<int> pre;
Node* buildTree(int inL, int inR, int preL, int preR)
{
	if (inL > inR) return NULL;
	int k = inL;
	while (in[k] != pre[preL])
	{
		k++;
	}
	int leftnum = k - inL;
	Node* root = new Node;
	root->key = pre[preL];
	root->lchild = buildTree(inL, k - 1, preL + 1, preL + leftnum);
	root->rchild = buildTree(k + 1, inR, preL + leftnum + 1, preR);
	return root;
}

void findParent(Node* root, int key, int &parent)
{
	if ((root->lchild != NULL && root->lchild->key == key) || (root->rchild != NULL && root->rchild->key == key))
		parent = root->key;
	if (root->lchild != NULL && parent == -1) findParent(root->lchild, key, parent);
	if (root->rchild != NULL && parent == -1) findParent(root->rchild, key, parent);
	
}

int findAncestor(map<int, int> father, int key1, int key2)
{
	return 0;
	int farA = father[key1];
	int farB = father[key2];
	while (farA != farB)
	{	//顺着a找
		farA = father[farA];
	}
	return 0;
}

int main()
{
	int m, n;
	cin >> m >> n;
	in.resize(n);
	pre.resize(n);
	for (int i = 0; i < n; i++)
		cin >> in[i];
	for (int i = 0; i < n; i++)
		cin >> pre[i];
	Node *root = buildTree(0, n - 1, 0, n - 1);
	map<int, int> father; //key的father
	for (int i = 0; i < n; i++)
	{
		int parent = -1;
		findParent(root, in[i], parent);
		father[in[i]] = parent;//key结点父亲结点parent ;借鉴并查集
	}
	return 0;
}