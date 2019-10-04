#include <cstring>
#include <iostream>
#include <stdio.h>
using namespace std;
const int N = 5e5 + 50;
const int M = 1e6 + 50;
#define ll long long
#define inf 0x3f3f3f3f
int head[N], ver[M], nxt[M], tot;
int fa[N], dep[N], sze[N], son[N], top[N], dfn[N], rnk[N], dfn_tot;
/*
    重链剖分
        fa[x] 表示节点x在树上的父亲
        dep[x]表示节点x在树上的深度
        sze[x]表示节点x的子树的节点个数
        son[x]表示节点x的重儿子
        top[x]表示节点x所在重链的顶部节点（深度最小）
        dfn[x]表示节点x的DFS序 ，也是其在线段树中的编号
        rnk[x]表示DFS序所对应的节点编号，有rnk[dfn[x]]=x
 */
void Add(int x, int y)
{
    ver[++tot] = y, nxt[tot] = head[x], head[x] = tot;
}
void Build(int x, int pre, int depth)
{
    son[x] = -1, sze[x] = 1, dep[x] = depth;
    for (int i = head[x]; i; i = nxt[i])
    {
        int y = ver[i];
        if (y == pre)
            continue;
        Build(y, x, depth + 1);
        sze[x] += sze[y], fa[y] = x;
        if (son[x] == -1 || sze[son[x]] < sze[y])
            son[x] = y;
    }
}
void Decomposition(int x, int t)
{
    top[x] = t, dfn[x] = ++dfn_tot, rnk[dfn_tot] = x;
    if (son[x] == -1)
        return;
    Decomposition(son[x], t);
    for (int i = head[x]; i; i = nxt[i])
    {
        int y = ver[i];
        if (y != son[x] && y != fa[x])
            Decomposition(y, y);
    }
}
int LCA(int x, int y)
{
    while (top[x] != top[y])
    {
        if (dep[top[x]] < dep[top[y]])
            y = fa[top[y]];
        else
            x = fa[top[x]];
    }
    if (dep[x] > dep[y])
        return y;
    return x;
}
int main()
{
    int n, m, rt;
    scanf("%d%d%d", &n, &m, &rt);
    int x, y;
    for (int i = 1; i <= n - 1; i++)
        scanf("%d%d", &x, &y), Add(x, y), Add(y, x);
    Build(rt, 0, 1);
    Decomposition(rt, rt);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &x, &y);
        printf("%d\n", LCA(x, y));
    }
    //system("pause");
    return 0;
}