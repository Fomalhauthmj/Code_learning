#include <cstring>
#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;
const int N = 1e3 + 50;
const int M = 1e6 + 50;
#define inf 0x3f3f3f3f
int head[N], ver[M], nxt[M], edge[M], tot = 1;
int d[N], S, T;
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
    int m, n;
    scanf("%d%d", &m, &n);
    S = 0, T = m + n + 1;
    int sum = 0;
    for (int i = 1, p; i <= m; i++)
        scanf("%d", &p), add(S, i, p), sum += p;
    for (int i = 1, c; i <= n; i++)
        scanf("%d", &c), add(m + i, T, c);
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            add(i, m + j, 1);
    int maxflow = 0, flow;
    while (BFS())
        while (flow = Dinic(S, inf))
            maxflow += flow;
    if (maxflow != sum)
        printf("0\n");
    else
    {
        printf("1\n");
        for (int i = 1; i <= m; i++)
        {
            for (int j = head[i]; j; j = nxt[j])
            {
                if (!edge[j])
                    printf("%d ", ver[j]-m);
            }
            printf("\n");
        }
    }
    //system("pause");
    return 0;
}