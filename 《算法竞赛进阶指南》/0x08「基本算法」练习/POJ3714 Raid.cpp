/*
 * File Created: Thursday, 11th July 2019 11:50:58 pm
 * Author: 北落师门 (NJTech_hemengjie@qq.com)
 * Last Modified: Friday, 12th July 2019 10:05:20 am
 * Copyright (c) 2019 北落师门
 */
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
const int N = 1E5 + 50;
#define ll long long
#define inf 0xffffffff
ll n;
struct node
{
    ll x, y;
    bool tag;
    node() {}
    bool operator<(const node &n) const
    {
        return x < n.x;
    }
};
node a[2 * N];
double dis(node &n1, node &n2)
{
    if (n1.tag == n2.tag)
    {
        return inf;
    }
    ll temp1 = n1.x - n2.x;
    ll temp2 = n1.y - n2.y;
    return sqrt(temp1 * temp1 + temp2 * temp2);
}
double Solve(int left, int right)
{
    if (left == right)
    {
        return inf;
    }
    else if (left + 1 == right)
    {
        return dis(a[left], a[right]);
    }
    else
    {

        ll mid = (left + right) >> 1;
        double d = min(Solve(left, mid), Solve(mid, right));
        for (int i = mid - 1; i >= left; i--)
        {
            if (a[mid].x - a[i].x < d)
            {
                for (int j = mid + 1; j <= right; j++)
                {
                    if (a[j].x - a[i].x < d)
                    {
                        d = min(d, dis(a[i], a[j]));
                    }
                }
            }
        }
        return d;
    }
}
int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int t;
    //freopen("1.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < 2 * n; i++)
        {
            //cin >> a[i].x >> a[i].y;
            scanf("%lld%lld", &a[i].x, &a[i].y);
            if (i < n)
                a[i].tag = 0;
            else
                a[i].tag = 1;
        }
        sort(a, a + 2 * n);
        cout << fixed << setprecision(3) << Solve(0, 2 * n - 1) << endl;
    }
    //system("pause");
    return 0;
}