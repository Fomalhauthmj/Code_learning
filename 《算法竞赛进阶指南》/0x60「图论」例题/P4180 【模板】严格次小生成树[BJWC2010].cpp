#include <algorithm>
#include <iostream>
#include <math.h>
#include <queue>
#include <stdio.h>
using namespace std;
const int N = 1e5 + 50;
const int M = 6e5 + 50;
#define ll long long
#define pii pair<int, int>
#define inf 0x3f3f3f3f
int n, m, k, F[N][20], d[N], fa[N];
int head[N], ver[M], nxt[M], edge[M], tot;
ll G[N][20][2];
void add(int x, int y, int z)
{
    ver[++tot] = y, nxt[tot] = head[x], head[x] = tot, edge[tot] = z;
}
struct edge
{
    int x, y, z;
    bool used;
    bool operator<(const edge &e) const
    {
        return z < e.z;
    }
} e[M];
int Find(int x)
{
    if (fa[x] == x)
        return x;
    return fa[x] = Find(fa[x]);
}
ll Kruskal()
{
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    sort(e + 1, e + 1 + m);
    ll ans = 0;
    int cnt = 0;
    for (int i = 1; i <= m; i++)
    {
        int fx = Find(e[i].x), fy = Find(e[i].y);
        if (fx != fy)
        {
            fa[fx] = fy;
            ans += e[i].z;
            e[i].used = true;
            cnt++;
            if (cnt >= n - 1)
                break;
        }
    }
    return ans;
}
void BFS()
{
    k = log2(n) + 1;
    queue<int> q;
    q.push(1), d[1] = 1;
    for (int i = 0; i <= k; i++)
        G[1][i][0] = G[1][i][1] = -inf;
    while (q.size())
    {
        int x = q.front();
        q.pop();
        for (int i = head[x]; i; i = nxt[i])
        {
            int y = ver[i];
            if (!d[y])
            {
                d[y] = d[x] + 1;
                F[y][0] = x;
                G[y][0][0] = edge[i];
                G[y][0][1] = -inf;
                for (int j = 1; j <= k; j++)
                {
                    F[y][j] = F[F[y][j - 1]][j - 1];
                    G[y][j][0] = max(G[y][j - 1][0], G[F[y][j - 1]][j - 1][0]);
                    if (G[y][j - 1][0] == G[F[y][j - 1]][j - 1][0])
                        G[y][j][1] = max(G[y][j - 1][1], G[F[y][j - 1]][j - 1][1]);
                    else if (G[y][j - 1][0] > G[F[y][j - 1]][j - 1][0])
                        G[y][j][1] = max(G[F[y][j - 1]][j - 1][0], G[y][j - 1][1]);
                    else
                        G[y][j][1] = max(G[y][j - 1][0], G[F[y][j - 1]][j - 1][1]);
                }
                q.push(y);
            }
        }
    }
}
pii LCA(int x, int y)
{
    ll val1 = -inf, val2 = -inf;
    if (d[y] > d[x])
        swap(x, y);
    for (int i = k; i >= 0; i--)
    {
        if (d[F[x][i]] >= d[y])
        {
            if (G[x][i][0] > val1)
                val1 = G[x][i][0], val2 = max(val2, G[x][i][1]);
            else if (G[x][i][0] < val1)
                val2 = max(val2, G[x][i][0]);
            x = F[x][i];
        }
    }
    if (x == y)
        return make_pair(val1, val2);
    for (int i = k; i >= 0; i--)
    {
        if (F[x][i] != F[y][i])
        {
            val1 = max(val1, max(G[x][i][0], G[y][i][0]));
            val2 = max(val2, (val1 == G[x][i][0]) ? G[x][i][1] : G[x][i][0]);
            val2 = max(val2, (val1 == G[y][i][0]) ? G[y][i][1] : G[y][i][0]);
            x = F[x][i], y = F[y][i];
        }
    }
    val1 = max(val1, max(G[x][0][0], G[y][0][0]));
    val2 = max(val2, (val1 == G[x][0][0]) ? G[x][0][1] : G[x][0][0]);
    val2 = max(val2, (val1 == G[y][0][0]) ? G[y][0][1] : G[y][0][0]);
    return make_pair(val1, val2);
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
        scanf("%d%d%d", &e[i].x, &e[i].y, &e[i].z), e[i].used = false;
    ll sum = Kruskal(), ans = 0x3f3f3f3f3f3f3f3f;
    for (int i = 1; i <= m; i++)
        if (e[i].used)
            add(e[i].x, e[i].y, e[i].z), add(e[i].y, e[i].x, e[i].z);
    BFS();
    for (int i = 1; i <= m; i++)
    {
        if (!e[i].used)
        {
            pii temp = LCA(e[i].x, e[i].y);
            if (e[i].z > temp.first)
                ans = min(ans, sum - temp.first + e[i].z);
            else if (e[i].z == temp.first)
                ans = min(ans, sum - temp.second + e[i].z);
        }
    }
    cout << ans << endl;
    //system("pause");
    return 0;
}