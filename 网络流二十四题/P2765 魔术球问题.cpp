#include <cstring>
#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;
const int N = 1e4 + 50;
const int M = 1e6 + 50;
#define inf 0x3f3f3f3f
int head[N], nxt[M], ver[M], edge[M], ori[M], tot = 1;
int n, m, S, T, d[N], num;
bool valid[N];
void add(int x, int y, int z)
{
    ver[++tot] = y, nxt[tot] = head[x], head[x] = tot, edge[tot] = z, ori[tot] = z;
    ver[++tot] = x, nxt[tot] = head[y], head[y] = tot, edge[tot] = 0, ori[tot] = 0;
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
            if ((y > n * n && y > n * n + num) || (y < n * n && y > num))
                continue;
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
        if ((y > n * n && y > n * n + num) || (y < n * n && y > num))
            continue;
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
    if (x <= 0 || x > num)
        return;
    cout << x << " ";
    vis[x] = true;
    for (int i = head[x]; i; i = nxt[i])
    {
        int y = ver[i];
        if (!edge[i])
            DFS(y - n * n);
    }
}
int main()
{
    scanf("%d", &n);
    num = 1;
    for (int i = 1; i <= n; i++)
        valid[i * i] = true;
    S = 0, T = n * n;
    while (1)
    {
        add(S, num, 1), add(num + n * n, T, 1);
        for (int i = 1; i < num; i++)
            if (valid[i + num])
                add(i, num + n * n, 1);
        int maxflow = 0, flow;
        while (BFS())
            while (flow = Dinic(S, inf))
                maxflow += flow;
        if (num - maxflow <= n)
            num++, memcpy(edge, ori, sizeof(edge));
        else
            break;
    }
    num--;
    memcpy(edge, ori, sizeof(edge));
    while (BFS())
        while (int flow = Dinic(S, inf))
            ;
    cout << num << endl;
    for (int i = 1; i <= num; i++)
        if (!vis[i])
            DFS(i), cout << endl;
    system("pause");
    return 0;
}