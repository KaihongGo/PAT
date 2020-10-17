//PAT A1020.cpp 1020 Tree Traversals (25 分)
//BUGS:for() 一句statement可以没{}; while(){}得有{};
//建树操作,中序，后序 转层序

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

int in[maxn], post[maxn];

void levelOrder(node* root)
{
	queue<node*> q;
	q.push(root);
	while (!q.empty())
	{
		node* now = q.front();
		q.pop();
		printf("%d", now->data);
		if (now->lchild != NULL) q.push(now->lchild);
		if (now->rchild != NULL) q.push(now->rchild);
		if (!q.empty()) printf(" ");	//递归完，队列不空，输出空格；最后一个元素输出时，队列已空
	}
}

node* build(int postL, int postR, int inL, int InR)
{
	if (postL > postR) return NULL;
	node* root = new node;
	root->data = post[postR];
	int k = 0; 
	while (in[k] != post[postR])
	{
		k++;
	}
	int numLeft = k - inL;	//左子树结点个数
	//左子树, post:[postL, postL+numLeft-1]; in:[inL, k-1]
	root->lchild = build(postL, postL + numLeft - 1, inL, k - 1);
	//右子树, post:[postL+numLeft, postR - 1]; in:[k+1, inR]
	root->rchild = build(postL + numLeft, postR - 1, k + 1, InR);
	return root;
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &post[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &in[i]);
	node* root = build(0, n - 1, 0, n - 1);
	levelOrder(root);
	printf("\n");
	return 0;
}


