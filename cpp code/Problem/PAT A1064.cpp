//PAT A1064 1064 Complete Binary Search Tree (30 ��)
//BUGS:left==right!!
//���ý���Ų���������򣬴������ࣻ�ɲ�������ӷ�����
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

struct node
{
	int data;
	int index;//���
};
vector<node> vi;//vi�洢�������У���С����
void findroot(int left, int right, int index)
{	//����������������ұ��
	if (left > right) return;
	if (left == right)
	{//Ҷ�ӽڵ㣬�����ֱ�ӷ���
		vi[left].index = index;
		return;
	}
	int n = right - left + 1;	//������
	int h = (int)log2(n) + 1;	//����
	//�������ö����������Ƶ�
	int leaf = n - (int)pow(2, h - 1) + 1;
	int leftleafsum = (int)pow(2, h - 2);
	int leftleaf;
	if (leaf <= leftleafsum) leftleaf = leaf;
	else leftleaf = leftleafsum;
	int leftnode = (leftleaf + (int)pow(2, h - 2) - 1);
	int root = left + leftnode;	//�������
	vi[root].index = index;//�ӱ��
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