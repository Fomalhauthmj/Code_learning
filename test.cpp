#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
const int N = 1e6 + 50;
const int M = 1e6 + 50;
#define ll long long
int head[N], nxt[M], ver[M], tot = 1;
int head_c[N], nxt_c[M], ver_c[M], tot_c;
int n, m, w[N], W[N];
void add(int x, int y)
{
    ver[++tot] = y, nxt[tot] = head[x], head[x] = tot;
}
void add_c(int x, int y)
{
    ver_c[++tot_c] = y, nxt_c[tot_c] = head_c[x], head_c[x] = tot_c;
}
int dfn[N], low[N], num, bridge[M], color[N], dcc;
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
            low[x] = min(low[x], dfn[y]);
    }
}
void DFS(int x)
{
    color[x] = dcc;
    W[dcc] += w[x];
    for (int i = head[x]; i; i = nxt[i])
    {
        int y = ver[i];
        if (!color[y] && !bridge[i])
            DFS(y);
    }
}
void e_DCC()
{
    dcc = 0;
    for (int i = 1; i <= n; i++)
        if (!color[i])
            ++dcc, DFS(i);
    tot_c = 1;
    for (int i = 2; i <= tot; i++)
    {
        int u = ver[i ^ 1], v = ver[i];
        if (color[u] != color[v])
            add_c(color[u], color[v]);
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    int u, v;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &u, &v);
        add(u, v), add(v, u);
    }
    int rt;
    scanf("%d", &rt);
    Tarjan(1, 0);
    e_DCC();
    //system("pause");
    return 0;
}