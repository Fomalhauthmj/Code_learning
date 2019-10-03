#include <iostream>
#include <queue>
using namespace std;
#define ll long long
const int N = 3e4 + 50;
const int M = 1e6 + 50;
#define inf 0x3f3f3f3f
int head[N], ver[M], nxt[M], edge[M], tot;
int sze[N], dist[N], rt, max_part[N], sum;
int new_dist[3];
int n;
ll ans = 0;
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
    new_dist[dist[x]]++;
    for (int i = head[x]; i; i = nxt[i])
    {
        int y = ver[i];
        if (vis[y] || y == fa)
            continue;
        dist[y] = (dist[x] + edge[i]) % 3;
        calc_dist(y, x);
    }
}
ll calc(int x, int z)
{
    //0+0 1+2 2+1
    new_dist[0] = new_dist[1] = new_dist[2] = 0;
    dist[x] = z, calc_dist(x, 0);
    return new_dist[0] * new_dist[0] + (new_dist[1] * new_dist[2]) * 2;
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
        ans -= calc(y, edge[i] % 3);
        sum = max_part[rt = 0] = sze[y];
        calc_sze(y, x), Solve(rt);
    }
}
ll GCD(ll a, ll b)
{
    if (b == 0)
        return a;
    else
        return GCD(b, a % b);
}
int main()
{
    scanf("%d", &n);
    int x, y, z;
    for (int i = 0; i < n - 1; i++)
        scanf("%d%d%d", &x, &y, &z), add(x, y, z), add(y, x, z);
    sum = n;
    max_part[rt = 0] = inf;
    calc_sze(1, 0);
    Solve(rt);
    ll path = n * n;
    ll t = GCD(ans, path);
    printf("%lld/%lld\n", ans / t, path / t);
    //system("pause");
    return 0;
}