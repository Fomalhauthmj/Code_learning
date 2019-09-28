#include <algorithm>
#include <cstring>
#include <iostream>
#include <stdio.h>
using namespace std;
const int N = 1e4 + 50;
const int M = 5e4 + 50;
int head[N], ver[M], nxt[M], edge[M], tot;
int sze[N], dist[N], rt, max_part[N], sum;
int new_dist[N], cnt;
int n, k, ans;
bool vis[N];
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
int calc(int x, int z)
{
    cnt = 0, dist[x] = z, calc_dist(x, 0);
    sort(new_dist + 1, new_dist + 1 + cnt);
    int l = 1, r = cnt, ret = 0;
    while (l <= r)
        (new_dist[l] + new_dist[r] <= k) ? (ret += r - l, l++) : r--;
    return ret;
}
void Solve(int x)
{
    vis[x] = true;
    ans += calc(x, 0);
    for (int i = head[x]; i; i = nxt[i])
    {
        int y = ver[i];
        if (vis[y])
            continue;
        ans -= calc(y, edge[i]);
        sum = max_part[rt = 0] = sze[y];
        calc_sze(y, x), Solve(rt);
    }
}
int main()
{
    while (scanf("%d%d", &n, &k) && n + k)
    {
        tot = 0, ans = 0;
        memset(vis, 0, sizeof(vis));
        memset(head, 0, sizeof(head));
        int x, y, z;
        for (int i = 0; i < n - 1; i++)
            scanf("%d%d%d", &x, &y, &z), add(x, y, z), add(y, x, z);
        sum = max_part[rt = 0] = n;
        calc_sze(1, 0);
        Solve(rt);
        printf("%d\n", ans);
    }
    return 0;
}
/*
7 10
1 6 13 
6 3 9 
3 5 7 
4 1 3 
2 4 20 
4 7 2 
=5
5 4
1 2 3
1 3 1
1 4 2
3 5 1
=8
*/