//PAT A1079.cpp 1079 Total Sales of Supply Chain (25 分)
//vector 的一个优势，元素默认全赋值0
//BUGS: double 类型输入scanf()用%lf;输出%f；错了就不行；输入bug
//基本思路：利用层序遍历处理，统计叶子结点深度；价值与深度相关，sale累加器累加
#include <queue>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
const int maxn = 100010;
struct node
{
	double product;
	int layer;//记录retailer深度，叶子结点
	vector<int> child;
}Node[maxn];

int n;
double p, r;
double sale = 0;	//总价值，累加
void layerOrder(int root)
{
	queue<int> q;
	q.push(root);
	Node[root].layer = 0;//layer由0开始
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		
		//相关操作
		if (Node[now].child.size() == 0)
		{	//无孩子，第几层；该售出价格(1+r)^深度*p
			sale += p * pow((1 + 0.01 * r), Node[now].layer) * Node[now].product;
		}

		for (int i = 0; i < Node[now].child.size(); i++)
		{
			int child = Node[now].child[i];
			Node[child].layer = Node[now].layer + 1;
			//记录层数
			q.push(child);
		}
	}
}

int main()
{
	scanf("%d%lf%lf", &n, &p, &r);
	for (int i = 0; i < n; i++)
	{
		int k = 0;
		scanf("%d", &k);
		if (k != 0)
		{
			for (int j = 0; j < k; j++)
			{
				int child;
				scanf("%d", &child);
				Node[i].child.push_back(child);
			}
		}
		else //k==0，记录产品量,叶子结点，无孩子
		{
			double product;
			scanf("%lf", &product);
			Node[i].product = product;
		}
	}
	layerOrder(0);	//根结点编号0
	printf("%.1f", sale);
}

