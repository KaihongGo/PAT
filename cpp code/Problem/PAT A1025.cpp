// PAT A1025.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 1025 PAT Ranking (25 分)

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
	int num = 0;	// num为总考生数，作为累加器递增
	for (int i = 1; i <= n; i++)
	{	// 循环n次，考场号为i
		scanf("%d", &k);
		for (int j = 0; j < k; j++)
		{
			scanf("%s %d", stu[num].id, &stu[num].score);
			stu[num].loc_num = i;	// 该考生的考场号
			num++;
		}

		sort(stu + num - k, stu + num, cmp);	// 将该考场的考生排序
		stu[num - k].loc_rank = 1;	// 该考场第一名的loc_rank记为1
		for (int j = num - k + 1; j < num; j++)
		{	// 对该考场剩余的学生
			if (stu[j].score == stu[j - 1].score)
			{	// 如果与前一位考生同分
				// loc_rank也相同
				stu[j].loc_rank = stu[j - 1].loc_rank;
			}
			else
			{	// 如果与前一位考生不同分
				// loc_rank 为该考生前的人数
				stu[j].loc_rank = j + 1 - (num - k);	// 下标j+1-前面已有元素个数
			}
		}
	}
	printf("%d\n", num);
	sort(stu, stu + num, cmp);
	int r = 1;	// 总排名
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

