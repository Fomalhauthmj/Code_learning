#include <cstring>
#include <iostream>
#include <queue>
#include <stdio.h>
#include <vector>
using namespace std;
const int N = 1e6 + 50;
const int M = 1e6 + 50;
#define inf 0x3f3f3f3f
int head[N], ver[M], nxt[M], edge[M], tot = 1;
int S, T, n, m, k,d[N];
vector<int> v[25];
int p[25], fa[25];
int Find(int x)
{
    if (x == fa[x])
        return x;
    return fa[x] = Find(fa[x]);
}
int H(int ver, int hour)
{
    return ver + hour * (n + 2);
}
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
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i <= n + 1; i++)
        fa[i] = i;
    for (int i = 1, cnt; i <= m; i++)
    {
        scanf("%d%d", &p[i], &cnt);
        for (int j = 0, pre; j < cnt; j++)
        {
            int t;
            scanf("%d", &t);
            if (t == -1)
                t = n + 1;
            if (j)
                fa[Find(pre)] = Find(t);
            v[i].push_back(t), pre = t;
        }
    }
    if (Find(0) != Find(n + 1))
    {
        printf("0\n");
        return 0;
    }
    int hour = 0;
    S = 1e5, T = 1e5 + 1;
    int maxflow = 0, flow;
    while (1)
    {
        add(S, H(0, hour), inf);
        add(H(n + 1, hour), T, inf);
        if (hour)
        {
            for(int i=1;i<=n;i++)
                add(H(i,hour-1),H(i,hour),inf);
            for (int i = 1; i <= m; i++)
            {
                int pre=(hour-1)%v[i].size();
                int now=hour%v[i].size();
                add(H(v[i][pre], hour - 1), H(v[i][now], hour), p[i]);
            }
        }
        while (BFS())
            while (flow = Dinic(S, inf))
                maxflow += flow;
        if (maxflow >= k)
            break;
        else
            hour++;
    }
    printf("%d\n", hour);
    //system("pause");
    return 0;
}