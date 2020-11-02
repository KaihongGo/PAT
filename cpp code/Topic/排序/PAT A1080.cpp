//PAT A1080.cpp 1080 Graduate Admission (30 ·Ö)
//
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 40010;

struct Student
{
	int id;
	int exam, inter;//grade of exam; grade of interview
	double finalGrade;
	vector<int> apply;
	int rank;
} stu[maxn];

vector<int> sameRank[maxn];//people with same rank; sub is rank;

bool cmp(Student a, Student b)
{
	if (a.finalGrade != b.finalGrade) return a.finalGrade > b.finalGrade;
	else return a.exam > b.exam;
}

int main()
{
	int n, m, k;//n applicants; m school; k, choice
	cin >> n >> m >> k;
	vector<int> quota(m);
	for (int i = 0; i < m; i++)
		cin >> quota[i];//a shcool's quota
	for (int i = 0; i < n; i++)
	{
		int exam, inter;
		cin >> exam >> inter;
		stu[i].id = i;
		stu[i].exam = exam;
		stu[i].inter = inter;
		stu[i].finalGrade = (exam + inter) / 2;
		stu[i].apply.resize(k);	// choice a student have
		for (int j = 0; j < k; j++)
			cin >> stu[i].apply[j];
	}
	//get rank of all student
	sort(stu, stu + n, cmp);
	stu[0].rank = 1;
	for (int i = 1; i < n; i++)
	{
		if (stu[i].finalGrade == stu[i - 1].finalGrade && stu[i].exam == stu[i - 1].exam)
		{	//same rank
			stu[i].rank = stu[i - 1].rank;
			sameRank[stu[i].rank].push_back(i);//not include the first one with this rank
		}
		else
			stu[i].rank = i + 1;
	}
	
	//apply school
	vector<vector<int> > admission(m);//m school
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{	//his k application
			int school = stu[i].apply[j];
			if (quota[school] != 0)
			{
				admission[school].push_back(i);// i stu's sub
				quota[school]--;
				break;
			}		
			else
			{	//same rank student
				int preStu = *(admission[school].end() - 1);//pre admitted stu i;
				
				if (stu[preStu].rank == stu[i].rank) {
					admission[school].push_back(i);
					break;
				}
			}
		}
	}
	//output the result
	for (int i = 0; i < m; i++)
	{
		vector<int> vi;
		for (int j = 0; j < admission[i].size(); j++)
		{
			int index = admission[i][j];
			vi.push_back(stu[index].id);
		}
		sort(vi.begin(), vi.end());
		for (int j = 0; j < vi.size(); j++)
		{
			printf("%d", vi[j]);
			if (j < vi.size() - 1)
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}