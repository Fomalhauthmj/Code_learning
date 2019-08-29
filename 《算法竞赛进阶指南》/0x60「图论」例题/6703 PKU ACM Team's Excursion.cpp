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
#define pii pair<int, int>
int head[N], ver1[M], ver2[M], nxt[M], edge[M], tot, in[N];
int head_r[N], ver1_r[M], nxt_r[M],tot_r, out[N],deg[N];
ll n, m, s, t, q;
ll fs[N], ft[N];
ll dis[N], ds[N], dt[N], bridge_sum[N];
bool bridge_start[N], bridge_end[N];
int pre[N], path[N], pcnt;
void add(int u, int v, int w)
{
    ver1[++tot] = v, ver2[tot] = u, nxt[tot] = head[u], head[u] = tot, edge[tot] = w, in[v]++;
    ver1_r[++tot_r] = u, nxt_r[tot_r] = head_r[v], head_r[v] = tot_r,out[u]++;
}
void Init()
{
    tot = tot_r = pcnt = 0;
    memset(head,0,sizeof(head)),memset(head_r,0,sizeof(head_r));
    memset(in,0,sizeof(in)),memset(out,0,sizeof(out));
    memset(fs,0,sizeof(fs)),memset(ft,0,sizeof(ft));
    memset(ds,0,sizeof(ds)),memset(dt,0,sizeof(dt));
    memset(bridge_sum,0,sizeof(bridge_sum));
    memset(bridge_start,0,sizeof(bridge_start)),memset(bridge_end,0,sizeof(bridge_end));
}
void Topo()
{
    memcpy(deg,in,sizeof(deg));
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (!in[i])
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
            if (--in[y] == 0)
                q.push(y);
        }
    }
    for (int i = 1; i <= n; i++)
        if (!out[i])
            q.push(i);
    ft[t] = 1;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = head_r[x]; i; i = nxt_r[i])
        {
            int y = ver1_r[i];
            ft[y] = (ft[y] + ft[x]) % MOD;
            if (--out[y] == 0)
                q.push(y);
        }
    }
    for (int i = 1; i <= tot; i++)
    {
        int y = ver1[i], x = ver2[i];
        if (fs[x] * ft[y] % MOD == fs[t])
            bridge_sum[y] = edge[i], bridge_start[x] = bridge_end[y] = true;
    }
}
bool ShortPath(int s, int t)
{
    for(int i=1;i<=n;i++) dis[i]=inf;
    queue<int> q;
    dis[s] = 0;
    for(int i=1;i<=n;i++)
        if(!deg[i]) q.push(i);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = head[x]; i; i = nxt[i])
        {
            int y = ver1[i];
            if (dis[y] > dis[x] + edge[i])
            {
                dis[y] = dis[x] + edge[i];
                pre[y] = x;
            }
            if(--deg[y]==0) q.push(y);
        }
    }
    if (dis[t] == inf)
        return false;
    int y = t;
    do
    {
        path[++pcnt] = y;
        y = pre[y];
    } while (y != s);
    path[++pcnt] = s;
    reverse(path + 1, path + 1 + pcnt);
    for (int i = 1; i <= pcnt; i++)
        bridge_sum[path[i]] += bridge_sum[path[i - 1]];
    return true;
}
void Solve()
{
    int cur = 1;
    for (int i = 1; i <= pcnt; i++)
    {

        //ds[i] 表示从S到最短路上第i个节点 覆盖一次 的最大覆盖长度
        while (dis[path[i]] - dis[path[cur]] > q)
            cur++; //超过范围 开始点后移
        ll temp = bridge_sum[path[i]] - bridge_sum[path[cur]];
        //cur-i范围内的桥总长度  temp<=dis[path[i]]-dis[path[cur]]<=q
        if (bridge_end[path[cur]]) //若cur点为桥的结束点 开始尝试从i点开始往前覆盖 画图理解
            temp += q - (dis[path[i]] - dis[path[cur]]);
        ds[i] = max(ds[i - 1], temp);
    }
    cur = pcnt;
    for (int i = pcnt; i >= 1; i--)
    {
        //dt[i] 表示从T到最短路上第i个节点 覆盖一次 的最大覆盖长度
        while (dis[path[cur]] - dis[path[i]] > q)
            cur--;
        ll temp = bridge_sum[path[cur]] - bridge_sum[path[i]];
        if (bridge_start[path[cur]])
            temp += q - (dis[path[cur]] - dis[path[i]]); //若cur点为桥的开始点 开始尝试从i点开始往后覆盖 是否可得到更大覆盖长度
        dt[i] = max(dt[i + 1], temp);
    }
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        Init();
        cin >> n >> m >> s >> t >> q;
        int u, v, w;
        for (int i = 0; i < m; i++)
            scanf("%d%d%d", &u, &v, &w), add(u + 1, v + 1, w);
        s++, t++;
        Topo();
        if (!ShortPath(s, t))
        {
            cout << -1 << endl;
            continue;
        }
        Solve();
        ll ans = inf;
        for (int i = 1; i <= pcnt; i++)
            ans = min(ans, bridge_sum[path[pcnt]] - ds[i] - dt[i]);
        cout << ans << endl;
    }
    //system("pause");
    return 0;
}