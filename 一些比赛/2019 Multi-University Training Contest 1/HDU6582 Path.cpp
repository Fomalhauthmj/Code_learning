#include <cstring>
#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;
const int N = 1E4 + 50;
const int M = 5E4 + 50;
#define ll long long
#define pli pair<long long, int>
#define inf 0x3f3f3f3f3f3f3f3f
ll head[N], ver[M], nxt[M], edge[M], tot;
ll hc[N], vc[M], nc[M], ec[M], tc;
ll dis[N];
int n, m;
bool vis[N];
void add(int u, int v, int w)
{
    ver[++tot] = v, nxt[tot] = head[u], head[u] = tot, edge[tot] = w;
}
void add_c(int u, int v, int w)
{
    vc[++tc] = v, nc[tc] = hc[u], hc[u] = tc, ec[tc] = w;
}
void Init()
{
    memset(head, 0, sizeof(head));
    memset(hc, 0, sizeof(hc));
    tot = tc = 1;
}
void Dijkstra()
{
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    pq.push({0, 1});
    dis[1] = 0;
    while (!pq.empty())
    {
        int x = pq.top().second;
        pq.pop();
        if (vis[x])
            continue;
        vis[x] = 1;
        for (int i = head[x]; i; i = nxt[i])
        {
            int y = ver[i];
            if (dis[y] > dis[x] + edge[i])
            {
                dis[y] = dis[x] + edge[i];
                pq.push({dis[y], y});
            }
        }
    }
}
void Build()
{
    for (int x = 1; x <= n; x++)
    {
        for (int i = head[x]; i; i = nxt[i])
        {
            int y = ver[i];
            if (dis[y] == dis[x] + edge[i])
            {
                add_c(x, y, edge[i]);
                add_c(y, x, 0);
            }
        }
    }
}
int s, t;
ll d[N];
bool BFS()
{ // 在残量网络上构造分层图
    memset(d, 0, sizeof(d));
    queue<int> q;
    q.push(s);
    d[s] = 1;
    while (q.size())
    {
        int x = q.front();
        q.pop();
        for (int i = hc[x]; i; i = nc[i])
        {
            int y = vc[i];
            if (ec[i] && !d[y])
            {
                q.push(y);
                d[y] = d[x] + 1;
                if (y == t)
                    return 1;
            }
        }
    }
    return 0;
}

ll Dinic(int x, ll flow)
{ // 在当前分层图上增广
    if (x == t)
        return flow;
    ll rest = flow, k;
    for (int i = hc[x]; i && rest; i = nc[i])
    {
        int y = vc[i];
        if (ec[i] && d[y] == d[x] + 1)
        {
            k = Dinic(y, min(rest, ec[i]));
            if (!k)
                d[y] = 0; // 剪枝，去掉增广完毕的点
            ec[i] -= k;
            ec[i ^ 1] += k;
            rest -= k;
        }
    }
    return flow - rest;
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        Init();
        scanf("%d%d", &n, &m);
        int x, y, c;
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d%d", &x, &y, &c);
            add(x, y, c);
        }
        Dijkstra();
        if (dis[n] == inf)
            cout << 0 << endl;
        else
        {
            Build();
            s = 1, t = n;
            ll flow, maxflow = 0;
            while (BFS())
                while (flow = Dinic(s, inf))
                    maxflow += flow;
            cout << maxflow << endl;
        }
    }
    system("pause");
    return 0;
}