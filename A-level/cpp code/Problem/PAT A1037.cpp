//PAT A1037.cpp 1049 Counting Ones (30 分)
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
	//左至右，处理负数
	for (int i = 0, j = 0; coupon[i] < 0 && product[j] < 0; i++, j++)
	{
		maxBack += coupon[i] * product[j];
	}
	//从右至左，处理正数
	for (int i = coupon.size() - 1, j = product.size() - 1; coupon[i] > 0 && product[j] > 0; i--, j--)
	{
		maxBack += coupon[i] * product[j];
	}
	cout << maxBack;
}