#include <cstring>
#include <iostream>
using namespace std;
const int N = 3e5 + 50;
const int M = 2e6 + 50;
#define ll long long
#define mod 998244353
ll n, m, ans, rest;
ll p[N];
int ver[M], nxt[M], head[N], tot;
void add(int x, int y)
{
    ver[++tot] = y, nxt[tot] = head[x], head[x] = tot;
}
int vis[N], cnt[N];
void Init()
{
    p[0] = 1;
    for (int i = 1; i < N; i++)
        p[i] = p[i - 1] * 2 % mod;
}
void DFS(int x, int temp, int father)
{
    vis[x] = 1;
    cnt[x] = temp;
    for (int i = head[x]; i; i = nxt[i])
    {
        int y = ver[i];
        if (y == father)
            continue;
        if (vis[y] == 0)
            DFS(y, temp + 1, x);
        else if (vis[y] == 1)
        {
            int t = cnt[x] - cnt[y] + 1;
            rest -= t;
            ans = (ans * (p[t] - 1) + mod) % mod;
        }
    }
    vis[x] = 2;
}
int main()
{
    Init();
    tot = 0;
    memset(head, 0, sizeof(head));
    memset(vis, 0, sizeof(vis));
    memset(cnt, 0, sizeof(cnt));
    scanf("%lld%lld", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        add(x, y), add(y, x);
    }
    ans = 1;
    rest = m;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            DFS(i, 0, 0);
    }
    ans = ans * p[rest] % mod;
    printf("%lld\n", ans);
    //system("pause");
    return 0;
}
/*
3 3
1 2
2 3
3 1

6 6
1 2
2 3
3 1
2 4
4 5
5 2
*/