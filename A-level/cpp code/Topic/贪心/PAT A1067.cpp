//PAT A1067.cpp 1067 Sort with Swap(0, i) (25 ��)
//
//ÿ�ε��ƶ�������С���ƶ�
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n; cin >> n;
	vector<int> pos(n);//��������λ��
	int left = 0, cnt = 0;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		pos[num] = i;
		if (pos[num] != num && num != 0)
			left++;//��0�ⲻ��λ���ϵ���
	}
	int k = 1;
	while (left > 0)
	{
		if (pos[0] == 0)
		{
			while (k < n)
			{
				if (pos[k] != k)//�ҵ�һ����ǰ���ڱ�λ�ϵ���
				{
					swap(pos[0], pos[k]);
					cnt++;
					break;
				}
				k++;
			}
		}c
		while (pos[0] != 0)
		{
			swap(pos[0], pos[pos[0]]);
			left--;
			cnt++;
		}
	}
	cout << cnt;
}