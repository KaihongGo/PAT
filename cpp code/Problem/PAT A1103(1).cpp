//����һ�����У�ö��������е����������У����Բ�������
//
//PAT A1130.cpp

#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> vi;//��ѡ����
int n, k, p, maxsum = -1;
vector<int> ans, temp;

void initArray()
{
	int i = 1;
	while ((int)pow(i, p) <= n)
	{
		vi.push_back((int)pow(i, p));
		i++;
	}
}

void DFS(int index, int nowK, int sum, int facSum)
{
	if (nowK == k && sum == n)
	{
		if (facSum > maxsum)
		{	//����
			maxsum = facSum;
			ans = temp;
		}
		return;
	}
	if (nowK > k || sum > n) return;
	//Σ��,Խ�翼��
	if (index >= 1)
	{
		temp.push_back(index);
		DFS(index, nowK + 1, sum + vi[index], facSum + index);
		temp.pop_back();
		DFS(index - 1, nowK, sum, facSum);
	}
}

int main()
{
	cin >> n >> k >> p;
	initArray();
	DFS(vi.size() - 1, 0, 0, 0);
	if (maxsum == -1) cout << "Impossible\n";
	else
	{
		printf("%d = %d^%d", n, ans[0], p);
		for (int i = 1; i < ans.size(); i++)
		{
			printf(" + %d^%d", ans[i], p);
		}
	}
}