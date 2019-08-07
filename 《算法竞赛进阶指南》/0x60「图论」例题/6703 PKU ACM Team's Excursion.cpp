//http://poj.openjudge.cn/practice/1044
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <stdio.h>
#include <vector>
using namespace std;
const int N = 1E5 + 50;
const int M = 2e5 + 50;
const int MOD = 1e9 + 7;
#define pii pair<int, int>
#define ll long long
#define inf 0x3f3f3f3f
ll head[N], ver1[M], ver2[M], nxt[M], edge[M], tot = 1, in_degree[N];
ll hr[N], vr[M], nr[M], er[M], tr = 1, indr[N];
ll n, m, s, t, q;
ll fs[N], ft[N];
ll dis[N], ds[N], dt[N], point[N], pcnt, bridge_sum[N];
bool vis[N], bridge[M], bridge_start[N], bridge_end[N];
pii path[N];
vector<ll> shortpath;
void add(ll u, ll v, ll w)
{
    ver1[++tot] = v, ver2[tot] = u, nxt[tot] = head[u], head[u] = tot, edge[tot] = w, in_degree[v]++;
    vr[++tr] = u, nr[tr] = hr[v], hr[v] = tr, er[tr] = w, indr[u]++;
}
void Init()
{
    tot = 1, tr = 1;
    pcnt = 0;
    memset(bridge, 0, sizeof(bridge));
    for (ll i = 0; i < N; i++)
        head[i] = hr[i] = in_degree[i] = indr[i] = fs[i] = ft[i] = ds[i] = dt[i] = bridge_sum[i] = bridge_start[i] = bridge_end[i] = 0;
}
void Topo()
{
    queue<ll> q;
    for (ll i = 1; i <= n; i++)
        if (!in_degree[i])
            q.push(i);
    fs[s] = 1;
    while (!q.empty())
    {
        ll x = q.front();
        q.pop();
        for (ll i = head[x]; i; i = nxt[i])
        {
            ll y = ver1[i];
            fs[y] = (fs[y] + fs[x]) % MOD;
            in_degree[y]--;
            if (!in_degree[y])
                q.push(y);
        }
    }
    for (ll i = 1; i <= n; i++)
        if (!indr[i])
            q.push(i);
    ft[t] = 1;
    while (!q.empty())
    {
        ll x = q.front();
        q.pop();
        for (ll i = hr[x]; i; i = nr[i])
        {
            ll y = vr[i];
            ft[y] = (ft[y] + ft[x]) % MOD;
            indr[y]--;
            if (!indr[y])
                q.push(y);
        }
    }
    for (ll i = 2; i <= tot; i++)
    {
        ll y = ver1[i], x = ver2[i];
        if (fs[x] * ft[y] % MOD == fs[t])
            bridge[i] = true, bridge_start[x] = bridge_end[y] = true;
    }
}
bool Dijkstra(ll s, ll t)
{
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dis[s] = 0;
    pq.push({0, s});
    while (!pq.empty())
    {
        ll x = pq.top().second;
        pq.pop();
        if (!vis[x])
        {
            vis[x] = 1;
            for (ll i = head[x]; i; i = nxt[i])
            {
                ll y = ver1[i];
                if (dis[y] > dis[x] + edge[i])
                {
                    dis[y] = dis[x] + edge[i];
                    path[y] = {x, i};
                    pq.push({dis[y], y});
                }
            }
        }
    }
    if (dis[t] == inf)
        return false;
    shortpath.clear();
    ll y = t;
    while (y != s)
    {
        shortpath.push_back(path[y].second);
        y = path[y].first;
    };
    reverse(shortpath.begin(), shortpath.end());
    for (ll i = 0; i < shortpath.size(); i++)
    {
        ll it = shortpath[i];
        //cout << ver2[it] << "->" << ver1[it] << ":" << edge[it] << endl;
        if (!i)
            point[++pcnt] = ver2[it];
        point[++pcnt] = ver1[it];
        if (bridge[it])
            bridge_sum[pcnt] = bridge_sum[pcnt - 1] + edge[it];
        else
            bridge_sum[pcnt] = bridge_sum[pcnt - 1];
    }
    return true;
}
void Solve()
{
    ll cur = 1;
    for (ll i = 1; i <= pcnt; i++)
    {

        //ds[i] 表示从S到最短路上第i个节点 覆盖一次 的最大覆盖长度
        while (dis[point[i]] - dis[point[cur]] > q)
            cur++;//超过范围 开始点后移
        ll temp = bridge_sum[i] - bridge_sum[cur];
        //cur-i范围内的桥总长度  temp<=dis[point[i]]-dis[point[cur]]<=q
        if (bridge_end[point[cur]]) //若cur点为桥的结束点 开始尝试从i点开始往前覆盖 画图理解
            temp += q - (dis[point[i]] - dis[point[cur]]);
        ds[i] = max(ds[i - 1], temp);
    }
    cur = pcnt;
    for (ll i = pcnt; i >= 1; i--)
    {
        //dt[i] 表示从T到最短路上第i个节点 覆盖一次 的最大覆盖长度
        while (dis[point[cur]] - dis[point[i]] > q)
            cur--;
        ll temp = bridge_sum[cur] - bridge_sum[i];
        if (bridge_start[point[cur]])
            temp += q - (dis[point[cur]] - dis[point[i]]); //若cur点为桥的开始点 开始尝试从i点开始往后覆盖 是否可得到更大覆盖长度
        dt[i] = max(dt[i + 1], temp);
    }
}
int main()
{
    ll T;
    scanf("%lld", &T);
    while (T--)
    {
        Init();
        scanf("%lld%lld%lld%lld%lld", &n, &m, &s, &t, &q);
        ll u, v, w;
        for (ll i = 0; i < m; i++)
            scanf("%lld%lld%lld", &u, &v, &w), add(u + 1, v + 1, w);
        s++, t++;
        Topo();
        if (!Dijkstra(s, t))
        {
            cout << -1 << endl;
            continue;
        }
        Solve();
        ll ans = inf;
        for (ll i = 1; i <= pcnt; i++)
            ans = min(ans, bridge_sum[pcnt] - ds[i] - dt[i]);
        cout << ans << endl;
    }
    system("pause");
    return 0;
}