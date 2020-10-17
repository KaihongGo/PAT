#include <iostream>
using namespace std;

const int maxn = 30;
int flag[maxn];
struct node
{
    string data;
    int lchild;
    int rchild;
} tree[maxn];

string dfs(int root)
{
    // by liuchuo
    // 这种写法其实是考虑了树所有可能的情况
    // 读题目可以发现，在某些情况要多输出些东西（括号），分情况讨论喽
    // 但是先有大框架-->中序遍历
    if (tree[root].lchild == -1 && tree[root].rchild == -1)
    {
                                    //左 --> 空 
        return tree[root].data;     //根
                                    //右 --> 空
    }           
    if (tree[root].lchild == -1 && tree[root].rchild != -1)
    {
        //等价写法
        // string ans = "(";
        //                                  // 左 --> 空
        // ans += tree[root].data;          // 根
        // ans += dfs(tree[root].rchild);   // 右
        // ans += ")";
        // return ans;
        return "(" + tree[root].data + dfs(tree[root].rchild) + ")";
    }
    if (tree[root].lchild != -1 && tree[root].rchild == -1)
    {
        //题目不可能出现
    }
    if (tree[root].lchild != -1 && tree[root].rchild != -1)
    {
        //等价写法
        // string ans = "(";
        // ans += dfs(tree[root].lchild);       //左
        // ans += tree[root].data;              //根
        // ans += dfs(tree[root].rchild);       //右 --> 是不是很像中序遍历
        // ans += ")";
        // return ans;
        return "(" + dfs(tree[root].lchild) + tree[root].data + dfs(tree[root].rchild) + ")";
    }
}
//xx序遍历有顺序要求，故顺序肯定不能错
//这类题代表-->在xx序的基础上多输出点什么

int main()
{
    int n;
    cin >> n;
    int root;
    for (int i = 1; i <= n; i++)
    {
        cin >> tree[i].data >> tree[i].lchild >> tree[i].rchild;
        if (tree[i].lchild != -1)
            flag[tree[i].lchild] = 1;
        if (tree[i].rchild != -1)
            flag[tree[i].rchild] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        if (flag[i] == 0)
        {
            root = i;
            break;
        }
    }
    string ans = dfs(root);
    //直接dfs输出，会带上首位括号，故删除
    if (ans[0] == '(')
        ans = ans.substr(1, ans.size() - 2);
    cout << ans;
    return 0;
}