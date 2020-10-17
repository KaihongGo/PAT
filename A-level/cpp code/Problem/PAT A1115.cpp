//PAT A1115.cpp 1115 Counting Nodes in a BST (30 ��)
//���������ͳ��ͬ������
/*
Sample Input:
9
25 30 42 16 20 20 35 -5 28
Sample Output:
2 + 4 = 6
*/

#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

const int maxn = 1010;
struct node
{
	int data;
	int layer;
	node* lchild;
	node* rchild;
};
vector<node*> Tree;//�洢���

void LayerOrder(node* root)
{	//�������
	queue<node*> q;
	root->layer = 1;
	q.push(root);
	while (!q.empty())
	{
		node* now = q.front();
		q.pop();
		Tree.push_back(now);
		//printf("%d ", now->data);
		if (now->lchild != NULL)
		{
			now->lchild->layer = now->layer + 1;
			q.push(now->lchild);
		}
		if (now->rchild != NULL)
		{
			now->rchild->layer = now->layer + 1;
			q.push(now->rchild);
		}
	}
}

void insert(node* &root, int x)
{	//����root�ޱ�&���ã��Խṹ��ɸı�
	if (root == NULL)
	{	//����ʧ�ܴ���Ϊ����λ��
		root = new node;
		root->data = x;
		root->lchild = NULL;
		root->rchild = NULL;
		return;
	}
	if (x <= root->data)
		insert(root->lchild, x);
	else
		insert(root->rchild, x);
}

int main()
{
	int A[maxn], n;
	scanf("%d", &n);
	node* root = NULL;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
		insert(root, A[i]);
	}
	LayerOrder(root);
	int n1 = 0, n2 = 0;
	for (int i = 0; i < Tree.size(); i++)
	{
		if (Tree[i]->layer == Tree[Tree.size() - 1]->layer) n1++;
		else if (Tree[i]->layer == Tree[Tree.size() - 1]->layer - 1) n2++;
	}
	printf("%d + %d = %d", n1, n2, n1 + n2);
	return 0;
}