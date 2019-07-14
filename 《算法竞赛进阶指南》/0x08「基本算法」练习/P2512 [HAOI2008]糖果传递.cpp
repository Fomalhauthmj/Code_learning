/*
 * File Created: Sunday, 14th July 2019 3:30:13 pm
 * Author: 北落师门 (NJTech_hemengjie@qq.com)
 * Last Modified: Sunday, 14th July 2019 3:31:19 pm
 * Copyright (c) 2019 北落师门
 */
#include <algorithm>
#include <iostream>
using namespace std;
#define ll long long
const int N = 1E6 + 50;
ll a[N], n;
ll sum[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    ll avg = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        avg += a[i];
    }
    avg /= n;
    for (int i = 0; i < n; i++)
    {
        a[i] -= avg;
        if (i)
            sum[i] = sum[i - 1] + a[i];
        else
            sum[i] = a[i];
    }
    ll ans = 0;
    sort(sum, sum + n);
    ll mid = sum[n / 2];
    for (int i = 0; i < n; i++)
    {
        ans += abs(sum[i] - mid);
    }
    cout << ans << endl;
    //system("pause");
    return 0;
}