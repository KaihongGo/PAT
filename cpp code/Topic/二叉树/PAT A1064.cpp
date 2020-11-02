//PAT A1064 1064 Complete Binary Search Tree (30 分)
//BUGS:left==right!!
//采用结点编号策略输出层序，代码冗余；可查用填格子法建树
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

struct node
{
	int data;
	int index;//编号
};
vector<node> vi;//vi存储有序序列，有小至大
void findroot(int left, int right, int index)
{	//传入参数，序列左右编号
	if (left > right) return;
	if (left == right)
	{//叶子节点，处理后直接返回
		vi[left].index = index;
		return;
	}
	int n = right - left + 1;	//结点个数
	int h = (int)log2(n) + 1;	//树高
	//以下利用二叉树性质推导
	int leaf = n - (int)pow(2, h - 1) + 1;
	int leftleafsum = (int)pow(2, h - 2);
	int leftleaf;
	if (leaf <= leftleafsum) leftleaf = leaf;
	else leftleaf = leftleafsum;
	int leftnode = (leftleaf + (int)pow(2, h - 2) - 1);
	int root = left + leftnode;	//树根编号
	vi[root].index = index;//加编号
	findroot(left, root - 1, 2 * index);
	findroot(root + 1, right, 2 * index + 1);
}

bool cmp1(node a, node b)
{
	return a.data < b.data;
}
bool cmp2(node a, node b)
{
	return a.index < b.index;
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		
		node temp;
		scanf("%d", &temp.data);
		vi.push_back(temp);
	}
	sort(vi.begin(), vi.end(),cmp1);
	findroot(0, n - 1, 1);
	sort(vi.begin(), vi.end(), cmp2);
	printf("%d", vi[0]);
	for (int i = 1; i < vi.size(); i++)
	{
		printf(" %d", vi[i]);
	}

	return 0;
}