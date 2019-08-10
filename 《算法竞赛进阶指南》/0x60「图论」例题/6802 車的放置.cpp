#include <cstring>
#include <iostream>
using namespace std;
const int N = 500;
const int M = 1e5 + 20;
int n, m;
bool invalid[N][N], vis[N];
int head[N], ver[M], nxt[M], tot;
int match[N];
void add(int u, int v)
{
    ver[++tot] = v, nxt[tot] = head[u], head[u] = tot;
}
bool DFS(int x)
{
    for (int i = head[x]; i; i = nxt[i])
    {
        int y = ver[i];
        if (!vis[y])
        {
            vis[y] = 1;
            if (!match[y] || DFS(match[y]))
            {
                match[y] = x;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> n >> m >> t;
    int x, y;
    for (int i = 0; i < t; i++)
    {
        cin >> x >> y;
        invalid[x][y] = true;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (!invalid[i][j])
            {
                add(i, n + j), add(n + j, i);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        memset(vis, 0, sizeof(vis));
        if(DFS(i))
            ans++;
    }
    cout << ans << endl;
    system("pause");
    return 0;
}