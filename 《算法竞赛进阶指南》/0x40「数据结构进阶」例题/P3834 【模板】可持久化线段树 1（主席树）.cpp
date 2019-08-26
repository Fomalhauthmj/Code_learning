#include <algorithm>
#include <iostream>
#include <stdio.h>
using namespace std;
const int MAX_N = 2e5 + 50;
const int MAX_M = 2e5 + 50;
struct SegmentTree
{
    int lc, rc, cnt;
} tree[MAX_M * 20];
int tot, root[MAX_M];
int n, m, a[MAX_N], b[MAX_N];
int Build(int l, int r)
{
    int p = ++tot;
    if (l == r)
    {
        tree[p].cnt = 0;
        return p;
    }
    int mid = (l + r) >> 1;
    tree[p].lc = Build(l, mid);
    tree[p].rc = Build(mid + 1, r);
    tree[p].cnt = tree[tree[p].lc].cnt + tree[tree[p].rc].cnt;
    return p;
}
int Insert(int now, int l, int r, int x, int val)
{
    int p = ++tot;
    tree[p] = tree[now];
    if (l == r)
    {
        tree[p].cnt += val;
        return p;
    }
    int mid = (l + r) >> 1;
    if (x <= mid)
        tree[p].lc = Insert(tree[now].lc, l, mid, x, val);
    else
        tree[p].rc = Insert(tree[now].rc, mid + 1, r, x, val);
    tree[p].cnt = tree[tree[p].lc].cnt + tree[tree[p].rc].cnt;
    return p;
}
//在p，q两个节点上，值域为 [l,r]，求第k小数
int Ask(int p, int q, int l, int r, int k)
{
    if (l == r)
        return l;
    int mid = (l + r) >> 1;
    int lcnt = tree[tree[p].lc].cnt - tree[tree[q].lc].cnt;
    if (k <= lcnt)
        return Ask(tree[p].lc, tree[q].lc, l, mid, k);
    else
        return Ask(tree[p].rc, tree[q].rc, mid + 1, r, k - lcnt);
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]), b[i] = a[i];
    sort(b + 1, b + 1 + n);
    int cnt = unique(b + 1, b + 1 + n) - (b + 1);
    root[0] = Build(1, cnt);
    for (int i = 1; i <= n; i++)
    {
        int x = lower_bound(b + 1, b + 1 + cnt, a[i]) - b;
        root[i] = Insert(root[i - 1], 1, cnt, x, 1);
    }
    int l, r, k;
    for (int i = 1; i <= m; i++)
        scanf("%d%d%d", &l, &r, &k), printf("%d\n", b[Ask(root[r], root[l - 1], 1, cnt, k)]);
    //system("pause");
    return 0;
}