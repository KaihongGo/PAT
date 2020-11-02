//PAT A1077.cpp 1077 Kuchiguse (20 ��)
//����˼·������Ƚ��ַ�����������ϳ��ȱ�����ĩβ�ַ���Ϊ�Ƚϱ�־
//�����Ƚ��ַ������򣬶���һ����Ϊ��׼��ʧ�ܾͽ�ȡ�����ǰ�����
//���Ų��з�������
#include <string>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	string str[110];
	int n;
	cin >> n;
	vector<int> len;//��������
	getchar();
	for (int i = 0; i < n; i++)
	{
		getline(cin, str[i]);
		len.push_back(str[i].size());
	}
	int minlen = 0x3fffffff;
	for (int i = 0; i < n; i++)
	{
		if (len[i] < minlen)
			minlen = len[i];
	}
	string kuchiguse;
	char temp;
	int index = 0;
	while (index < minlen)
	{
		for (int i = 0; i < n; i++)
		{//���������ַ���
			temp = str[n - 1][len[n - 1] - 1];//���һ���ַ��� β
			if (str[i][len[i] - 1] != temp)
				break;	//�ƺ�û�пո���
			if (i == n - 1)
			{//β�ַ���
				kuchiguse += temp;
			}
			len[i]--;//���³���
		}
		index++;
	}
	reverse(kuchiguse.begin(), kuchiguse.end());//�ַ�������
	if (kuchiguse.size() != 0)
		printf("%s", kuchiguse.c_str());
	else
		printf("nai");
}