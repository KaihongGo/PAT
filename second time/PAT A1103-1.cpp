#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

const int maxn = 1000;
// int num[maxn];   这个数组没用

vector<int> path, res;

// int sum = 0; // sum作为全局变量，函数中也有sum？？？？？
int n, p, k;
int maxSumNum = 0;
int cnt = 0;

void dfs(int numk, int depth, int sum, int numSum)
{
    //明白每个变量的意义！
    //numk --> 当前选择的数
    //depth --> 代表path中选择了多少个数字；改为index更好
    //sum --> 代表平方和
    //numSum --> 代表path中数字和

    //剪枝，不进行无效递归，缩短时间--很好！
    if (sum > n || depth > k || numk < 1)
        return;
    //递归基
    if (sum == n && depth == k)
    {
        cnt++;
        if (numSum > maxSumNum)
        {
            maxSumNum = numSum;
            res = path;
        }
        return;
    }

    //选【当前】这个数
    path.push_back(numk);
    dfs(numk, depth + 1, sum + pow(numk, p), numSum + numk);
    path.pop_back();

    //不选【当前】这个数
    // dfs(numk - 1, depth + 1, sum + pow(numk - 1, p), numsum + numk - 1);
    //正确写法
    dfs(numk -1, depth, sum, numSum);   
}

int main()
{
    // ！！！！！！！！！！！！！一定注意，我也犯过！
    // int n;   // n已经定义为全局变量，这里重新声明n；作用main局部域；因而cin这个n，全局域n仍为0！！！
    // 这种BUG！只能通过debug关注变量找出！！！
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