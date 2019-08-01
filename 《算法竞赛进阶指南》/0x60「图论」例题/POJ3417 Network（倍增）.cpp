#include <iostream>
#include <math.h>
#include <queue>
#include <stdio.h>
#include <vector>
using namespace std;
const int N = 1E5 + 50;
int n, m, k, head[N], nxt[N << 1], ver[N << 1],tot=0;
int w[N], d[N], fa[N][20];
int dp[N]; //f[x] x与父结点的树边被覆盖次数   以x为根的子树 各结点权值和
bool vis[N];
void add(int u, int v)
{
    ver[++tot] = v;
    nxt[tot] = head[u];
    head[u] = tot;
}
void BFS()
{
    queue<int> q;
    q.push(1);
    d[1] = 1;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = head[x]; i; i = nxt[i])
        {
            int y = ver[i];
            if (!d[y])
            {
                d[y] = d[x] + 1;
                fa[y][0] = x;
                for (int j = 1; j <= k; j++)
                {
                    fa[y][j] = fa[fa[y][j - 1]][j - 1];
                }
                q.push(y);
            }
        }
    }
}
void DP(int x)
{
    vis[x] = 1;
    dp[x] = w[x];
    for (int i = head[x]; i; i = nxt[i])
    {
        int y = ver[i];
        if (!vis[y])
        {
            DP(y);
            dp[x] += dp[y];
        }
    }
}
int LCA(int x, int y)
{
    if (d[x] < d[y])
        swap(x, y);
    for (int i = k; i >= 0; i--)
        if (d[fa[x][i]] >= d[y])
            x = fa[x][i];
    if (x == y)
        return y;
    for (int i = k; i >= 0; i--)
        if (fa[x][i] != fa[y][i])
            x = fa[x][i], y = fa[y][i];
    return fa[x][0];
}
int main()
{
    cin >> n >> m;
    k = log2(n) + 1;
    int a, b;
    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }
    BFS();
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &a, &b);
        int lca = LCA(a, b);
        w[a]++, w[b]++, w[lca] -= 2;
    }
    DP(1);
    int ans = 0;
    for (int i = 2; i <= n; i++)
    {
        if (!dp[i])
            ans += m;
        else if (dp[i] == 1)
            ans += 1;
    }
    cout << ans << endl;
    //system("pause");
    return 0;
}