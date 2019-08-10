#include <cstring>
#include <iostream>
using namespace std;
const int N = 105;
int n, t;
bool invalid[N][N], vis[N * N];
int match[N * N];
int head[N * N], ver[N * N * 8], nxt[N * N * 8], tot;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
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
bool Judge(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > n || invalid[x][y])
        return false;
    return true;
}
inline int Pos(int x, int y)
{
    return x * n + y;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> t;
    int x, y;
    for (int i = 0; i < t; i++)
    {
        cin >> x >> y;
        invalid[x][y] = true;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (!invalid[i][j])
            {
                for (int k = 0; k < 4; k++)
                {
                    int nx = i + dir[k][0], ny = j + dir[k][1];
                    if (Judge(nx, ny))
                        add(Pos(i, j), Pos(nx, ny)), add(Pos(nx, ny), Pos(i, j));
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (!invalid[i][j]&&((i + j) & 1))
            {
                memset(vis, 0, sizeof(vis));
                if (DFS(Pos(i, j)))
                    ans++;
            }
        }
    }
    cout << ans << endl;
    system("pause");
    return 0;
}
/*
4 6
1 3
1 4
2 1 
2 3 
4 2
4 4
 */