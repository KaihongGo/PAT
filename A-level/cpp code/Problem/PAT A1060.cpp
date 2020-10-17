//1060 Are They Equal (25分)
//

#include <iostream>
#include <string>
using namespace std;

string toNum(string num, int n)
{
    //将num转化为科学计数法，返回转化结果
    string ans;
    ans += "0.";

    while (num.size() > 0 && num[0] == '0')
    { //删除前导0
        num.erase(num.begin());
    }

    int dot = num.find('.');
    if (dot != string::npos)
        num.erase(num.begin() + dot); //删除点
    else
        dot = num.length(); //没找到，点在数字后

    int e = 0; //精度
    if (dot == 0)
    {
        //0.05删除小数点前0--> .05 --> 05
        //0.05 --> 0.5*10^-1
        while (num.length() > 0 && num[0] == '0')
        {
            //得到指数
            num.erase(num.begin());
            e--; //指数
        }
    }
    else
        e = dot;

    //经过上面处理
    //0.005 --> 005
    //12.4  --> 124
    //12    --> 12
    //三种情况
    if (num.length() == 0)
        e = 0;

    int i = 0;
    for (; i < n && i < num.length(); i++)
    {
        ans += num[i];
    }
    

    ans += ("*10^" + to_string(e));
    return ans;
}

int main()
{
    int n;
    cin >> n;
    string a, b; // BUG! --> 数字预处理
    cin >> a >> b;
    string a_digit = toNum(a, n);
    string b_digit = toNum(b, n);
    if (a_digit == b_digit)
        cout << "YES"
             << " " << a_digit << endl;
    else
        cout << "NO"
             << " " << a_digit << " " << b_digit << endl;
    return 0;
}
