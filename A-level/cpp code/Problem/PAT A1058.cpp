//PAT A1058.cpp 1058 A+B in Hogwarts (20 ·Ö)
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int a[3], b[3];
	int galleon, sickle, knut;
	int carry = 0;
	scanf("%d.%d.%d %d.%d.%d", &a[0], &a[1], &a[2], &b[0], &b[1], &b[2]);
	knut = (a[2] + b[2]) % 29;
	carry = (a[2] + b[2]) / 29;
	sickle = (a[1] + b[1] + carry) % 17;
	carry = (a[1] + b[1] + carry) / 17;
	galleon = a[0] + b[0] + carry;
	printf("%d.%d.%d",galleon,sickle,knut);
}