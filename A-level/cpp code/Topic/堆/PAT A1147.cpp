//PAT A1147.cpp 1147 Heaps (30 ��)
//��ס������������˼·��ȥд
//����˼·δʵ��
//9.4�� ������ʱ���Ƕ����٣�˼·������͸���
#include <cstdio>
#include <vector>
using namespace std;

int const maxn = 1010;
vector<int> heap;
int m, n;

void postOrder(int i)
{	//i root���
	if (i > n)	//�ս�㣬����
		return;
	postOrder(2 * i);
	postOrder(2 * i + 1);
	printf("%d ", heap[i]);
}

int judge(int i)
{	//����1��maxHeap��-1��minHeap��0��not
	//���ص�ǰ���flag��Ҷ��-2
	int leftflag = 0, rightflag = 0, flag = 0;
	//�ݹ��
	
	//�жϵ�ǰ�������ֶ�


	//�ж��������������ֶ�
	leftflag = judge(2 * i);
	rightflag = judge(2 * i + 1);
	//�����ϲ��Լ������ֶ�
	if (flag == 1 && leftflag == 1 && rightflag == 1)
		return 1;
	else if (flag == -1 && leftflag == -1 && rightflag == -1)
		return -1;
	else if (leftflag == -2)
		return flag;
}


int main()
{
	scanf("%d%d", &m, &n);
	heap.resize(n+1);	//����0��λ
	for (int i = 0; i < m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &heap[j]);
		}
		int flag = judge(1);
		printf("%d\n", flag);
		//postOrder(1);
		//printf("\n");
	}
	return 0;
}