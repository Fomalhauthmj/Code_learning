#include <cstring>
#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;
const int N = 1e6 + 50;
const int M = 1e6 + 50;
#define inf 0x3f3f3f3f
#define ll long long
int m, n, S, T, tot = 1;
int head[N], ver[M], nxt[M], edge[M], cost[M], dis[N], incf[N], pre[N], edge_c[M];
bool vis[N];
void add(int x, int y, int z, int c)
{
    ver[++tot] = y, nxt[tot] = head[x], head[x] = tot, edge[tot] = z, cost[tot] = c;
    ver[++tot] = x, nxt[tot] = head[y], head[y] = tot, edge[tot] = 0, cost[tot] = -c;
}
bool SPFA_min()
{
    memset(dis, 0x3f, sizeof(dis)); //inf
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
                if (dis[y] > dis[x] + cost[i])
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
    if (dis[T] >= inf)
        return false;
    return true;
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
int a[105],b[105];
int main()
{
    S = 0, T = m + n + 1;
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; i++)
        scanf("%d", &a[i]), add(S, i, a[i], 0);
    for (int i = 1; i <= n; i++)
        scanf("%d", &b[i]), add(m + i, T, b[i], 0);
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1, c; j <= n; j++)
        {
            scanf("%d", &c), add(i, m + j,a[i], c);
        }
    }
    cout<<tot<<endl;
    memcpy(edge_c, edge, sizeof(edge_c));
    max_flow = 0, ans = 0;
    while (SPFA_min())
        Update();
    cout << max_flow << " " << ans << endl;
    for(int i=2;i<=tot;i+=2)
        cout<<edge[i]<<endl;
    /*
    max_flow = 0, ans = 0;
    while (SPFA_max())
        Update();
    cout << max_flow << " " << ans << endl;
    */
    system("pause");
    return 0;
}