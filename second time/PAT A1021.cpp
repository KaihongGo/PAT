#include <iostream>
#include <set>
#include <vector>
using namespace std;

const int maxn = 10010;
vector<int> adj[maxn];
bool vis[maxn];
set<int> res; // res == result
int n;

int dfs(int u, int depth, int maxDepth)
{
    vis[u] = true;
    if (maxDepth < depth)
    {
        maxDepth = depth;
    }
    for (int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if (vis[v] == false)
        {
            maxDepth = dfs(v, depth + 1, maxDepth);//这样可以不在引用的情况下，返回maxDepth
        }
    }
    return maxDepth; //注意dfs是一个递归写法，处理最深节点的时候绝对不是最后返回一个
}

int maxdepth = -1;
int dfs_travel()
{
    for (int u = 1; u <= n; u++)
    {
        int depth = dfs(u, 1, -1);//要求dfs函数返回深度
        //如果是引用传参，是不可以直接传数值的
        if (depth > maxdepth)
        {
            maxdepth = depth;
            res.clear();
            res.insert(u);  //清空，添加当前
        }
        else if (depth == maxdepth)
        {
            res.insert(u);
        }
        fill(&vis[0], &vis[0] + maxn, false);//还原数组状态
    }
    //两个for循环可以合并为一个。分开要明白分开的功能
    int num = 0;
    for (int u = 1; u <= n; u++)
    {
        if (vis[u] == false)
        {
            dfs(u, 1, -1);
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