/*
 * File Created: Monday, 15th July 2019 11:43:27 pm
 * Author: 北落师门 (NJTech_hemengjie@qq.com)
 * Last Modified: Monday, 15th July 2019 11:43:43 pm
 * Copyright (c) 2019 北落师门
 */
#include <deque>
#include <iostream>
using namespace std;
#define ll long long
const int N = 3E5 + 50;
int n, m;
ll sum[N];
deque<ll> q;
void Init()
{
    cin >> n >> m;
    ll num;
    sum[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> num;
        sum[i] = sum[i - 1] + num;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    Init();
    ll ans = -0x3f3f3f3f;
    q.push_back(0);// 必要
    for (int i = 1; i <= n; i++)
    {
        while (!q.empty() && q.front() < i - m)
            q.pop_front();
        if (!q.empty())
            ans = max(ans, sum[i] - sum[q.front()]);
        while (!q.empty() && sum[q.back()] >= sum[i])
            q.pop_back();
        q.push_back(i);
    }
    cout << ans << endl;
    //system("pause");
    return 0;
}