#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
#define inf 0x3f3f3f3f
const int N = 1e4 + 50;
const int M = 1e5 + 50;
int n, m, t, S, T;
int head[N * 3], nxt[M * 3], edge[M * 3], ver[M * 3], tot = 1;
int d[N * 3], dfn[N * 3], low[N * 3], num = 0, color[N * 3], cnt = 0, stack[N * 3], top = 0;
bool in_stack[N * 3];
struct edge
{
    int x, y, edge_id;
    bool invalid;
} p[M];
void add(int u, int v, int w)
{
    ver[++tot] = v, nxt[tot] = head[u], head[u] = tot, edge[tot] = w;
    ver[++tot] = u, nxt[tot] = head[v], head[v] = tot, edge[tot] = 0;
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
void Tarjan(int x)
{
    dfn[x] = low[x] = ++num;
    in_stack[x] = true, stack[++top] = x;
    for (int i = head[x]; i; i = nxt[i])
    {
        int y = ver[i];
        if (!edge[i])
            continue; //不连通
        if (!dfn[y])
        {
            Tarjan(y);
            low[x] = min(low[x], low[y]);
        }
        else if (in_stack[y])
            low[x] = min(low[x], dfn[y]);
    }
    if (dfn[x] == low[x])
    {
        int y;
        cnt++;
        do
        {
            y = stack[top--], color[y] = cnt, in_stack[y] = false;
        } while (y != x);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> p[i].x >> p[i].y;
        p[i].edge_id = tot + 1, p[i].invalid = false;
        add(p[i].x, n + p[i].y, 1);
    }
    S = 0, T = n + m + 1;
    for (int i = 1; i <= n; i++)
        add(S, i, 1);
    for (int i = n + 1; i <= n + m; i++)
        add(i, T, 1);
    while (BFS())
        while (Dinic(S, inf))
            ;
    for (int i = 0; i <= n + m + 1; i++)
        if (!dfn[i])
            Tarjan(i);
    int ans = 0;
    for (int i = 1; i <= t; i++)
    {
        if (!edge[p[i].edge_id] || color[p[i].x] == color[p[i].y + n])
            continue;
        else
            p[i].invalid = true, ans++;
    }
    cout << ans << endl;
    for (int i = 1; i <= t; i++)
    {
        if (p[i].invalid)
            cout << i << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}