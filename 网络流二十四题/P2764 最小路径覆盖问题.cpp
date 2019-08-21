#include <cstring>
#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;
const int N = 505;
const int M = 2E4 + 50;
#define inf 0x3f3f3f3f
int head[N], nxt[M], ver[M], edge[M], tot = 1;
int n, m, S, T, d[N];
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
bool vis[N];
void DFS(int x)
{
    if(x<=0) return;
    cout<<x<<" ";
    vis[x]=true;
    for (int i = head[x]; i; i = nxt[i])
    {
        int y=ver[i];
        if(!edge[i])
            DFS(y-n);
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    S = 0, T = 2 * n + 1;
    for (int i = 1; i <= n; i++)
        add(S, i, 1), add(n + i, T, 1);
    for (int i = 1, x, y; i <= m; i++)
        scanf("%d%d", &x, &y), add(x, y + n, 1);
    int maxflow = 0, flow;
    while (BFS())
        while (flow = Dinic(S, inf))
            maxflow += flow;
    for(int i=1;i<=n;i++)
        if(!vis[i]) DFS(i),cout<<endl;
    cout << n - maxflow << endl;
    //system("pause");
    return 0;
}