/*
 * File Created: Saturday, 13th July 2019 11:53:50 pm
 * Author: 北落师门 (NJTech_hemengjie@qq.com)
 * Last Modified: Sunday, 14th July 2019 9:57:45 am
 * Copyright (c) 2019 北落师门
 */
#include <algorithm>
#include <iostream>
using namespace std;
const int N = 10050;
int x[N];
int y[N];
int n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }
    sort(x, x + n);
    for (int i = 0; i < n; i++)
        x[i] -= i;
    sort(x, x + n);//注意两次排序
    sort(y, y + n);
    int mid_x, mid_y;
    if (n & 1)
    {
        mid_x = x[n / 2];
        mid_y = y[n / 2];
    }
    else
    {
        mid_x = (x[n / 2 - 1] + x[n / 2]) / 2;
        mid_y = (y[n / 2 - 1] + y[n / 2]) / 2;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += abs(x[i] - mid_x);
        ans += abs(y[i] - mid_y);
    }
    cout << ans << endl;
    //system("pause");
    return 0;
}