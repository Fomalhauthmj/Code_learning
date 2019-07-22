#include <cstring>
#include <iostream>
#include <stdio.h>
using namespace std;
const int N = 2e5 + 50;
int n;
int head[N], deg[N], ver[2 * N], nxt[2 * N], edge[2 * N], tot = 0;
int d[N], f[N];
bool vis[N];
void add(int x, int y, int z)
{
    ver[++tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
    edge[tot] = z;
    deg[x]++;
}
void DP(int rt)
{
    d[rt] = 0;
    vis[rt] = 1;
    for (int i = head[rt]; i; i = nxt[i])
    {
        int s = ver[i];
        if (!vis[s]) //避免重复访问
        {
            DP(s);
            if (deg[s] != 1)
                d[rt] += min(d[s], edge[i]);
            else
                d[rt] += edge[i];
        }
    }
}
void DFS(int rt)
{
    vis[rt] = 1;
    for (int i = head[rt]; i; i = nxt[i])
    {
        int s = ver[i];
        if (!vis[s]) //避免重复访问
        {
            if (deg[rt] != 1)
                f[s] = d[s] + min(edge[i], f[rt] - min(edge[i], d[s]));
            else
                f[s] = d[s] + edge[i];
            DFS(s);
        }
    }
}
void Init()
{
    tot = 0;
    memset(deg, 0, sizeof(deg));
    memset(head, 0, sizeof(head));
}
int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int t, x, y, z;
    cin >> t;
    while (t--)
    {
        cin >> n;
        Init();
        for (int i = 0; i < n - 1; i++)
        {
            //cin >> x >> y >> z;
            scanf("%d%d%d", &x, &y, &z);
            add(x, y, z);
            add(y, x, z);
        }
        int root = 1;
        memset(vis, 0, sizeof(vis));
        DP(root);
        memset(vis, 0, sizeof(vis));
        f[root] = d[root];
        DFS(root);
        int ans = 0;
        for (int i = 1; i <= n; i++)
            ans = max(ans, f[i]);
        cout << ans << endl;
    }
    system("pause");
    return 0;
}