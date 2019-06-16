#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
#define inf 0x3f3f3f3f3f
#define ll long long
ll read()
{
    ll x = 0, f = 1;
    char c = getchar();
    for (; !isdigit(c); c = getchar())
        if (c == '-')
            f = -1;
    for (; isdigit(c); c = getchar())
        x = x * 10 + c - '0';
    return x * f;
}
const ll maxn = 1250;
const ll maxm = 250000;
struct edge
{
    ll v, w, nxt;
} e[maxm << 1];
ll h[maxn], tot, n, m, gap[maxn], last[maxn], d[maxn], que[maxn], ql, qr;
vector<ll> inv[maxn];
void add(ll u, ll v, ll w)
{
    e[++tot] = (edge){v, w, h[u]};
    h[u] = tot;
    e[++tot] = (edge){u, 0, h[v]};
    h[v] = tot;
}
void init(ll s, ll t)
{
    memset(gap, 0, sizeof gap), memset(d, 0, sizeof d), ++gap[d[t] = 1];
    for (ll i = 1; i <= n; ++i)
        last[i] = h[i];
    que[ql = qr = 1] = t;
    while (ql <= qr)
    {
        ll x = que[ql++];
        for (ll i = h[x], v = e[i].v; i; i = e[i].nxt, v = e[i].v)
            if (!d[v])
                ++gap[d[v] = d[x] + 1], que[++qr] = v;
    }
}
ll aug(ll x, ll s, ll t, ll mi)
{
    if (x == t)
        return mi;
    ll flow = 0;
    for (ll &i = last[x], v = e[i].v; i; i = e[i].nxt, v = e[i].v)
        if (d[x] == d[v] + 1)
        {
            ll tmp = aug(v, s, t, min(mi, e[i].w));
            flow += tmp, mi -= tmp, e[i].w -= tmp, e[i ^ 1].w += tmp;
            if (!mi)
                return flow;
        }
    if (!(--gap[d[x]]))
        d[s] = n + 1;
    ++gap[++d[x]], last[x] = h[x];
    return flow;
}
ll maxflow(ll s, ll t)
{
    init(s, t);
    ll ret = aug(s, s, t, inf);
    while (d[s] <= n)
        ret += aug(s, s, t, inf);
    return ret;
}
int main()
{
    ll s, t;
    scanf("%lld%lld%lld%lld", &n, &m, &s, &t);
    tot = 1,
    memset(h, 0, sizeof h);
    for (ll i = 1; i <= n; ++i)
        inv[i].clear();
    for (ll i = 1; i <= m; ++i)
    {
        ll u = read(), v = read(), w = read();
        add(u, v, w);
        if (w)
            inv[v].push_back(u);
    }
    ll ans = maxflow(s, t);
    printf("%lld\n", ans);
    //system("pause");
    return 0;
}