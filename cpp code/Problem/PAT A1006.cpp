//PAT A1006.cpp 1006 Sign In and Sign Out (25 ?)
//???map??????map???key??
#include <iostream>	
#include <map>
#include <cstdio>
#include <string>
using namespace std;

map<int, string> in;
map<int, string> out;
int toSec(int hh, int mm, int ss)
{
	return hh * 3600 + mm * 60 + ss;
}

int main()
{
	int m; cin >> m;
	for (int i = 0; i < m; i++)
	{
		string id; cin >> id;
		int hh, mm, ss;
		scanf("%d:%d:%d", &hh, &mm, &ss);
		in[toSec(hh, mm, ss)] = id;
		scanf("%d:%d:%d", &hh, &mm, &ss);
		out[toSec(hh, mm, ss)] = id;
	}
	cout << in.begin()->second << " " << out.rbegin()->second;
	return 0;
}