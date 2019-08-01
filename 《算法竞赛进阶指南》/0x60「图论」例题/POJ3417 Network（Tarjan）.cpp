#include <cstring>
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
const int N = 1E5 + 50;
#define pii pair<int, int>
int n, m, head[N], nxt[N << 1], ver[N << 1], tot = 0;
int w[N], dp[N], lca[N], fa[N]; //f[x] x与父结点的树边被覆盖次数   以x为根的子树 各结点权值和
int vis[N];
vector<pii> q[N];
pii Q[N];
void add(int u, int v)
{
    ver[++tot] = v;
    nxt[tot] = head[u];
    head[u] = tot;
}
int Find(int x)
{
    if (x == fa[x])
        return x;
    return fa[x] = Find(fa[x]);
}
void Tarjan(int x)
{
    vis[x] = 1;
    for (int i = head[x]; i; i = nxt[i])
    {
        int y = ver[i];
        if (!vis[y])
        {
            Tarjan(y);
            fa[y] = x;
        }
    }
    for (int i = 0; i < q[x].size(); i++)
    {
        int y = q[x][i].first, id = q[x][i].second;
        if (vis[y] == 2)
            lca[id] = Find(y);
    }
    vis[x] = 2;
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
int main()
{
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &a, &b);
        if (a == b)
            lca[i] = a;
        else
        {
            q[a].push_back({b, i});
            q[b].push_back({a, i});
        }
        Q[i].first = a, Q[i].second = b;
    }
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    Tarjan(1);
    for (int i = 1; i <= m; i++)
    {
        w[Q[i].first]++;
        w[Q[i].second]++;
        w[lca[i]] -= 2;
    }
    memset(vis, 0, sizeof(vis));
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