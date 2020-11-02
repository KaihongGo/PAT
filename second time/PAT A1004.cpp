#include <bits/stdc++.h>

using namespace std;
const int MAXN = 110;
struct Node
{
    int layer;
    vector<int> childs;
} Tree[MAXN];

int cnt[MAXN];
int bfs(int root)
{
    queue<int> q;
    q.push(root);
    Tree[root].layer = 0;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        if (Tree[front].childs.size() == 0)
        {
            cnt[Tree[front].layer]++;
        }
        for (auto child : Tree[front].childs)
        {
            Tree[child].layer = Tree[front].layer + 1;
            q.push(child);
        }
        if (q.empty())
            return Tree[front].layer;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int index, k, child;
        cin >> index >> k;
        for (int j = 0; j < k; j++)
        {
            cin >> child;
            Tree[index].childs.push_back(child);
        }
    }
    int maxLayer = bfs(01);
    for (int i = 0; i <= maxLayer; i++)
    {
        if (i != 0)
            cout << " ";
        cout << cnt[i];
    }
}