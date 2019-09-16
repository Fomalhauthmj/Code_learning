#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;
const int N = 1e5 + 50;
const int M = 1e5 + 50;
#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int, int>
int S, T, tot = 1;
ll head[N], ver[M], nxt[M], edge[M], cost[M], dis[N], incf[N], pre[N];
bool vis[N];
void add(ll x, ll y, ll z, ll c)
{
    ver[++tot] = y, nxt[tot] = head[x], head[x] = tot, edge[tot] = z, cost[tot] = c;
    ver[++tot] = x, nxt[tot] = head[y], head[y] = tot, edge[tot] = 0, cost[tot] = -c;
}
bool SPFA_max()
{
    for (int i = 0; i < N; i++)
        dis[i] = -inf;
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
    if (dis[T] == -inf)
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
int x[N << 1], xcnt;
struct line
{
    int x1, x2;
    ll z;
} ls[505];
ll Z(int x1, int y1, int x2, int y2)
{
    ll temp1 = x1 - x2;
    ll temp2 = y1 - y2;
    return sqrt(temp1 * temp1 + temp2 * temp2);
}
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    xcnt = 0;
    int x1, y1, x2, y2;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        ll z = Z(x1, y1, x2, y2);
        if (x1 > x2)
            swap(x1, x2);
        x1 <<= 1;
        x2 <<= 1;
        if (x1 == x2)
            x1--;
        ls[i] = {x1, x2, z};
        x[++xcnt] = x1, x[++xcnt] = x2;
    }
    sort(x + 1, x + 1 + xcnt);
    xcnt = unique(x + 1, x + 1 + xcnt) - (x + 1);
    S = 0, T = 2 * n + 1;
    add(S, 1, k, 0), add(xcnt, T, k, 0);
    for (int i = 1; i < xcnt; i++)
        add(i, i + 1, inf, 0);
    for (int i = 1; i <= n; i++)
    {
        int u = lower_bound(x + 1, x + 1 + xcnt, ls[i].x1) - x;
        int v = lower_bound(x + 1, x + 1 + xcnt, ls[i].x2) - x;
        add(u, v, 1, ls[i].z);
    }
    max_flow = ans = 0;
    while (SPFA_max())
        Update();
    printf("%lld\n", ans);
    //system("pause");
    return 0;
}