/*
 * File Created: Monday, 15th July 2019 10:25:51 am
 * Author: 北落师门 (NJTech_hemengjie@qq.com)
 * Last Modified: Monday, 15th July 2019 10:44:30 am
 * Copyright (c) 2019 北落师门
 */
#include <algorithm>
#include <iostream>
#include <math.h>
#include <queue>
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f3f3f3f3f
const int N = 1E5 + 50;
ll n, m, q, u, v, t;
ll a[N];
double p;
queue<ll> q1, q2, q3;
int GetFlag()
{
    ll ret = -inf;
    int flag = 0;
    if (!q1.empty() && q1.front() > ret)
        flag = 1, ret = q1.front();
    if (!q2.empty() && q2.front() > ret)
        flag = 2, ret = q2.front();
    if (!q3.empty() && q3.front() > ret)
        flag = 3, ret = q3.front();
    return flag;
}
ll GetMaxLen(int flag)
{
    ll ret = -inf;
    if (flag == 1)
    {
        ret = q1.front();
        q1.pop();
    }
    else if (flag == 2)
    {
        ret = q2.front();
        q2.pop();
    }
    else if (flag == 3)
    {
        ret = q3.front();
        q3.pop();
    }
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> q >> u >> v >> t;
    p = u * 1.0 / v;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n, greater<ll>());
    for (int i = 1; i <= n; i++)
    {
        q1.push(a[i]);
    }
    int temp = 1;
    ll delta = 0;
    while (temp <= m)
    {
        ll max_len = GetMaxLen(GetFlag()) + delta;
        //cout<<"cur:"<<max_len<<" time:"<<temp<<endl;
        if (temp++ % t == 0)
            cout << max_len << " ";
        ll one = p * max_len;
        q2.push(one - q - delta);
        q3.push(max_len - one - q - delta);
        delta += q;
    }
    cout << endl;
    temp=1;
    while(temp<=n+m)
    {
        ll max_len=GetMaxLen(GetFlag())+delta;
        if(temp++%t==0)
            cout<<max_len<<" ";
    }
    cout<<endl;
    //system("pause");
    return 0;
}