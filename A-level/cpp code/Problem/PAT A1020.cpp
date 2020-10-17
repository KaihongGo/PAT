//PAT A1020.cpp 1020 Tree Traversals (25 ��)
//BUGS:for() һ��statement����û{}; while(){}����{};
//��������,���򣬺��� ת����

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
		if (!q.empty()) printf(" ");	//�ݹ��꣬���в��գ�����ո����һ��Ԫ�����ʱ�������ѿ�
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
	int numLeft = k - inL;	//������������
	//������, post:[postL, postL+numLeft-1]; in:[inL, k-1]
	root->lchild = build(postL, postL + numLeft - 1, inL, k - 1);
	//������, post:[postL+numLeft, postR - 1]; in:[k+1, inR]
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


