/*
 * File Created: Sunday, 14th July 2019 10:44:08 am
 * Author: 北落师门 (NJTech_hemengjie@qq.com)
 * Last Modified: Sunday, 14th July 2019 10:44:16 am
 * Copyright (c) 2019 北落师门
 */
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int base1, base2;
string num;
int m[150];
char w[150];
int temp[1050];
void Init()
{
    int weight = 0;
    for (char i = '0'; i <= '9'; i++)
        w[weight] = i, m[i] = weight++;
    for (char i = 'A'; i <= 'Z'; i++)
        w[weight] = i, m[i] = weight++;
    for (char i = 'a'; i <= 'z'; i++)
        w[weight] = i, m[i] = weight++;
}
//短除法实现 进制转换
string convert(string &s, int base1, int base2)
{
    string ret = "";
    int len = s.length();
    for (int i = 0; i < len; i++)
    {
        temp[len - 1 - i] = m[s[i]];
    }
    while (len)
    {
        for (int i = len; i > 0; i--)
        {
            temp[i - 1] += temp[i] % base2 * base1;
            temp[i] /= base2;
        }
        //cout << "cur: " << temp[0] % base2 << endl;
        ret += w[temp[0] % base2];
        temp[0] /= base2;
        while (len && !temp[len - 1])
            len--;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    Init();
    cin >> t;
    while (t--)
    {
        cin >> base1 >> base2 >> num;
        cout << base1 << " " << num << endl;
        cout << base2 << " " << convert(num, base1, base2) << endl;
        cout << endl;
    }
    //system("pause");
    return 0;
}