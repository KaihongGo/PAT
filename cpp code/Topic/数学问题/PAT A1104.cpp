//PAT A1104.cpp 1104 Sum of Number Segments (20 ·Ö)
//

#include <iostream>
using namespace std;
const int MAXN = 1e6;
double num[MAXN];

int main()
{
	int n;
	cin >> n;
	double sum = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> num[i];
		sum += num[i] * i * (n - i + 1);
	}
	printf("%.2f", sum);	
}