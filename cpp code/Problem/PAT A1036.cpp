//PAT A1036.cpp 1036 Boys vs Girls (25 ·Ö)
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

struct Person
{
	string name;
	char gender;
	string id;
	int grade;
};

int main()
{
	int n; cin >> n;
	Person maxGirl = { "",'F',"",0 };
	Person minBoy = { "",'M',"",150 };
	for (int i = 0; i < n; i++) {
		Person temp;
		cin >> temp.name >> temp.gender >> temp.id >> temp.grade;
		if (temp.gender == 'F' && temp.grade > maxGirl.grade)
			maxGirl = temp;
		else if (temp.gender == 'M' && temp.grade < minBoy.grade)
			minBoy = temp;
	}
	
	bool absent = false;
	if (maxGirl.name == "")
	{
		cout << "Absent" << endl;
		absent = true;
	}
	else
		cout << maxGirl.name << " " << maxGirl.id << endl;
	if (minBoy.name == "")
	{
		cout << "Absent" << endl;
		absent = true;
	}
	else
		cout << minBoy.name << " " << minBoy.id << endl;
	if (absent) cout << "NA" << endl;
	else cout << maxGirl.grade - minBoy.grade;
	return 0;
}