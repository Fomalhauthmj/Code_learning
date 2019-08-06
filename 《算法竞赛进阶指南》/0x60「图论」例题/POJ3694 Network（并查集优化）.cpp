#include <cstring>
#include <iostream>
#include <math.h>
#include <queue>
#include <stdio.h>
using namespace std;
const int N = 1e5 + 50;
const int M = 2E5 + 50;
int n, m;
int head[N], nxt[M << 1], ver[M << 1], tot;
//e-DCC 缩点
int dfn[N], low[N], num;
bool bridge[M << 1];
void add(int u, int v)
{
    ver[++tot] = v;
    nxt[tot] = head[u];
    head[u] = tot;
}
void Tarjan(int x, int in_edge)
{
    dfn[x] = low[x] = ++num;
    for (int i = head[x]; i; i = nxt[i])
    {
        int y = ver[i];
        if (!dfn[y])
        {
            Tarjan(y, i);
            low[x] = min(low[x], low[y]);
            if (low[y] > dfn[x])
            {
                bridge[i] = bridge[i ^ 1] = true;
            }
        }
        else if (i != (in_edge ^ 1))
        {
            low[x] = min(low[x], dfn[y]);
        }
    }
}
int color[N], dcc;
int headc[N], verc[M << 1], nxtc[M << 1], totc;
int origin_bridges;
void DFS(int x)
{
    color[x] = dcc;
    for (int i = head[x]; i; i = nxt[i])
    {
        int y = ver[i];
        if (!color[y] && !bridge[i])
            DFS(y);
    }
}
void add_c(int u, int v)
{
    verc[++totc] = v;
    nxtc[totc] = headc[u];
    headc[u] = totc;
}
int d[N], k, fa[N][20];
void e_DCC()
{
    dcc = 0;
    for (int i = 1; i <= n; i++)
        if (!color[i])
            ++dcc, DFS(i);
    totc = 1;
    for (int i = 2; i <= tot; i++)
    {
        int u = ver[i ^ 1], v = ver[i];
        if (color[u] != color[v])
            add_c(color[u], color[v]);
    }
    origin_bridges = (totc - 1) / 2;
    k = log2(dcc) + 1;
}
void BFS()
{
    queue<int> q;
    q.push(1);
    d[1] = 1;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = headc[x]; i; i = nxtc[i])
        {
            int y = verc[i];
            if (!d[y])
            {
                fa[y][0] = x;
                d[y] = d[x] + 1;
                for (int j = 1; j <= k; j++)
                    fa[y][j] = fa[fa[y][j - 1]][j - 1];
                q.push(y);
            }
        }
    }
}
int LCA(int x, int y)
{
    if (d[x] < d[y])
        swap(x, y);
    for (int i = k; i >= 0; i--)
        if (d[fa[x][i]] >= d[y])
            x = fa[x][i];
    if (x == y)
        return y;
    for (int i = k; i >= 0; i--)
        if (fa[x][i] != fa[y][i])
            x = fa[x][i], y = fa[y][i];
    return fa[x][0];
}
int father[N]; //并查集优化
void Init()
{
    num = 0;
    tot = 1;
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(head, 0, sizeof(head));
    memset(bridge, 0, sizeof(bridge));
    memset(color, 0, sizeof(color));
    memset(headc, 0, sizeof(headc));
    memset(d, 0, sizeof(d));
    for (int i = 1; i < N; i++)
        father[i] = i;
}
int Find(int x)
{
    if (x == father[x])
        return x;
    return father[x] = Find(father[x]);
}
int main()
{
    int casenum = 0;
    while (scanf("%d%d", &n, &m) && n + m)
    {
        Init();
        int u, v, q;
        for (int i = 0; i < m; i++)
            scanf("%d%d", &u, &v), add(u, v), add(v, u);
        //无向连通图
        Tarjan(1, 0);
        e_DCC();
        BFS();
        scanf("%d", &q);
        printf("Case %d:\n", ++casenum);
        for (int i = 0; i < q; i++)
        {
            scanf("%d%d", &u, &v);
            if (color[u] != color[v])
            {
                int p = LCA(color[u], color[v]);
                int temp = Find(color[u]);
                while (d[temp] > d[p])//注意这里的终止条件
                {
                    origin_bridges--;
                    father[temp] = fa[temp][0];
                    temp = Find(temp);
                }
                temp = Find(color[v]);
                while (d[temp] > d[p])
                {
                    origin_bridges--;
                    father[temp] = fa[temp][0];
                    temp = Find(temp);
                }
            }
            printf("%d\n", origin_bridges);
        }
        printf("\n");
    }
    //system("pause");
    return 0;
}