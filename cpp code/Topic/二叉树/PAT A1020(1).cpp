//PAT A1020.cpp 1020 Tree Traversals (25 ·Ö)
//
/*
Input:
7
2 3 1 5 7 6 4
1 2 3 4 5 6 7
*/

#include <cstdio>
#include <queue>
using namespace std;

struct node
{
	int data;
	node* lchild;
	node* rchild;
};
const int maxn = 35;

int post[maxn], in[maxn];

node* PostInCreate(int postL, int postR, int inL, int inR)
{
	if (postL > postR) return NULL;
	int k = inL;
	while (in[k] != post[postR])
		k++;
	int numLeft = k - inL;
	node* root = new node;
	root->data = post[postR];
	root->lchild = PostInCreate(postL, numLeft + postL - 1, inL, k - 1);
	root->rchild = PostInCreate(numLeft + postL, postR - 1, k + 1, inR);
	return root;
}

void LayerOrder(node* root)
{
	queue<node*> q;
	q.push(root);
	while (!q.empty())
	{
		node* now = q.front();
		q.pop();
		printf("%d", now->data);
		if (now->lchild != NULL) q.push(now->lchild);
		if (now->rchild != NULL)q.push(now->rchild);
		if(!q.empty())
			printf(" ");
	}
}


int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &post[i]);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &in[i]);
	}
	node* root = PostInCreate(0, n - 1, 0, n - 1);
	LayerOrder(root);

}