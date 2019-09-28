#include <iostream>
#include <queue>
using namespace std;
#define ll long long
const int N = 1e4 + 50;
const int M = 1e6 + 50;
#define inf 0x3f3f3f3f
int head[N], ver[M], nxt[M], edge[M], tot;
int sze[N], dist[N], rt, max_part[N], sum;
int new_dist[N], cnt;
int n, m;
int query[N];
bool ans[N], vis[N], exist[1000 * N];
void add(int x, int y, int z)
{
    ver[++tot] = y, nxt[tot] = head[x], head[x] = tot, edge[tot] = z;
}
void calc_sze(int x, int fa)
{
    max_part[x] = 0, sze[x] = 1;
    for (int i = head[x]; i; i = nxt[i])
    {
        int y = ver[i];
        if (vis[y] || y == fa)
            continue;
        calc_sze(y, x);
        sze[x] += sze[y];
        max_part[x] = max(max_part[x], sze[y]);
    }
    max_part[x] = max(max_part[x], sum - sze[x]);
    if (max_part[x] < max_part[rt])
        rt = x;
}
void calc_dist(int x, int fa)
{
    new_dist[++cnt] = dist[x];
    for (int i = head[x]; i; i = nxt[i])
    {
        int y = ver[i];
        if (vis[y] || y == fa)
            continue;
        dist[y] = dist[x] + edge[i];
        calc_dist(y, x);
    }
}
void calc(int x)
{
    queue<int> new_exist;
    for (int i = head[x]; i; i = nxt[i])
    {
        int y = ver[i];
        if (vis[y])
            continue;
        cnt = 0, dist[y] = edge[i];
        calc_dist(y, x);
        for (int j = 1; j <= cnt; j++)
            for (int k = 0; k < m; k++)
                if (query[k] >= new_dist[j])
                    ans[k] |= exist[query[k] - new_dist[j]];
        for (int j = 1; j <= cnt; j++)
            new_exist.push(new_dist[j]), exist[new_dist[j]] = true;
    }
    while (new_exist.size())
        exist[new_exist.front()] = false, new_exist.pop();
}
void Solve(int x)
{
    vis[x] = true, exist[0] = true;
    calc(x);
    for (int i = head[x]; i; i = nxt[i])
    {
        int y = ver[i];
        if (vis[y])
            continue;
        sum = sze[y], max_part[rt = 0] = inf;
        calc_sze(y, x), Solve(rt);
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    int x, y, z;
    for (int i = 0; i < n - 1; i++)
        scanf("%d%d%d", &x, &y, &z), add(x, y, z), add(y, x, z);
    for (int i = 0; i < m; i++)
        scanf("%d", &query[i]);
    sum = n;
    max_part[rt = 0] = inf;
    calc_sze(1, 0);
    Solve(rt);
    for (int i = 0; i < m; i++)
        if (ans[i])
            printf("AYE\n");
        else
            printf("NAY\n");
    //system("pause");
    return 0;
}