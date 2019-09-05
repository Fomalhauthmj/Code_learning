#include <cstring>
#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;
const int N = 2e5 + 50;
const int M = 1e6 + 50;
#define inf 0x3f3f3f3f
int n, k, a, b, c;
int grid[105][105];
int head[N], ver[M], nxt[M], edge[M], tot;
int dis[N];
bool vis[N];
void add(int x, int y, int z)
{
    ver[++tot] = y, nxt[tot] = head[x], head[x] = tot, edge[tot] = z;
}
bool Judge(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > n)
        return false;
    return true;
}
int H(int x, int y, int oil)
{
    return (x - 1) * n + y + oil * n * n;
}
void SPFA(int S)
{
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    dis[S] = 0;
    vis[S] = 1;
    q.push(S);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        vis[x] = 0;
        for (int i = head[x]; i; i = nxt[i])
        {
            int y = ver[i], z = edge[i];
            if (dis[y] > dis[x] + z)
            {
                dis[y] = dis[x] + z;
                if (!vis[y])
                    q.push(y), vis[y] = 1;
            }
        }
    }
}
int main()
{
    scanf("%d%d%d%d%d", &n, &k, &a, &b, &c);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &grid[i][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int t = k; t >= 0; t--) //cur oil
            {
                if (grid[i][j])
                {
                    add(H(i, j, t), H(i, j, k), a);
                    if (Judge(i - 1, j))
                        add(H(i, j, k), H(i - 1, j, k - 1), b);
                    if (Judge(i, j - 1))
                        add(H(i, j, k), H(i, j - 1, k - 1), b);
                    if (Judge(i + 1, j))
                        add(H(i, j, k), H(i + 1, j, k - 1), 0);
                    if (Judge(i, j + 1))
                        add(H(i, j, k), H(i, j + 1, k - 1), 0);
                }
                else
                {
                    add(H(i, j, t), H(i, j, k), c + a);
                    if (t)
                    {
                    if (Judge(i - 1, j))
                        add(H(i, j, t), H(i - 1, j, t - 1), b);
                    if (Judge(i, j - 1))
                        add(H(i, j, t), H(i, j - 1, t - 1), b);
                    if (Judge(i + 1, j))
                        add(H(i, j, t), H(i + 1, j, t - 1), 0);
                    if (Judge(i, j + 1))
                        add(H(i, j, t), H(i, j + 1, t - 1), 0);
                    }
                }
            }
    SPFA(H(1, 1, k));
    int ans = inf;
    for (int i = 0; i <= k; i++)
        ans = min(ans, dis[H(n, n, i)]);
    printf("%d\n", ans);
    //system("pause");
    return 0;
}