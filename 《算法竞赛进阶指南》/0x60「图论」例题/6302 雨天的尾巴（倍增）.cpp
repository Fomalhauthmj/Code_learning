#include <algorithm>
#include <cstring>
#include <iostream>
#include <math.h>
#include <queue>
#include <stdio.h>
using namespace std;
const int N = 1E5 + 20;
int n, m, k, val[N], cnt;
int head[N], nxt[2*N], ver[2*N], tot = 0;
int fa[N][20], vis[N], d[N];
int X[N], Y[N], Z[N];
void add(int u, int v)
{
    ver[++tot] = v;
    nxt[tot] = head[u];
    head[u] = tot;
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
        for (int i = head[x]; i; i = nxt[i])
        {
            int y = ver[i];
            if (!d[y])
            {
                d[y] = d[x] + 1;
                fa[y][0] = x;
                for (int i = 1; i <= k; i++)
                {
                    fa[y][i] = fa[fa[y][i - 1]][i - 1];
                }
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
struct SegmentTree
{
    int left, right, dat, pos;
    //区间最大值及最大值位置
} tree[N * 20 * 4];
int tree_num, root[N], ans[N];
void PushUp(int rt)
{
    int l = tree[rt].left, r = tree[rt].right;
    tree[rt].dat = max(tree[l].dat, tree[r].dat);
    tree[rt].pos = tree[l].dat >= tree[r].dat ? tree[l].pos : tree[r].pos;
}
void Insert(int rt, int l, int r, int val, int delta)
{
    if (l == r)
    {
        tree[rt].dat += delta;
        tree[rt].pos = tree[rt].dat ? l : 0;
        return;
    }
    int mid = (l + r) >> 1;
    if (val <= mid)
    {
        if (!tree[rt].left)
            tree[rt].left = ++tree_num;
        Insert(tree[rt].left, l, mid, val, delta);
    }
    else
    {
        if (!tree[rt].right)
            tree[rt].right = ++tree_num;
        Insert(tree[rt].right, mid + 1, r, val, delta);
    }
    PushUp(rt);
}
int Merge(int p, int q, int l, int r)
{
    if (!p)
        return q;
    if (!q)
        return p;
    if (l == r)
    {
        tree[p].dat += tree[q].dat;
        tree[p].pos = tree[p].dat ? l : 0;
        return p;
    }
    int mid = (l + r) >> 1;
    tree[p].left = Merge(tree[p].left, tree[q].left, l, mid);
    tree[p].right = Merge(tree[p].right, tree[q].right, mid + 1, r);
    PushUp(p);
    return p;
}
void DFS_calc(int x)
{
    vis[x] = 1;
    for (int i = head[x]; i; i = nxt[i])
    {
        int y = ver[i];
        if (!vis[y])
        {
            DFS_calc(y);
            root[x] = Merge(root[x], root[y], 1, cnt);
        }
    }
    ans[x] = tree[root[x]].pos;
}
int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //cin >> n >> m;
    scanf("%d%d", &n, &m);
    k = log2(n) + 1;
    int a, b;
    for (int i = 0; i < n - 1; i++)
    {
        //cin >> a >> b;
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }
    BFS();
    for (int i = 1; i <= m; i++)
    {
        //cin >> X[i] >> Y[i] >> Z[i];
        scanf("%d%d%d", &X[i], &Y[i], &Z[i]);
        val[i] = Z[i];
    }
    sort(val + 1, val + 1 + m);
    cnt = unique(val + 1, val + 1 + m) - (val + 1);
    tree_num = 0;
    for (int i = 1; i <= n; i++)
        root[i] = ++tree_num;
    for (int i = 1; i <= m; i++)
    {
        int x = X[i], y = Y[i];
        int z = lower_bound(val + 1, val + 1 + cnt, Z[i]) - val;
        int p = LCA(x, y);
        Insert(root[x], 1, cnt, z, 1);
        Insert(root[y], 1, cnt, z, 1);
        Insert(root[p], 1, cnt, z, -1);
        if (fa[p][0])
            Insert(root[fa[p][0]], 1, cnt, z, -1);
    }
    memset(vis, 0, sizeof(vis));
    DFS_calc(1);
    for (int i = 1; i <= n; i++)
        cout << val[ans[i]] << endl;
    system("pause");
    return 0;
}