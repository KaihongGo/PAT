//PAT A1053.cpp 1053 Path of Equal Weight (30 分)
//BUGS：未考虑输出要求；审题不认真，输出叶结点；故需要判断是否为叶结点路径
//BUGS：可通过对输入数据进行处理，使其满足输出要求；
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 110;
int N, M, S;	//结点数，边数，给定的和
vector<int> path;	//记录路径

struct node
{
	int weight;
	vector<int> child;
} Node[maxn];

bool cmp(int a, int b)
{	//对输入数据进行除去，按权重排序
	return Node[a].weight > Node[b].weight;
}

void DFS(int root, int sum)
{	//当前访问结点未index, numNode为当前路径path上的结点个数
	//sum为当前结点和，改进为每次递归传递参数；而不是重新求取；提高效率
	if (sum == S)
	{	//触及边界
		if (Node[root].child.size() != 0) return;	//不是叶子结点，return；忘记！！！！
		for (int i = 0; i < path.size(); i++)
		{
			if (i != path.size() - 1) printf("%d ", Node[path[i]].weight);
			else printf("%d\n", Node[path[i]].weight);
		}
		return;
	}
	if (sum > S) return; //死胡同
	for (int i = 0; i < Node[root].child.size(); i++)
	{	//枚举所有子结点
		int child = Node[root].child[i];
		path.push_back(child);//走
		DFS(child,sum+Node[child].weight);
		path.pop_back();	//需要复原！！
	}
}

int main()
{	
	scanf("%d %d %d", &N, &M, &S);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &Node[i].weight);
	}
	for (int i = 0; i < M; i++)
	{
		int root, k;
		scanf("%d %d", &root, &k);
		for (int j = 0; j < k; j++)
		{	
			int child = 0;
			scanf("%d", &child);
			Node[root].child.push_back(child);
		}
		sort(Node[root].child.begin(), Node[root].child.end(), cmp);
	}
	path.push_back(0);	//首进队列，起始元素
	DFS(0,Node[0].weight);
	return 0;
}
