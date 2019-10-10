#include <cstring>
#include <iostream>
#include <stdio.h>
using namespace std;
const int N = 1e5 + 50;
const int M = 2e5 + 50;
#define ll long long
int temp[N], weight[N];
int head[N], ver[M], nxt[M], tot;
int fa[N], dep[N], sze[N], son[N], top[N], dfn[N], rnk[N], dfn_tot;
struct SegmentTree
{
    int l, r;
    int lc, rc, cnt;
    int edit;
#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)
#define l(x) tree[x].l
#define r(x) tree[x].r
#define cnt(x) tree[x].cnt
#define lc(x) tree[x].lc
#define rc(x) tree[x].rc
#define edit(x) tree[x].edit
} tree[N << 2];
//FIXME 
void PushUp(int rt)
{
    cnt(rt) = (rc(ls(rt)) == lc(rs(rt))) ? cnt(ls(rt)) + cnt(rs(rt)) - 1 : cnt(ls(rt)) + cnt(rs(rt));
    cout << tree[rt].l << ":" << tree[rt].r << " cnt ->" << cnt(rt) << endl;
    lc(rt) = lc(ls(rt)), rc(rt) = rc(rs(rt));
    cout << tree[rt].l << ":" << tree[rt].r << " ->" << lc(rt) << " " << rc(rt) << endl;
}
void SegmentTree_Build(int rt, int l, int r)
{
    l(rt) = l, r(rt) = r;
    if (l == r)
    {
        lc(rt) = rc(rt) = weight[l], cnt(rt) = 1;
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
        lc(rt) = rc(rt) = d, cnt(rt) = 1;
        return;
    }
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
        return cnt(rt);
    }
    ll ret = 0;
    int mid = (l(rt) + r(rt)) >> 1;
    if (l <= mid)
        ret += Query(ls(rt), l, r);
    if (r > mid)
        ret += Query(rs(rt), l, r);
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
        ret += Query(1, dfn[top[x]], dfn[x]);
        x = fa[top[x]];
    }
    if (dep[x] > dep[y])
        swap(x, y);
    ret += Query(1, dfn[x], dfn[y]);
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
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &temp[i]);
    int x, y;
    for (int i = 1; i <= n - 1; i++)
        scanf("%d%d", &x, &y), Add(x, y), Add(y, x);
    Build(1, 0, 1);
    Decomposition(1, 1);
    for (int i = 1; i <= n; i++)
        weight[i] = temp[rnk[i]], cout << "dfn " << i << "=" << rnk[i] << endl;
    SegmentTree_Build(1, 1, dfn_tot);
    for (int i = 1; i <= m; i++)
    {
        char op[2];
        scanf("%s", op);
        if (op[0] == 'C')
        {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            Update_Path(a, b, c);
        }
        else if (op[0] == 'Q')
        {
            int a, b;
            scanf("%d%d", &a, &b);
            printf("%lld\n", Query_Path(a, b));
        }
    }
    system("pause");
    return 0;
}