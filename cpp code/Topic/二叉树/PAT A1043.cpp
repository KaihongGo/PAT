//PAT A1043.cpp 1043 Is It a Binary Search Tree (25 分)
//二叉查找树BST，构建；遍历
/*
sample input:
7
8 6 5 7 10 8 11
*/

#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 1010;

struct node
{
	int data;
	node* lchild;
	node* rchild;
};

void insert(node *&root, int x)
{	//BST建树
	if (root == NULL)
	{
		root = new node;
		root->data = x;
		root->lchild = NULL;
		root->rchild = NULL;
		return;
	}
	if (x < root->data) insert(root->lchild, x);
	else insert(root->rchild, x);
}

node* create(vector<int> data, int n)
{
	node* root = NULL;
	for (int i = 0; i < n; i++)
		insert(root, data[i]);
	return root;
}

void PreOrder(node* root, vector<int> &Pre)
{
	if (root == NULL) return;
	Pre.push_back(root->data);
	PreOrder(root->lchild, Pre);
	PreOrder(root->rchild, Pre);
}

void rPreOrder(node* root, vector<int>& rPre)
{
	if (root == NULL) return;
	rPre.push_back(root->data);
	rPreOrder(root->rchild, rPre);
	rPreOrder(root->lchild, rPre);
}

void PostOrder(node* root, vector<int> &post)
{
	if (root == NULL) return;
	PostOrder(root->lchild, post);
	PostOrder(root->rchild, post);
	post.push_back(root->data);
}

void rPostOrder(node* root, vector<int> &rpost)
{
	if (root == NULL) return;
	rPostOrder(root->rchild, rpost);
	rPostOrder(root->lchild, rpost);
	rpost.push_back(root->data);
}

int main()
{
	int n;
	vector<int> data;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int a = 0;
		scanf("%d", &a);
		data.push_back(a);
	}
	node *root = create(data, n);
	vector<int> Pre, rPre, Post, rPost;
	PreOrder(root, Pre);
	rPreOrder(root, rPre);
	PostOrder(root, Post);
	rPostOrder(root, rPost);
	
	if (Pre == data)
	{
		printf("YES\n");
		for (int i = 0; i < Post.size(); i++)
		{
			printf("%d", Post[i]);
			if (i < Post.size() - 1) printf(" ");
		}
	}
	else if (rPre == data)
	{
		printf("YES\n");
		for (int i = 0; i < rPost.size(); i++)
		{
			printf("%d", rPost[i]);
			if (i < rPost.size() - 1) printf(" ");
		}
	}
	else printf("NO\n");
}