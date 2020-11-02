//PAT A1101.cpp 1101 Quick Sort (25 ��)
//16�֣�����ԭ��λ�ã���
//����˼·��������±겻��
//ʵ�ʣ������������Ե�δ����
//ԭ�򣺲�����λ�ò��䣬�����������߲�������Ԫ�ز��Ϲ�

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 100010;

int main()
{
	int n;
	scanf("%d", &n);
	vector<int> data;
	data.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &data[i]);
	vector<int> temp = data;
	sort(data.begin(), data.end());
	vector<int> ans;
	int max = 0;
	for (int i = 0; i < data.size(); i++)
	{
		if (data[i] == temp[i] && temp[i] > max)
			ans.push_back(data[i]);//��ʵ�ϣ��������⣻��Ҫ�����ұ���С����
		if (temp[i] > max)//���Ӵ��룬��������ֵ
			max = temp[i];

	}
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++)
	{
		printf("%d", ans[i]);
		if (i < ans.size() - 1)
			printf(" ");
	}
	printf("\n");
}

