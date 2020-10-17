#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 1010;
struct node
{
    double num;
    double price;
    double unit;
} mooncake[maxn];

bool cmp(node a, node b)
{
    return a.unit > b.unit;
}
int main()
{
    int n;
    double d;
    cin >> n >> d;
    for (int i = 0; i < n; i++)
    {
        cin >> mooncake[i].num;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> mooncake[i].price;
        mooncake[i].unit = mooncake[i].price / mooncake[i].num;
    }
    sort(mooncake, mooncake + n, cmp);
    double sum = 0.0;
    for (int i = 0; i < n ; i++)
    {
        if (d >= mooncake[i].num)
        {
            d = d - mooncake[i].num;
            sum += mooncake[i].price;
        }
        else
        {
            sum += d * mooncake[i].unit;
            break;
        }
    }
    printf("%.2f\n", sum);
    return 0;
}