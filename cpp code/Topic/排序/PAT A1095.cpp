//PAT A1095.cpp 1095 Cars on Campus (30 ��)
//
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
const int maxn = 10010;

struct Node
{
	int time;
	string status;
	string platenum;
	bool valid = true;//��ʼ��������Ԫ�ؾ���Ч,������޳���ЧԪ��
};
vector<Node> record;
map<string, int> isIn;	  //��i����¼�Ǽ���
map<string, int> duration;//ͣ��ʱ�� 
map<string, int> intime;  //����ʱ��
map<string, int> outtime; //��ʱ��

int tosec(int hh, int mm, int ss)
{
	return hh * 3600 + mm * 60 + ss;
}

string tohour(int time)
{
	char str[20];
	int hh = time / 3600;
	int ss = time % 60;
	int mm = (time / 60) - hh * 60;
	sprintf(str, "%02d:%02d:%02d", hh, mm, ss);
	string ans(str);
	return ans;
}

bool cmp1(Node a, Node b)
{
	return a.time < b.time;
}

int main()
{
	int n, k, num = 0;//num������̨��
	cin >> n >> k;
	record.resize(n);
	for (int i = 0; i < n; i++)
	{
		string platenum;
		int hh, mm, ss;
		string status;
		cin >> platenum;
		scanf("%d:%d:%d", &hh, &mm, &ss);
		cin >> status;
		
		isIn[platenum] = -1;//��¼��Ϊ����ģ��
		record[i].time = tosec(hh, mm, ss);
		record[i].status = status;
		record[i].platenum = platenum;
	}
	sort(record.begin(), record.end(), cmp1); //������ʱ�����򣬽���ģ��
	for (int i = 0; i < n; i++)
	{	//ɾ����Ч����
		string platenum = record[i].platenum;
		if (record[i].status == "in")
		{
			if (isIn[platenum] != -1)
			{	//��ǰ������,��ǰ��¼��Ч
				record[isIn[platenum]].valid = false;
			}//ɾ��Ԫ�����õ����鳤����Ϊ�������䣻��Σ�գ�����
			else
				isIn[platenum] = i;//�����±�
		}
		else
		{	//out 
			if (isIn[platenum] != -1)
			{	//��ǰ������
				isIn[platenum] = -1;
			}
			else//�Ѿ���ȥ�ˣ���ǰ��¼��Ч
				record[i].valid = false;
		}
	}
	vector<int> ans;
	while (k--)
	{	//k query
		int hh, mm, ss;
		scanf("%d:%d:%d", &hh, &mm, &ss);
		int query = tosec(hh, mm, ss);
		int i = 0;//index 
		int incnt = 0;//car in campus 
		
		while (i < n && record[i].time <= query)
		{
			if (record[i].valid)
			{
				string platenum = record[i].platenum;
				if (record[i].status == "in")
					incnt++;
				else if (record[i].status == "out")
					incnt--;
			}
			i++;
		}
		ans.push_back(incnt);
	}
	for (int i = 0; i < ans.size(); i++)
		printf("%d\n", ans[i]);
	//find the max duration 
	for (int i = 0; i < n; i++)
	{
		if (record[i].valid)
		{
			string platenum = record[i].platenum;
			if (record[i].status == "in")
				intime[platenum] = record[i].time;
			else
			{
				outtime[platenum] = record[i].time;
				duration[platenum] += outtime[platenum] - intime[platenum];
			}
		}
	}
	int max = duration.begin()->second;
	for (auto it = duration.begin(); it != duration.end(); it++)
	{
		if (it->second > max)
			max = it->second;
	}
	for (auto it = duration.begin(); it != duration.end(); it++)
	{
		if(it->second == max)
			cout << it->first << " ";
	}
	cout <<tohour(max);
	return 0;
}