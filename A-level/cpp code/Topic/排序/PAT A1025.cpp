// PAT A1025.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
// 1025 PAT Ranking (25 ��)

#include <stdlib.h>
#include <stdio.h>
#include <algorithm>

using namespace std;

struct student
{
	//registration_number final_rank location_number local_rank
	char id[15];
	int score;
	int loc_num;
	int loc_rank;
	int final_rank;
}stu[40000];

bool cmp(student a, student b)
{
	if (a.score != b.score) return a.score > b.score;
	else return strcmp(a.id, b.id) < 0;
}

int main()
{
	int n = 0;
	int k = 0;
	scanf("%d", &n);
	int num = 0;	// numΪ�ܿ���������Ϊ�ۼ�������
	for (int i = 1; i <= n; i++)
	{	// ѭ��n�Σ�������Ϊi
		scanf("%d", &k);
		for (int j = 0; j < k; j++)
		{
			scanf("%s %d", stu[num].id, &stu[num].score);
			stu[num].loc_num = i;	// �ÿ����Ŀ�����
			num++;
		}

		sort(stu + num - k, stu + num, cmp);	// ���ÿ����Ŀ�������
		stu[num - k].loc_rank = 1;	// �ÿ�����һ����loc_rank��Ϊ1
		for (int j = num - k + 1; j < num; j++)
		{	// �Ըÿ���ʣ���ѧ��
			if (stu[j].score == stu[j - 1].score)
			{	// �����ǰһλ����ͬ��
				// loc_rankҲ��ͬ
				stu[j].loc_rank = stu[j - 1].loc_rank;
			}
			else
			{	// �����ǰһλ������ͬ��
				// loc_rank Ϊ�ÿ���ǰ������
				stu[j].loc_rank = j + 1 - (num - k);	// �±�j+1-ǰ������Ԫ�ظ���
			}
		}
	}
	printf("%d\n", num);
	sort(stu, stu + num, cmp);
	int r = 1;	// ������
	for (int i = 0; i < num; i++)
	{
		if (i > 0 && stu[i].score != stu[i - 1].score)
		{
			r = i + 1;
		}
		printf("%s ", stu[i].id);
		printf("%d %d %d\n", r, stu[i].loc_num, stu[i].loc_rank);
	}
	return 0;
}

