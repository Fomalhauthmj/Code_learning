#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;
const int N = 1e6 + 50;
const int M = 1e6 + 50;
#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int, int>
int S, T, tot = 1;
int head[N], ver[M], nxt[M], edge[M], cost[M], dis[N], incf[N], pre[N];
bool vis[N];
void add(int x, int y, int z, int c)
{
    ver[++tot] = y, nxt[tot] = head[x], head[x] = tot, edge[tot] = z, cost[tot] = c;
    ver[++tot] = x, nxt[tot] = head[y], head[y] = tot, edge[tot] = 0, cost[tot] = -c;
}
bool SPFA_max()
{
    memset(dis, 0xcf, sizeof(dis)); //inf
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    dis[S] = 0, vis[S] = 1, incf[S] = 1 << 30;
    q.push(S);
    while (q.size())
    {
        int x = q.front();
        q.pop();
        vis[x] = 0;
        for (int i = head[x]; i; i = nxt[i])
        {
            if (edge[i])
            {
                int y = ver[i];
                if (dis[y] < dis[x] + cost[i])
                {
                    dis[y] = dis[x] + cost[i];
                    incf[y] = min(incf[x], edge[i]);
                    pre[y] = i;
                    if (!vis[y])
                        q.push(y), vis[y] = 1;
                }
            }
        }
    }
    if (dis[T] == 0xcfcfcfcf)
        return false;
    return true;
}
ll max_flow, ans;
void Update()
{
    int x = T;
    while (x != S)
    {
        int i = pre[x];
        edge[i] -= incf[T];
        edge[i ^ 1] += incf[T];
        x = ver[i ^ 1];
    }
    max_flow += incf[T];
    ans += incf[T] * dis[T];
}
int p[N << 1], pcnt;
pii q[505];
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    pcnt = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &q[i].first, &q[i].second);
        if (q[i].first > q[i].second)
            swap(q[i].first, q[i].second);
        p[++pcnt] = q[i].first, p[++pcnt] = q[i].second;
    }
    sort(p + 1, p + 1 + pcnt);
    pcnt = unique(p + 1, p + 1 + pcnt) - (p + 1);
    S = 0, T = 2 * n + 1;
    add(S, 1, k, 0), add(pcnt, T, k, 0);
    for (int i = 1; i < pcnt; i++)
        add(i, i + 1, inf, 0);
    for (int i = 1; i <= n; i++)
    {
        int u = lower_bound(p + 1, p + 1 + pcnt, q[i].first) - p;
        int v = lower_bound(p + 1, p + 1 + pcnt, q[i].second) - p;
        add(u, v, 1, q[i].second - q[i].first);
    }
    max_flow = ans = 0;
    while (SPFA_max())
        Update();
    printf("%lld\n", ans);
    //system("pause");
    return 0;
}