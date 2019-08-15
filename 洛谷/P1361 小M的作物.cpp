#include <cstring>
#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f
const int N = 3e3 + 500;
const int M = 2e6 + 50;
int head[N], ver[M], nxt[M], tot = 1, d[N];
ll edge[M];
int n, m, S, T;
void add(int x, int y, ll z)
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
ll Dinic(int x, ll flow)
{
    if (x == T)
        return flow;
    ll rest = flow, k;
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
    scanf("%d", &n);
    ll ai, bi, sum = 0;
    S = 0, T = n + 1;
    for (int i = 1; i <= n; i++)
        scanf("%lld", &ai), add(S, i, ai), sum += ai;
    for (int i = 1; i <= n; i++)
        scanf("%lld", &bi), add(i, T, bi), sum += bi;
    scanf("%d", &m);
    int k, p;
    ll c1, c2;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%lld%lld", &k, &c1, &c2);
        sum += c1 + c2;
        add(S, n + 1 + i, c1), add(n + 1 + i + m, T, c2);
        for (int j = 1; j <= k; j++)
            scanf("%d", &p), add(n + 1 + i, p, inf), add(p, n + 1 + i + m, inf);
    }
    ll maxflow = 0, flow;
    while (BFS())
        while (flow = Dinic(S, inf))
            maxflow += flow;
    cout << sum - maxflow << endl;
    //system("pause");
    return 0;
}