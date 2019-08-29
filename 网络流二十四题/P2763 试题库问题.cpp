#include <cstring>
#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;
const int N = 2e3 + 50;
const int M = 1e6 + 50;
#define inf 0x3f3f3f3f
int k, n, m, S, T, d[N], x[N];
int head[N], ver[M], nxt[M], edge[M], tot = 1;
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
    scanf("%d%d", &k, &n);
    S = 0, T = n + k + 1, m = 0;
    for (int i = 1; i <= k; i++)
        scanf("%d", &x[i]), add(S, i, x[i]), m += x[i];
    for (int i = 1; i <= n; i++)
        add(i + k, T, 1);
    for (int i = 1; i <= n; i++)
    {
        int j, belong;
        scanf("%d", &j);
        while (j--)
            scanf("%d", &belong), add(belong, i + k, 1);
    }
    int maxflow = 0, flow;
    while (BFS())
        while (flow = Dinic(S, inf))
            maxflow += flow;
    if (maxflow != m)
        printf("No Solution!\n");
    else
    {
        for (int i = 1; i <= k; i++)
        {
            printf("%d:", i);
            if (x[i])
            {
                for (int j = head[i]; j; j = nxt[j])
                {
                    if (!edge[j])
                        printf(" %d", ver[j] - k);
                }
            }
            printf("\n");
        }
    }
    //system("pause");
    return 0;
}