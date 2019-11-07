/* 
 * Author: Hemengjie
 * Time: 2019-11-07 11:10:41
**/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f
const int N = 1e5 + 50;
struct SegmentTree
{
    int l, r;
    int lazy, min_val;
#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)
#define l(x) tree[x].l
#define r(x) tree[x].r
#define lazy(x) tree[x].lazy
#define min_val(x) tree[x].min_val
} tree[N << 2];
int n;
int a[N];
int R[N];
int GTK[N];
vector<int> V[N];
void PushUp(int rt)
{
    min_val(rt) = min(min_val(ls(rt)), min_val(rs(rt)));
}
void PushDown(int rt)
{
    if (lazy(rt))
    {
        min_val(ls(rt)) += lazy(rt), min_val(rs(rt)) += lazy(rt);
        lazy(ls(rt)) += lazy(rt), lazy(rs(rt)) += lazy(rt);
        lazy(rt) = 0;
    }
}
void SegmentTree_Build(int rt, int l, int r)
{
    l(rt) = l, r(rt) = r;
    if (l == r)
    {
        min_val(rt) = n - R[l] - GTK[l - 1] - 1;
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
        min_val(rt) += d;
        lazy(rt) += d;
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
int Query(int rt, int l, int r)
{
    if (l(rt) >= l && r(rt) <= r)
    {
        return min_val(rt);
    }
    PushDown(rt);
    int ret = inf;
    int mid = (l(rt) + r(rt)) >> 1;
    if (l <= mid)
        ret = min(ret, Query(ls(rt), l, r));
    if (r > mid)
        ret = min(ret, Query(rs(rt), l, r));
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m, Q;
    scanf("%d%d%d", &n, &m, &Q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        if (i > 1 && a[i] > a[1])
            GTK[0]++;
    }
    int key = a[1];
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &R[i]);
        GTK[i] = GTK[i - 1];
        for (int j = 1, bi; j <= R[i]; j++)
        {
            scanf("%d", &bi);
            V[i].push_back(bi);
            if (bi > key)
                GTK[i]++;
        }
    }
    SegmentTree_Build(1, 1, m);
    while (Q--)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        if (x < m)
        {
            if (V[x][y - 1] < key && z > key)
                Update(1, x + 1, m, -1);
            else if (V[x][y - 1] > key && z < key)
                Update(1, x + 1, m, 1);
            V[x][y - 1] = z;
        }
        int ans = Query(1, 1, m);
        if (ans < 0)
            printf("0\n");
        else
            printf("1\n");
    }
    //system("pause");
    return 0;
}