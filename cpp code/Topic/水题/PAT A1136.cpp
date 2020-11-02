//PAT A1136.cpp 1136 A Delayed Palindrome (20 分)
//两个运行时错误！

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string add(string num)
{
	string rnum = num;
	reverse(rnum.begin(), rnum.end());
	string ans;
	int carry = 0;	//低位在前
	for (int i = 0; i < rnum.length() || i < num.length(); i++)
	{
		int temp = (rnum[i] - '0') + (num[i] - '0') + carry;
		carry = temp / 10;
		ans.push_back((temp%10)+'0');
	}
	if (carry != 0)
		ans.push_back(carry + '0');
	reverse(ans.begin(), ans.end());
	return ans;
}

int main()
{
	string num;
	cin >> num;
	bool flag = false;
	for (int i = 0; i < 10; i++)
	{	//低位存储
		string rnum = num;
		reverse(rnum.begin(),rnum.end());

		if (rnum == num)
		{
			printf("%s is a palindromic number.\n",num.c_str());
			flag = true;
			break;
		}

		cout << num << " + " << rnum << " = ";
		
		num = add(num);

		cout << num << endl;
	}
	if (!flag) printf("Not found in 10 iterations.\n");
}