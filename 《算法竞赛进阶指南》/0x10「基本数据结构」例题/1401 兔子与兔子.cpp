/*
 * File Created: Tuesday, 16th July 2019 7:25:07 pm
 * Author: 北落师门 (NJTech_hemengjie@qq.com)
 * Last Modified: Tuesday, 16th July 2019 7:27:44 pm
 * Copyright (c) 2019 北落师门
 */
#include <iostream>
#include <string>
using namespace std;
#define ull unsigned long long
#define P 131
const int N = 1E6 + 50;
string str;
ull p[N], f[N];
ull Hash(int left, int right)
{
    return f[right] - f[left-1] * p[right - left + 1];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> str;
    int len = str.length();
    p[0] = 1;
    for (int i = 1; i <= len; i++)
    {
        f[i] = f[i - 1] * P + (str[i - 1] - 'a' + 1);
        p[i] = p[i - 1] * P;
    }
    int m, l1, r1, l2, r2;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> l1 >> r1 >> l2 >> r2;
        if (Hash(l1, r1) == Hash(l2, r2))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    //system("pause");
    return 0;
}