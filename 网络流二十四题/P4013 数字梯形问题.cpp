#include <cstring>
#include <iostream>
#include<stdio.h>
#include <queue>
using namespace std;
const int N = 1e6 + 50;
const int M = 1e6 + 50;
#define inf 0x3f3f3f3f
int head[N], ver[M], nxt[M], edge[M], cost[M], tot = 1, dis[N], incf[N], pre[N];
int edge_c[M];
bool vis[N];
int m, n, num[105][105], S, T;
void add(int x, int y, int z, int c)
{
    ver[++tot] = y, nxt[tot] = head[x], head[x] = tot, edge[tot] = z, cost[tot] = c;
    ver[++tot] = x, nxt[tot] = head[y], head[y] = tot, edge[tot] = 0, cost[tot] = -c;
}
int H(int r, int c)
{
    return (r - 1) * (m + m + r - 2) / 2 + c;
}
bool SPFA()
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
int max_flow, ans;
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
int main()
{
    scanf("%d%d", &m, &n);
    int cnt = n * (m + m + n - 1) / 2;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m + i - 1; j++)
        {
            scanf("%d", &num[i][j]);
            add(H(i, j), H(i, j) + cnt, 1, num[i][j]);
        }
    }
    S = 0, T = cnt * 2 + 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m + i - 1; j++)
        {
            if (i == 1)
                add(S, H(i, j), 1, 0);
            if (i == n)
                add(H(i, j) + cnt, T, inf, 0);
            if (i != n)
                add(H(i, j) + cnt, H(i + 1, j), 1, 0), add(H(i, j) + cnt, H(i + 1, j + 1), 1, 0);
        }
    }
    max_flow = 0, ans = 0;
    memcpy(edge_c,edge,sizeof(edge_c));
    while (SPFA())
        Update();
    printf("%d\n",ans);
    memcpy(edge,edge_c,sizeof(edge));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m + i - 1; j++)
        {
            if (i != 1)
                add(H(i, j), H(i, j) + cnt, m - 1, num[i][j]);
        }
    }
    memcpy(edge_c,edge,sizeof(edge_c));
    max_flow=0,ans=0;
    while (SPFA())
        Update();
    printf("%d\n",ans);
    memcpy(edge,edge_c,sizeof(edge));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m + i - 1; j++)
        {
            if (i != n)
                add(H(i, j) + cnt, H(i + 1, j), m-1, 0), add(H(i, j) + cnt, H(i + 1, j + 1), m-1, 0);
        }
    }
    max_flow=0,ans=0;
    while (SPFA())
        Update();
    printf("%d\n",ans);
    //system("pause");
    return 0;
}