//PAT A1127.cpp 1127 ZigZagging on a Tree (30 分)
//BFS，控制奇偶性输出，借助辅助数组
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Node
{
	int val, layer;
	Node* left,* right;
};

vector<int> in, post;

Node* build(int inL, int inR, int postL, int postR)
{
	if (inL > inR) return NULL;
	int k = inL;
	while (in[k]!= post[postR])
	{
		k++;
	}
	int leftnum = k - inL;
	Node* root = new Node;
	root->val = post[postR];
	root->left = build(inL, k - 1, postL, postL + leftnum - 1);
	root->right = build(k + 1, inR, postL + leftnum, postR - 1);
	return root;
}

void layerOrder(Node* root, vector<vector<int> > &ans, int &maxLayer)
{
	queue<Node *> q;
	root->layer = 1;
	q.push(root);
	while (!q.empty())
	{
		Node* front = q.front();
		q.pop();
		//相关操作
		ans[front->layer].push_back(front->val);
		if (front->left != NULL) {
			front->left->layer = front->layer + 1;
			q.push(front->left);
		}
		if (front->right != NULL) {
			front->right->layer = front->layer + 1;
			q.push(front->right);
		}
		if (q.empty()) maxLayer = front->layer;
	}
}

int main()
{
	int n; cin >> n;
	in.resize(n);
	post.resize(n);
	for (int i = 0; i < n; i++)
		cin >> in[i];
	for (int i = 0; i < n; i++)
		cin >> post[i];
	Node* root = build(0, n - 1, 0, n - 1);
	vector<vector<int> > ans(n+5);
	int maxlayer = 0;
	layerOrder(root, ans, maxlayer);
	printf("%d", ans[1][0]);
	for (int layer = 2; layer <= maxlayer; layer++)
	{
		if (layer % 2 != 0)
		{
			for (int i = ans[layer].size() - 1; i >= 0; i--)
				printf(" %d", ans[layer][i]);
		}
		else
		{
			for (int i = 0; i < ans[layer].size(); i++)
				printf(" %d", ans[layer][i]);
		}
	}
	return 0;
}