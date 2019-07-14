/*
 * File Created: Sunday, 14th July 2019 1:22:45 pm
 * Author: 北落师门 (NJTech_hemengjie@qq.com)
 * Last Modified: Sunday, 14th July 2019 1:22:48 pm
 * Copyright (c) 2019 北落师门
 */
#include <algorithm>
#include <iostream>
using namespace std;
#define ll long long
const int N = 50050;
struct cow
{
    ll weight, strength;
    bool operator<(const cow &n) const
    {
        return weight + strength < n.weight + n.strength;
    }
};
cow p[N];
int n;
ll sum[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> p[i].weight >> p[i].strength;
    sort(p, p + n);
    ll ans;
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (i)
            ans = max(ans, sum - p[i].strength);
        else
            ans = sum - p[i].strength;
        sum += p[i].weight;
    }
    cout << ans << endl;
    //system("pause");
    return 0;
}