#include <algorithm>
#include <iostream>
#include <stdio.h>
using namespace std;
const int N = 5E5 + 50;
const int M = 5E5 + 50;
struct point
{
    int x, y, tag, id;
    bool operator<(const point &n) const
    {
        if (x == n.x && y == n.y)
            return tag < n.tag;
        if (x != n.x)
            return x < n.x;
        return y < n.y;
    }
} p[5 * N];
int n, m, tot, y[5 * N], ycnt, c[5 * N], ans[5 * N];
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
    int ans = 0;
    while (x >= 1)
    {
        ans += c[x];
        x -= lowbit(x);
    }
    return ans;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1, xi, yi; i <= n; i++)
        scanf("%d%d", &xi, &yi), p[++tot] = {xi, yi, 0, 0}, y[++ycnt] = yi;
    for (int i = 1, a, b, c, d; i <= m; i++)
    {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        p[++tot] = {a - 1, b - 1, 1, i}, y[++ycnt] = b - 1;
        p[++tot] = {c, b - 1, 1, i + m},
        p[++tot] = {a - 1, d, 1, i + 2 * m}, y[++ycnt] = d;
        p[++tot] = {c, d, 1, i + 3 * m};
    }
    sort(p + 1, p + 1 + tot);
    sort(y + 1, y + 1 + ycnt);
    ycnt = unique(y + 1, y + 1 + ycnt) - (y + 1);
    for (int i = 1; i <= tot; i++)
    {
        int k = lower_bound(y + 1, y + 1 + ycnt, p[i].y) - y;
        if (!p[i].tag)
            change(k, 1);
        else
        {
            ans[p[i].id] = getsum(k);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int ret = ans[i + 3 * m] - ans[i + 2 * m] - ans[i + m] + ans[i];
        printf("%d\n", ret);
    }
    //system("pause");
    return 0;
}