#include <bits/stdc++.h>
using namespace std;
const int N = 105;
#define ll long long
#define inf 0x3f3f3f3f
int n, m;
int a[N][N], dis[N][N];
void Floyd()
{
    memcpy(dis, a, sizeof(dis));
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                ll temp = dis[i][k] + dis[k][j];
                if (dis[i][j] > temp)
                    dis[i][j] = temp;
            }
        }
    }
}
const int M = 3e6;
int S, T;
int ver[M], nxt[M], head[M], edge[M], tot = 1, d[M];
void add(int x, int y, int z)
{
    ver[++tot] = y, nxt[tot] = head[x], head[x] = tot, edge[tot] = z;
    ver[++tot] = x, nxt[tot] = head[y], head[y] = tot, edge[tot] = 0;
}
bool BFS()
{
    memset(d, 0, sizeof(d));
    queue<int> q;
    q.push(S);
    d[S] = 1; //不为1  陷入死循环
    while (q.size())
    {
        int x = q.front();
        q.pop();
        for (int i = head[x]; i; i = nxt[i])
        {
            int y = ver[i];
            if (edge[i] && !d[y])
            {
                d[y] = d[x] + 1;
                q.push(y);
                if (y == T)
                    return true;
            }
        }
    }
    return false;
}
int Dinic(int x, int flow)
{
    if (x == T)
        return flow;
    int rest = flow, k;
    for (int i = head[x]; i && rest; i = nxt[i])
    {
        int y = ver[i];
        if (edge[i] && d[y] == d[x] + 1)
        {
            k = Dinic(y, min(edge[i], rest));
            if (!k)
                d[y] = 0;
            edge[i] -= k;
            edge[i ^ 1] += k;
            rest -= k;
        }
    }
    return flow - rest;
}
struct Spaceship
{
    int x, a, f;
} spaceship[N * 10];
struct Base
{
    int x, d;
} base[N * 10];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    memset(a, 0x3f, sizeof(a));
    for (int i = 0, u, v; i < m; i++)
        cin >> u >> v, a[u][v] = a[v][u] = 1;
    for (int i = 1; i <= n; i++)
        a[i][i] = 0;
    int s, b, k, h;
    cin >> s >> b >> k >> h;
    for (int i = 0; i < s; i++)
    {
        int x, a, f;
        cin >> x >> a >> f;
        spaceship[i] = {x, a, f};
    }
    for (int i = 0; i < b; i++)
    {
        int x, d;
        cin >> x >> d;
        base[i] = {x, d};
    }
    S = 0, T = 1e4;
    Floyd();
    for (int i = 0; i < b; i++)
        add(s + i + 1, T, 1);
    for (int i = 0; i < s; i++)
    {
        auto ss = spaceship[i];
        add(S, i + 1, 1);
        for (int j = 0; j < b; j++)
        {
            auto bs = base[j];
            if (dis[ss.x][bs.x] <= ss.f && ss.a >= bs.d)
                add(i + 1, s + j + 1, 1);
        }
    }
    int max_flow = 0, flow;
    while (BFS())
        while (flow = Dinic(S, inf))
            max_flow += flow;
    //cout << max_flow << endl;
    ll ans = min(1ll * max_flow * k, 1ll * s * h);
    /*
    k>h max_flow*k  h*s
    */
    cout << ans << endl;
    //system("pause");
    return 0;
}