#include <cstring>
#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;
const int N = 5e4 + 50;
const int M = 1e6 + 50;
#define inf 0x3f3f3f3f
int head[N], ver[M], nxt[M], edge[M], tot = 1, d[N];
int dir[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
int S, T, m, n;
void add(int x, int y, int z)
{
    ver[++tot] = y, nxt[tot] = head[x], head[x] = tot, edge[tot] = z;
    ver[++tot] = x, nxt[tot] = head[y], head[y] = tot, edge[tot] = 0;
}
bool Judge(int r, int c)
{
    if (r < 1 || r > m || c < 1 || c > n)
        return false;
    return true;
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
int Pos(int r, int c)
{
    return (r - 1) * n + c;
}
int main()
{
    scanf("%d%d", &m, &n);
    int val;
    S = 0, T = m * n + 1;
    int sum = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &val), sum += val;
            if ((i + j) & 1)
            {
                add(S, Pos(i, j), val);
                for (int k = 0; k < 4; k++)
                {
                    int nr = i + dir[k][0];
                    int nc = j + dir[k][1];
                    if (Judge(nr, nc))
                    {
                        add(Pos(i, j), Pos(nr, nc), inf);
                    }
                }
            }
            else
                add(Pos(i, j), T, val);
        }
    }
    int maxflow = 0, flow;
    while (BFS())
        while (flow = Dinic(S, inf))
            maxflow += flow;
    cout << sum - maxflow << endl;
    //system("pause");
    return 0;
}