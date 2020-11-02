//PAT A1083.cpp 1083 List Grades (25 分)
//只通过2个测试点！原因：数组开小了！

#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100010;

struct Student
{
	char name[15];
	char ID[15];
	int grade;
}stu[maxn];

bool cmp(Student a, Student b)
{
	return a.grade > b.grade;
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s %s %d", &stu[i].name, &stu[i].ID, &stu[i].grade);
	}
	int grade1, grade2;
	scanf("%d %d", &grade1, &grade2);
	sort(stu, stu + n, cmp);
	bool flag = false;
	for (int i = 0; i < n; i++)
	{
		if (stu[i].grade >= grade1 && stu[i].grade <= grade2)
		{
			flag = true;
			printf("%s %s\n", stu[i].name, stu[i].ID);
		}
	}
	if (!flag) printf("NONE\n");
	return 0;

}
