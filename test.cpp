//http://poj.openjudge.cn/practice/1044
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;
const int N = 1E5 + 50;
const int M = 2e5 + 50;
const int MOD = 1e9 + 7;
#define ll long long
#define inf 0x3f3f3f3f
#define pii pair<int,int>
int head[N], ver1[M], ver2[M], nxt[M], edge[M], tot, in_degree[N];
int hr[N], vr[M], nr[M], er[M], tr, indr[N];
ll n, m, s, t, q;
ll fs[N], ft[N];
ll dis[N], ds[N], dt[N],bridge_sum[N];
bool vis[N],bridge_start[N], bridge_end[N];
int pre[N],path[N],pcnt;
void add(int u, int v, int w)
{
    ver1[++tot] = v, ver2[tot] = u, nxt[tot] = head[u], head[u] = tot, edge[tot] = w, in_degree[v]++;
    vr[++tr] = u, nr[tr] = hr[v], hr[v] = tr, er[tr] = w, indr[u]++;
}
void Init()
{
    tot=tr=pcnt = 0;
    for (int i = 0; i < N; i++)
        head[i] = hr[i] = in_degree[i] = indr[i] = fs[i] = ft[i] = ds[i] = dt[i] = bridge_sum[i] = bridge_start[i] = bridge_end[i] = 0;
}
void Topo()
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (!in_degree[i])
            q.push(i);
    fs[s] = 1;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = head[x]; i; i = nxt[i])
        {
            int y = ver1[i];
            fs[y] = (fs[y] + fs[x]) % MOD;
            if (--in_degree[y]==0)
                q.push(y);
        }
    }
    for (int i = 1; i <= n; i++)
        if (!indr[i])
            q.push(i);
    ft[t] = 1;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = hr[x]; i; i = nr[i])
        {
            int y = vr[i];
            ft[y] = (ft[y] + ft[x]) % MOD;
            if (--indr[y]==0)
                q.push(y);
        }
    }
    for (int i =1; i <= tot; i++)
    {
        ll y = ver1[i], x = ver2[i];
        if (fs[x] * ft[y] % MOD == fs[t])
            bridge_sum[y]=edge[i],bridge_start[x] = bridge_end[y] = true;
    }
}
bool Dijkstra(int s, int t)
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
                    pre[y] =x;
                    pq.push({dis[y], y});
                }
            }
        }
    }
    if (dis[t] == inf)
        return false;
    int y=t;
    do
    {
        path[++pcnt]=y;
        y = pre[y];
    } while (y!=s);
    path[++pcnt]=s;
    reverse(path+1,path+1+pcnt);
    for (ll i = 1; i <=pcnt; i++)
        bridge_sum[path[i]]+=bridge_sum[path[i-1]];
    return true;
}
void Solve()
{
    ll cur = 1;
    for (ll i = 1; i <= pcnt; i++)
    {

        //ds[i] 表示从S到最短路上第i个节点 覆盖一次 的最大覆盖长度
        while (dis[path[i]] - dis[path[cur]] > q)
            cur++;//超过范围 开始点后移
        ll temp = bridge_sum[path[i]] - bridge_sum[path[cur]];
        //cur-i范围内的桥总长度  temp<=dis[path[i]]-dis[path[cur]]<=q
        if (bridge_end[path[cur]]) //若cur点为桥的结束点 开始尝试从i点开始往前覆盖 画图理解
            temp += q - (dis[path[i]] - dis[path[cur]]);
        ds[i] = max(ds[i - 1], temp);
    }
    cur = pcnt;
    for (ll i = pcnt; i >= 1; i--)
    {
        //dt[i] 表示从T到最短路上第i个节点 覆盖一次 的最大覆盖长度
        while (dis[path[cur]] - dis[path[i]] > q)
            cur--;
        ll temp =  bridge_sum[path[cur]] - bridge_sum[path[i]];
        if (bridge_start[path[cur]])
            temp += q - (dis[path[cur]] - dis[path[i]]); //若cur点为桥的开始点 开始尝试从i点开始往后覆盖 是否可得到更大覆盖长度
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
            ans = min(ans, bridge_sum[path[pcnt]] - ds[i] - dt[i]);
        cout << ans << endl;
    }
    //system("pause");
    return 0;
}