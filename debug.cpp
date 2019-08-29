#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;
const int N = 1E5 + 50;
const int M = 2e5 + 50;
const int mod = 1e9 + 7;
#define ll long long
#define inf 0x3f3f3f3f
int head[N], ver1[M], ver2[M], nxt[M], edge[M], tot, in[N];
int head_r[N], ver1_r[M], nxt_r[M], tot_r, out[N], deg[N];
ll n, m, s, t, q;
ll fs[N], ft[N];
ll dis[N], ds[N], dt[N], bridge_sum[N];
bool bridge_start[N], bridge_end[N];
int pre[N], path[N], pcnt;
inline void add(int x, int y, int z)
{
    ver2[++tot] = x, ver1[tot] = y, edge[tot] = z, nxt[tot] = head[x], head[x] = tot, ++in[y];
    ver1_r[++tot_r] = x, nxt_r[tot_r] = head_r[y], head_r[y] = tot_r, ++out[x];
}
inline void Clear()
{
    for (int i = 1; i <= n; ++i)
        dis[i] = inf;
    memset(fs, 0, sizeof(fs));
    memset(ft, 0, sizeof(ft));
    memset(bridge_end, 0, sizeof(bridge_end));
    memset(bridge_start, 0, sizeof(bridge_start));
    memset(bridge_sum, 0, sizeof(bridge_sum));
    memset(ds, 0, sizeof(ds));
    memset(dt, 0, sizeof(dt));
    memset(head, 0, sizeof(head));
    memset(head_r, 0, sizeof(head_r));
    tot = tot_r = 0;
}
inline void Topo()
{
    memcpy(deg, in, sizeof(in));
    queue<int> q;
    fs[s] = 1;
    for (int i = 1; i <= n; ++i)
        if (!deg[i])
            q.push(i);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = head[x]; i; i = nxt[i])
        {
            int y = ver1[i];
            fs[y] = (fs[x] + fs[y]) % mod;
            if (!--deg[y])
                q.push(y);
        }
    }
    ft[t] = 1;
    for (int i = 1; i <= n; ++i)
        if (!out[i])
            q.push(i);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = head_r[x]; i; i = nxt_r[i])
        {
            int y = ver1_r[i];
            ft[y] = (ft[x] + ft[y]) % mod;
            if (!--out[y])
                q.push(y);
        }
    }
    for (int i = 1; i <= tot; ++i)
    {
        int x = ver2[i], y = ver1[i];
        if (fs[x] * ft[y] % mod == fs[t])
        {
            bridge_sum[y] = edge[i];
            bridge_end[y] = bridge_start[x] = 1;
        }
    }
}
void ShortPath()
{
    queue<int> q;
    for (int i = 1; i <= n; ++i)
        if (!in[i])
            q.push(i);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = head[x]; i; i = nxt[i])
        {
            int y = ver1[i], z = edge[i];
            if (dis[y] > dis[x] + z)
            {
                dis[y] = dis[x] + z;
                pre[y] = x;
            }
            if (!--in[y])
                q.push(y);
        }
    }
}
void Solve()
{
    int cur = 1;
    for (int i = 1; i <= pcnt; ++i)
    {
        while (dis[path[i]] - dis[path[cur]] > q)
            ++cur;
        ll temp = bridge_sum[path[i]] - bridge_sum[path[cur]];
        if (bridge_end[path[cur]])
            temp += q - (dis[path[i]] - dis[path[cur]]);
        ds[i] = max(ds[i - 1], temp);
    }
    cur = pcnt;
    for (int i = pcnt; i >= 1; --i)
    {
        while (dis[path[cur]] - dis[path[i]] > q)
            --cur;
        ll temp = bridge_sum[path[cur]] - bridge_sum[path[i]];
        if (bridge_start[path[cur]])
            temp += q - (dis[path[cur]] - dis[path[i]]);
        dt[i] = max(dt[i + 1], temp);
    }
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> m >> s >> t >> q;
        ++s, ++t;
        Clear();
        for (int i = 1; i <= m; ++i)
        {
            int x, y, z;
            cin >> x >> y >> z;
            ++x, ++y;
            add(x, y, z);
        }
        Topo();
        dis[s] = 0;
        ShortPath();
        if (dis[t] == inf)
            puts("-1");
        else
        {
            pcnt = 0;
            int p = t;
            do
            {
                path[++pcnt] = p;
                p = pre[p];
            } while (p != s);
            path[++pcnt] = s;
            reverse(path + 1, path + pcnt + 1);
            for (int i = 1; i <= pcnt; ++i)
                bridge_sum[path[i]] += bridge_sum[path[i - 1]];
            Solve();
            ll temp = bridge_sum[path[pcnt]], ans = inf;
            for (int i = 1; i <= pcnt; ++i)
                ans = min(ans, temp - (ds[i] + dt[i]));
            printf("%lld\n", ans);
        }
    }
    return 0;
}