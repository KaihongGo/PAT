//PAT A1110
#include <iostream>
#include <queue>
using namespace std;

const int maxn = 30;
struct node
{
    int index;
    int lchild;
    int rchild;
} tree[maxn];

int hashtable[maxn];

void bfs(int root)
{
    queue<int> q;
    q.push(root);
    tree[root].index = 1;

    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        if (tree[now].lchild != -1)
        {
            tree[tree[now].lchild].index = 2 * tree[now].index;
            q.push(tree[now].lchild);
        }
        if (tree[now].rchild != -1)
        {
            tree[tree[now].rchild].index = 2 * tree[now].index + 1;
            q.push(tree[now].rchild);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char lchild, rchild;//char不好吧
        cin >> lchild >> rchild;
        if (lchild == '-')
            tree[i].lchild = -1;
        else
        {
            tree[i].lchild = lchild - '0';//-'0'一定要小心！！！
            hashtable[tree[i].lchild] = 1;
        }
        if (rchild == '-')
            tree[i].rchild = -1;
        else
        {
            tree[i].rchild = rchild - '0';
            hashtable[tree[i].rchild] = 1;
        }
    }
    int root;
    for (int i = 0; i < n; i++)
    {
        if (hashtable[i] != 1)
        {
            root = i;
            break;
        }
    }
    bfs(root);
    int maxindex = 0;
    int maxnode;
    for (int i = 0; i < n; i++)
    {
        if (tree[i].index > maxindex)
        {
            maxindex = tree[i].index;
            maxnode = i;
        }
    }
    if (maxindex == n)
    {
        printf("YES %d", maxnode);
    }
    else
    {
        printf("NO %d", root);
    }
    return 0;
}