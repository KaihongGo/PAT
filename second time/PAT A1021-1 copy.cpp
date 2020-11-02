#include <iostream>
#include <set>
#include <vector>
using namespace std;

const int maxn = 10010;
vector<int> adj[maxn];
bool vis[maxn];
set<int> res;
int n;

int dfs(int u, int depth, int maxDepth)
{
    vis[u] = true;
    if (depth > maxDepth)
    {
        maxDepth = depth;
    }

    for (int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        maxDepth = dfs(v, depth + 1, maxDepth);
    }
    return maxDepth;
}

int maxdepth = -1;
int dfs_travel()
{
    for (int u = 1; u <= n; u++)
    {
        int maxd = dfs(u, 1, -1);

        if (maxd > maxdepth)
        {
            maxdepth = maxd;
            res.clear();
        }
        if (maxd == maxdepth)
        {
            res.insert(u);
        }
        fill(&vis[0], &vis[0] + maxn, false);
    }

    int num = 0;
    for (int u = 1; u <= n; u++)
    {
        if (vis[u] == false)
        {
            dfs(u, 1, 0);
            num++;
        }
    }
    return num;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }

    int num = dfs_travel();
    if (num == 1)
    {
        for (auto it = res.begin(); it != res.end(); it++)
        {
            cout << *it << endl;
        }
    }
    else
    {
        printf("Error: %d components", num);
    }
    return 0;
}