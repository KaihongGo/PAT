//PAT A1044.cpp 1044 Shopping in Mars (25 分)
//
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 100010;

struct node
{
    int begin, end, value;
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> A(n);
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i]
    }
    vector<node> vi;
    int min = 0x7fffffff;
    for (int i = 0; i < n; i++)
    { 
        // 子列和，A[j] -A[i+1] = S[j] - S[i] >= m --> S[j] >= m + S[i]; 
        // 取A[i+1]-A[j];
        // S[j]表示[0-j]的数值和
        // S[i]表示[0-i]的数值和
        // S[j]-S[i]表示A[i+1]-A[j]的数和
        int j = lower_bound(S + i, S + n, m + S[i]) - S;
        node temp = {i + 1, j, S[j] - S[i]};
        if (temp.value >= m)
        {  
            vi.push_back(temp);
            if (temp.value < min)
                min = temp.value;
        }
    }
    for (int i = 0; i < vi.size(); i++)
    {
        if (vi[i].value == min)
            printf("%d-%d\n", vi[i].begin, vi[i].end);
    }
    return 0;
}