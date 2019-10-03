#include <cstring>
#include <iostream>
#include<stdio.h>
using namespace std;
const int N = 1e5 + 50;
const int M = 2e5 + 50;
#define ll long long
int mod;
int temp[N], weight[N];
int head[N], ver[M], nxt[M], tot;
int fa[N], dep[N], sze[N], son[N], top[N], dfn[N], rnk[N], dfn_tot;
struct SegmentTree
{
    int l, r;
    ll sum, add;
    #define ls(x) (x << 1)
    #define rs(x) (x << 1 | 1)
    #define l(x) tree[x].l
    #define r(x) tree[x].r
    #define sum(x) tree[x].sum
    #define add(x) tree[x].add
} tree[N << 2];
void PushUp(int rt)
{
    sum(rt) = (sum(ls(rt)) + sum(rs(rt))) % mod;
}
void PushDown(int rt)
{
    if (add(rt))
    {
        sum(ls(rt)) = (sum(ls(rt)) + add(rt) * (r(ls(rt)) - l(ls(rt)) + 1)) % mod;
        sum(rs(rt)) = (sum(rs(rt)) + add(rt) * (r(rs(rt)) - l(rs(rt)) + 1)) % mod;
        add(ls(rt)) = (add(ls(rt)) + add(rt)) % mod;
        add(rs(rt)) = (add(rs(rt)) + add(rt)) % mod;
        add(rt) = 0;
    }
}
void SegmentTree_Build(int rt, int l, int r)
{
    l(rt) = l, r(rt) = r;
    if (l == r)
    {
        sum(rt) = weight[l];
        return;
    }
    int mid = (l + r) >> 1;
    SegmentTree_Build(ls(rt), l, mid);
    SegmentTree_Build(rs(rt), mid + 1, r);
    PushUp(rt);
    //向上更新
}
void Update(int rt, int l, int r, int d)
{
    if (l <= l(rt) && r(rt) <= r)
    {
        sum(rt) = (sum(rt) + (r(rt) - l(rt) + 1) * d) % mod;
        add(rt) = (add(rt) + d) % mod;
        return;
    }
    PushDown(rt);
    int mid = (l(rt) + r(rt)) >> 1;
    if (l <= mid)
        Update(ls(rt), l, r, d);
    if (r > mid)
        Update(rs(rt), l, r, d);
    PushUp(rt);
}
ll Query(int rt, int l, int r)
{
    if (l(rt) >= l && r(rt) <= r)
    {
        return sum(rt) % mod;
    }
    PushDown(rt);
    ll ret = 0;
    int mid = (l(rt) + r(rt)) >> 1;
    if (l <= mid)
        ret = (ret + Query(ls(rt), l, r)) % mod;
    if (r > mid)
        ret = (ret + Query(rs(rt), l, r)) % mod;
    return ret;
}
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
ll Query_Path(int x, int y)
{
    ll ret = 0;
    while (top[x] != top[y])
    {
        if (dep[top[x]] < dep[top[y]])
            swap(x, y);
        ret = (ret + Query(1, dfn[top[x]], dfn[x])) % mod;
        x = fa[top[x]];
    }
    if (dep[x] > dep[y])
        swap(x, y);
    ret = (ret + Query(1, dfn[x], dfn[y])) % mod;
    return ret;
}
void Update_Path(int x, int y, int d)
{
    while (top[x] != top[y])
    {
        if (dep[top[x]] < dep[top[y]])
            swap(x, y);
        Update(1, dfn[top[x]], dfn[x], d);
        x = fa[top[x]];
    }
    if (dep[x] > dep[y])
        swap(x, y);
    Update(1, dfn[x], dfn[y], d);
}
int main()
{
    int n, m, r;
    scanf("%d%d%d%d", &n, &m, &r, &mod);
    for (int i = 1; i <= n; i++)
        scanf("%d", &temp[i]);
    int x, y;
    for (int i = 1; i <= n - 1; i++)
        scanf("%d%d", &x, &y), Add(x, y), Add(y, x);
    Build(r, 0, 1);
    Decomposition(r, r);
    for (int i = 1; i <= n; i++)
        weight[i] = temp[rnk[i]] % mod;
    SegmentTree_Build(1, 1, dfn_tot);
    for (int i = 1; i <= m; i++)
    {
        int op;
        scanf("%d", &op);
        int x, y, z;
        if (op == 1)
        {
            //路径修改
            scanf("%d%d%d", &x, &y, &z);
            Update_Path(x, y, z);
        }
        else if (op == 2)
        {
            //路径和
            scanf("%d%d", &x, &y);
            printf("%lld\n", Query_Path(x, y));
        }
        else if (op == 3)
        {
            //子树修改
            scanf("%d%d", &x, &z);
            Update(1,dfn[x],dfn[x]+sze[x]-1,z);
        }
        else
        {
            //子树和
            scanf("%d", &x);
            printf("%lld\n", Query(1,dfn[x],dfn[x]+sze[x]-1));
        }
    }
    //system("pause");
    return 0;
}