//PAT A1050.cpp 1050 String Subtraction (20 ·Ö)
//
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	int pos = s1.find_first_of(s2);
	while (pos!= string::npos)
	{
		s1.erase(s1.begin() + pos);
		pos = s1.find_first_of(s2, pos);
	}
	cout << s1;
}