// PAT A1127

#include <iostream>
#include <queue>
using namespace std;

const int maxn = 35;
struct node
{
    int data;
    int layer;
    node *lchild;
    node *rchild;
};

int post[maxn], in[maxn];
vector<node *> oddLayer, evenLayer;

void bfs(node *root)
{
    queue<node *> q;
    q.push(root);
    root->layer = 1;
    while (!q.empty())
    {
        node *now = q.front();
        q.pop();
        if (now->layer % 2 == 0)
        {
            evenLayer.push_back(now);
            
        }
        else
        {
            oddLayer.push_back(now);
        }

        if (now->lchild != NULL)
        {
            q.push(now->lchild);
            now->lchild->layer = now->layer + 1;
        }
        if (now->rchild != NULL)
        {
            q.push(now->rchild);
            now->rchild->layer = now->layer + 1;
        }
    }
}

node *preInCreate(int postl, int postr, int inl, int inr)
{
    if (postl > postr)
        return NULL;
    node *root = new node;
    root->data = post[postr];
    int k = inl;
    while (in[k] != root->data)
        k++;
    int numleft = k - inl;
    root->lchild = preInCreate(postl, postl + numleft - 1, inl, k - 1);
    root->rchild = preInCreate(postl + numleft, postr - 1, k + 1, inr);
    return root;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> post[i];
    }
    node *root = preInCreate(0, n - 1, 0, n - 1);
    bfs(root);
    return 0;
}