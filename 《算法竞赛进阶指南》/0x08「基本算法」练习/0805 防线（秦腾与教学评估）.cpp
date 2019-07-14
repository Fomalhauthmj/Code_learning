/*
 * File Created: Sunday, 14th July 2019 4:25:24 pm
 * Author: 北落师门 (NJTech_hemengjie@qq.com)
 * Last Modified: Sunday, 14th July 2019 6:34:30 pm
 * Copyright (c) 2019 北落师门
 */
#include <iostream>
#include<algorithm>
using namespace std;
#define ll long long
const int N = 2e5 + 50;
int n;
struct p
{
    ll s, e, d;
    bool operator<(const p& n) const
    {
        if(s!=n.s) return s<n.s;
        return e<n.e;
    }
};
p ps[N];
ll cnt;
ll count(ll pos)
{
    ll ret=0;
    for(int i=0;i<n;i++)
    {
        if(ps[i].s>pos) break;
        ret+=(min(pos,ps[i].e)-ps[i].s)/ps[i].d+1;
    }
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> ps[i].s >> ps[i].e >> ps[i].d;
        sort(ps,ps+n);
        ll left, right, mid;
        left = 0;
        right = (1ll<< 31);
        while (left < right)
        {
            mid = (left + right) >> 1;
            //cout<<"cur:"<<mid<<endl;
            if (count(mid)&1)
            {
                right = mid;
            }
            else
                left = mid + 1;
        }
        if (left != (1ll << 31))
            cout << left << " " << count(left)-count(left-1) << endl;
        else
            cout << "There's no weakness." << endl;
    }
    //system("pause");
    return 0;
}