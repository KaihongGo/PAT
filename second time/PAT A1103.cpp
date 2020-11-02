#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

const int maxn = 1000;

vector<int> path, res;

int n, p, k;       //k表示有几个数
int maxSumNum = 0; //记录所取数字的和
int cnt = 0;

void dfs(int numk, int depth, int sum, int numSum)
{
    //depth记录存入几个数 depth -->
    //递归基
    if (sum == n && depth == k)
    {
        cnt++; //更新
        if (numSum > maxSumNum)
        {
            maxSumNum = numSum;
            res = path;
        }
        return;
    }
    //剪枝
    if (sum > n || depth > k || numk < 1)
        return;
    //选【当前】这个数
    path.push_back(numk);
    dfs(numk, depth + 1, sum + (int)pow(numk, p), numSum + numk);
    path.pop_back();
    //不选【当前】这个数，选下一个数字
    dfs(numk - 1, depth, sum, numSum); //
}

int main()
{
    //int n;
    cin >> n >> k >> p;
    int numk = pow(n, 1.0 / p);
    dfs(numk, 0, 0, 0);

    if (cnt == 0)
        cout << "Impossible";
    else
    {
        printf("%d = ", n);
        for (int i = 0; i < k; i++)
        {
            cout << res[i] << "^" << p;
            if (i != k - 1)
                cout << " + ";
        }
    }
    return 0;
}