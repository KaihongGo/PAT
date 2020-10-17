#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 10010;
int heap[MAXN];
int n; // n elements

vector<int> path;
void DFS(int root)
{
    if (root <= n && root * 2 > n)
    {
        path.push_back(heap[root]);
        for (int i = 0; i < path.size(); i++)
        {
            cout << path[i];
            i != path.size() - 1 ? cout << " " : cout << endl;
        }
        path.pop_back();
        return;
    }
    path.push_back(heap[root]);
    if (root * 2 + 1 <= n)
        DFS(root * 2 + 1);
    if (root * 2 <= n)
        DFS(root * 2);
    path.pop_back();
}

void downAdjust(int low, int high)
{
    int i = low, j = 2 * i;
    while (j <= high)
    {
        if (j + 1 <= high && heap[j + 1] > heap[j])
            j = j + 1;
        if (heap[j] > heap[i])
        {
            swap(heap[j], heap[i]);
            i = j;
            j = 2 * i;
        }
        else
            break;1
    }
}

void createHeap()
{
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> heap[i];
    DFS(1);
}