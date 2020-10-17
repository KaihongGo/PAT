//PAT A1037.cpp 1049 Counting Ones (30 ��)
//

#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> coupon;
	vector<int> product;
	int nc, np;
	cin >> nc;
	coupon.resize(nc);
	for (int i = 0; i < nc; i++)
		cin >> coupon[i];
	cin >> np;
	product.resize(np);
	for (int i = 0; i < np; i++)
		cin >> product[i];
	//sort
	sort(coupon.begin(), coupon.end());
	sort(product.begin(), product.end());
	int maxBack = 0;
	//�����ң�������
	for (int i = 0, j = 0; coupon[i] < 0 && product[j] < 0; i++, j++)
	{
		maxBack += coupon[i] * product[j];
	}
	//�������󣬴�������
	for (int i = coupon.size() - 1, j = product.size() - 1; coupon[i] > 0 && product[j] > 0; i--, j--)
	{
		maxBack += coupon[i] * product[j];
	}
	cout << maxBack;
}