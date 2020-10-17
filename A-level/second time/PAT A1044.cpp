//PAT A1044.cpp 1044 Shopping in Mars (25 分)
//
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 100010;

int S[maxn];
struct node
{
    int begin, end, value;
};

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    { //下标由【1】开始-->题目实际意思
        //下标即表示第几个数
        //S[i]代表[1-i]，i之前所有数值和
        cin >> S[i];
        S[i] += S[i - 1];//S[0] = 0;
    }
    vector<node> vi;
    int min = 0x7fffffff;
    for (int i = 0; i <= n; i++)
    {
        //lower_bound用法
        //Returns an iterator pointing to the first element in the range ***[first, last)*** that is not less than (i.e. greater or equal to) value, 
        //or last if no such element is found.（来自文档）
        
        //i从0开始！！因为代表A[i+1]-->A[j]的和；A[1]从1开始

        // 子列和，A[j] -A[i+1] = S[j] - S[i] >= m --> S[j] >= m + S[i];
        // 取A[i+1]-A[j]; >= --> lower_bound函数
        // S[j]表示[1-j]的数值和
        // S[i]表示[1-i]的数值和
        // S[j]-S[i]表示A[i+1]-A[j]的数和
        int j = lower_bound(S + i, S + n + 1, m + S[i]) - S;
        //[first, last)
        //first = S + i
        //last =  S + n + 1 --> 开区间
        //寻找值>= m + S[i]
        //lower_bound返回指针（数组）/迭代器;减去开始指针(-S)得到下标
        node temp = node{i + 1, j, S[j] - S[i]}; //构建node对象, node temp = {i+1, j, S[j]-S[i]};写法也可以，按变量声明位置赋值
        if (temp.value >= m)
        {
            //if判断筛选，可能没找到
            //lower_bound可能没找到，没找到返回last-->j = n + 1
            vi.push_back(temp);
            if (temp.value < min)
                min = temp.value;
        }
    }
    for (int i = 0; i < vi.size(); i++)
    {
        //vi[i]是结构体node
        if (vi[i].value == min)
            printf("%d-%d\n", vi[i].begin, vi[i].end);
    }
    return 0;
}