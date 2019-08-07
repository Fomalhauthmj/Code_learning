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
int head[N], ver1[M], ver2[M], nxt[M], edge[M], tot = 1, in_degree[N];
int hr[N], vr[M], nr[M], er[M], tr = 1, indr[N];
int n, m, s, t, q;
ll fs[N], ft[N];
int dis[N], ds[N], dt[N], point[N], pcnt, bridge_sum[N];
bool vis[N], bridge[M], bridge_start[N], bridge_end[N];
pii path[N];
vector<int> shortpath;
void add(int u, int v, int w)
{
    ver1[++tot] = v, ver2[tot] = u, nxt[tot] = head[u], head[u] = tot, edge[tot] = w, in_degree[v]++;
    vr[++tr] = u, nr[tr] = hr[v], hr[v] = tr, er[tr] = w, indr[u]++;
}
void Init()
{
}
void Topo()
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (!in_degree[i])
            q.push(i), fs[i] = 1;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = head[x]; i; i = nxt[i])
        {
            int y = ver1[i];
            fs[y] = (fs[y] + fs[x]) % MOD;
            in_degree[y]--;
            if (!in_degree[y])
                q.push(y);
        }
    }
    for (int i = 1; i <= n; i++)
        if (!indr[i])
            q.push(i), ft[i] = 1;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = hr[x]; i; i = nr[i])
        {
            int y = vr[i];
            ft[y] = (ft[y] + ft[x]) % MOD;
            indr[y]--;
            if (!indr[y])
                q.push(y);
        }
    }
    for (int i = 2; i <= tot; i++)
    {
        int y = ver1[i], x = ver2[i];
        if (fs[x] * ft[y] == fs[t])
            bridge[i] = true;
    }
}
void Dijkstra(int s, int t)
{
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dis[s] = 0;
    pq.push({0, s});
    while (!pq.empty())
    {
        int x = pq.top().second;
        pq.pop();
        if (!vis[x])
        {
            vis[x] = 1;
            for (int i = head[x]; i; i = nxt[i])
            {
                int y = ver1[i];
                if (dis[y] > dis[x] + edge[i])
                {
                    dis[y] = dis[x] + edge[i];
                    path[y] = {x, i};
                    pq.push({dis[y], y});
                }
            }
        }
    }
    shortpath.clear();
    int y = t;
    while (y != s)
    {
        shortpath.push_back(path[y].second);
        y = path[y].first;
    };
    reverse(shortpath.begin(), shortpath.end());
    for (int i = 0; i < shortpath.size(); i++)
    {
        int it = shortpath[i];
        //cout << ver2[it] << "->" << ver1[it] << ":" << edge[it] << endl;
        if (!i)
            point[++pcnt] = ver2[it];
        point[++pcnt] = ver1[it];
        if (bridge[it])
            bridge_sum[pcnt] = bridge_sum[pcnt - 1] + edge[it], bridge_start[pcnt - 1] = bridge_end[pcnt] = true;
        else
            bridge_sum[pcnt] = bridge_sum[pcnt - 1];
    }
}
void Solve()
{
    int cur = 1;
    for (int i = 1; i <= pcnt; i++)
    {
        //cout << point[i] << " " << bridge_sum[i] << endl;
        while (dis[point[i]] - dis[point[cur]] > q)
            cur++;
        int temp = bridge_sum[i] - bridge_sum[cur];
        //q范围内的桥长度
        if (bridge_end[cur]) //cur点为桥的结束点
            temp += q - (dis[point[i]] - dis[point[cur]]);
        ds[i] = max(ds[i - 1], temp);
    }
    cur = pcnt;
    for (int i = pcnt; i >= 1; i--)
    {
        while (dis[point[cur]] - dis[point[i]] > q)
            cur--;
        int temp = bridge_sum[cur] - bridge_sum[i];
        if (bridge_start[cur])
            temp += q - (dis[point[cur]] - dis[point[i]]);
        dt[i] = max(dt[i + 1], temp);
    }
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        Init();
        scanf("%d%d%d%d%d", &n, &m, &s, &t, &q);
        int u, v, w;
        for (int i = 0; i < m; i++)
            scanf("%d%d%d", &u, &v, &w), add(u + 1, v + 1, w);
        Topo();
        Dijkstra(s + 1, t + 1);
        Solve();
        int ans = inf;
        for (int i = 1; i <= pcnt; i++)
            ans = min(ans, bridge_sum[pcnt] - ds[i] - dt[i]);
        cout << ans << endl;
    }
    system("pause");
    return 0;
}