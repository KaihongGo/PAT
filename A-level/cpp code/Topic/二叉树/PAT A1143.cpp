//PAT A1143.cpp 1143 Lowest Common Ancestor (30 分)
//建树超时啊！！！用遍历序列知识！！
//错误！
#include <iostream>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
	int data;
	Node* lchild;
	Node* rchild;

};

void Insert(Node*& root, int x)
{
	if (root == NULL)
	{
		root = new Node;
		root->data = x;
		root->lchild = NULL;
		root->rchild = NULL;
		return;
	}
	if (x < root->data) Insert(root->lchild, x);
	if (x >= root->data) Insert(root->rchild,x);
}

int findParent(Node* root, int x)
{	//找结点x的双亲
	if (root == NULL) return -1;
	if (root->lchild != NULL && root->lchild->data == x)
		return root->data;
	else if (root->rchild != NULL && root->rchild->data == x)
		return root->data;
	if (x < root->data)	findParent(root->lchild, x);
	else findParent(root->rchild, x);
}

int main()
{
	int m, n;
	cin >> m >> n;
	Node* root = NULL;
	for (int i = 0; i < n; i++)
	{
		int x; cin >> x;
		Insert(root,x);
	}
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		int farA = findParent(root,a), farB = findParent(root,b);
		if (farA == b)
			printf("%d is an ancestor of %d.\n", b, a);
		else if (farB == a)
			printf("%d is an ancestor of %d.\n", a, b);
		else if (farA == -1 && farB != -1)
			printf("ERROR: %d is not found.\n", a);
		else if (farB == -1 && farA != -1)
			printf("ERROR: %d is not found.\n", b);
		else if (farA == -1 && farB == -1)
			printf("ERROR: %d and %d are not found.\n", a, b);
		else
		{	//此处错误！
			while (farA!= farB)
			{
				farA = findParent(root, farA);
				if (farA == root->data) break;
			}
			while (farA!= farB)
			{
				farB = findParent(root, farB);
				if (farB == root->data) break;
			}
			printf("LCA of %d and %d is %d.\n", a, b, farA);
		}
	}
	return 0;
}