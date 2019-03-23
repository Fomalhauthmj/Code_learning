#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;
#define mem(a, b) memset(a, b, sizeof(a))
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
typedef long long ll;
const int N = 10000 + 20;
struct Seg
{
    int l, r, h;
    int f;
    Seg() {}
    Seg(int a, int b, int c, int d) : l(a), r(b), h(c), f(d) {}
} e[N];
bool cmp(Seg a, Seg b)
{
    return a.h < b.h;
}
struct node
{
    int len;
    int cnt;
} t[N << 2];

int X[N];
void pushdown(int l, int r, int rt)
{
    if (t[rt].cnt)
        t[rt].len = X[r + 1] - X[l];
    else if (l == r)
        t[rt].len = 0;
    else
        t[rt].len = t[rt << 1].len + t[rt << 1 | 1].len;
}
void update(int L, int R, int l, int r, int rt, int val)
{
    if (L <= l && r <= R)
    {
        t[rt].cnt += val;
        pushdown(l, r, rt);
        return;
    }
    int m = (l + r) >> 1;
    if (L <= m)
        update(L, R, lson, val);
    if (R > m)
        update(L, R, rson, val);
    pushdown(l, r, rt);
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    int a, b, c, d;
    scanf("%d", &n);
    mem(t, 0);
    int num = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        X[num] = a;
        e[num++] = Seg(a, c, b, 1);
        X[num] = c;
        e[num++] = Seg(a, c, d, -1);
    }
    sort(X, X + num);
    sort(e, e + num, cmp);
    int m = unique(X, X + num) - X;
    for (int i = 0; i < num-1; i++)
    {
        int l = lower_bound(X, X + m, e[i].l) - X;
        int r = lower_bound(X, X + m, e[i].r) - X - 1;
        update(l, r, 0, m, 1, e[i].f);
        ans += t[1].len * (e[i + 1].h - e[i].h);
    }
    printf("%d\n", ans);
    return 0;
}