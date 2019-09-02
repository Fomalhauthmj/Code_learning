#include <algorithm>
#include <cstring>
#include <iostream>
#include <stdio.h>
using namespace std;
const int N = 1E5 + 50;
const int M = 1E5 + 50;
#define ll long long
struct point
{
    int x, y, tag, id, val;
    bool operator<(const point &n) const
    {
        if (x == n.x && y == n.y)
            return tag < n.tag;
        if (x != n.x)
            return x < n.x;
        return y < n.y;
    }
} po[5 * N];
int n, m, p, tot, y[5 * N], ycnt;
ll c[5 * N], ans[5 * N];
ll Ori_Val(int x, int y)
{
    x = x - (n + 1) / 2;
    y = y - (n + 1) / 2;
    int t = max(abs(x), abs(y));
    if (x >= y)
        return (ll)n * n - (ll)4 * t * t - 2 * t - x - y;
    else
        return (ll)n * n - (ll)4 * t * t + 2 * t + x + y;
}
int Bit_Val(ll ori_val)
{
    int ret = 0;
    while (ori_val)
        ret += ori_val % 10, ori_val /= 10;
    return ret;
}
int lowbit(int x)
{
    return x & (-x);
}
void change(int x, int v)
{
    while (x <= ycnt)
    {
        c[x] += v;
        x += lowbit(x);
    }
}
int getsum(int x)
{
    ll ans = 0;
    while (x >= 1)
    {
        ans += c[x];
        x -= lowbit(x);
    }
    return ans;
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        //init
        memset(c, 0, sizeof(c));
        tot = 0, ycnt = 0;
        scanf("%d%d%d", &n, &m, &p);
        for (int i = 1, xi, yi; i <= m; i++)
            scanf("%d%d", &xi, &yi), po[++tot] = {xi, yi, 0, 0, Bit_Val(Ori_Val(xi, yi))}, y[++ycnt] = yi;
        for (int i = 1, a, b, c, d; i <= p; i++)
        {
            scanf("%d%d%d%d", &a, &b, &c, &d);
            po[++tot] = {a - 1, b - 1, 1, i, 0}, y[++ycnt] = b - 1;
            po[++tot] = {c, b - 1, 1, i + p, 0},
            po[++tot] = {a - 1, d, 1, i + 2 * p, 0}, y[++ycnt] = d;
            po[++tot] = {c, d, 1, i + 3 * p, 0};
        }
        sort(po + 1, po + 1 + tot);
        sort(y + 1, y + 1 + ycnt);
        ycnt = unique(y + 1, y + 1 + ycnt) - (y + 1);
        for (int i = 1; i <= tot; i++)
        {
            int k = lower_bound(y + 1, y + 1 + ycnt, po[i].y) - y;
            if (!po[i].tag)
                change(k, po[i].val);
            else
            {
                ans[po[i].id] = getsum(k);
            }
        }
        for (int i = 1; i <= p; i++)
        {
            ll ret = ans[i + 3 * p] - ans[i + 2 * p] - ans[i + p] + ans[i];
            printf("%lld\n", ret);
        }
    }
    //system("pause");
    return 0;
}