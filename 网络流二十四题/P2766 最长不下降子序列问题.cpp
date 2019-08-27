#include <cstring>
#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;
const int N = 2e3 + 50;
const int M = 1e6 + 50;
#define inf 0x3f3f3f3f
int d[N], S, T;
int head[N], ver[M], nxt[M], edge[M], tot = 1;
int f[N], x[N], k;
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
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &x[i]), f[i] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
            if (x[i] >= x[j])
                f[i] = max(f[i], f[j] + 1);
    }
    k = 1;
    for (int i = 1; i <= n; i++)
        k = max(k, f[i]);
    printf("%d\n", k);
    S = 0, T = 2 * n + 1;
    for (int i = 1; i <= n; i++)
    {
        add(i, i + n, 1);
        if (f[i] == 1)
            add(S, i, 1);
        if (f[i] == k)
            add(i + n, T, 1);
        for (int j = 1; j < i; j++)
        {
            if (x[i] >= x[j] && f[i] == f[j] + 1)
                add(j + n, i, 1);
        }
    }
    int maxflow = 0, flow;
    while (BFS())
        while (flow = Dinic(S, inf))
            maxflow += flow;
    printf("%d\n", maxflow);
    add(1, 1 + n, inf), add(n, n + n, inf);
    add(S, 1, inf);
    if (f[n] == k)
        add(n + n, T, inf);
    while (BFS())
        while (flow = Dinic(S, inf))
            maxflow += flow;
    printf("%d\n", maxflow);
    //system("pause");
    return 0;
}