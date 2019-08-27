#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <stdio.h>
using namespace std;
#define ll long long
const int N = 2e5 + 50;
struct line
{
    int x, y1, y2;
    int tag;
    bool operator<(const line &l) const
    {
        return x < l.x;
    }
} lines[N];
ll raw[N];
map<int, int> val;
struct SegmentTree
{
    int l, r, cnt;
    ll len;
} tree[N << 2];
void Build(int p, int l, int r)
{
    tree[p].l = l, tree[p].r = r;
    if (l == r)
    {
        tree[p].cnt = 0, tree[p].len = 0;
        return;
    }
    int mid = (l + r) >> 1;
    Build(p << 1, l, mid), Build(p << 1 | 1, mid + 1, r);
    tree[p].len = tree[p].cnt > 0 ? raw[tree[p].r + 1] - raw[tree[p].l] : (tree[p << 1].len + tree[p << 1 | 1].len);
}
void Change(int p, int l, int r, int d)
{
    if (tree[p].l >= l && tree[p].r <= r)
    {
        tree[p].cnt += d;
        if (tree[p].cnt > 0)
            tree[p].len = raw[tree[p].r + 1] - raw[tree[p].l];
        else if (tree[p].l == tree[p].r)
            tree[p].len = 0;
        else
            tree[p].len = tree[p << 1].len + tree[p << 1 | 1].len;
        return;
    }
    int mid = (tree[p].l + tree[p].r) >> 1;
    if (l <= mid)
        Change(p << 1, l, r, d);
    if (r > mid)
        Change(p << 1 | 1, l, r, d);
    tree[p].len = tree[p].cnt > 0 ? raw[tree[p].r + 1] - raw[tree[p].l] : (tree[p << 1].len + tree[p << 1 | 1].len);
}
int main()
{
    int n;
    scanf("%d", &n);
    int x1, y1, x2, y2;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        lines[i] = {x1, y1, y2, 1}, lines[i + n] = {x2, y1, y2, -1};
        raw[i] = y1, raw[i + n] = y2;
    }
    sort(lines + 1, lines + 1 + 2 * n);
    sort(raw + 1, raw + 1 + 2 * n);
    int cnt = unique(raw + 1, raw + 1 + 2 * n) - (raw + 1);
    for (int i = 1; i <= cnt; i++)
        val[raw[i]] = i;
    memset(tree, 0, sizeof(tree));
    Build(1, 1, cnt - 1);
    ll ans = 0;
    for (int i = 1; i < 2 * n; i++)
    {
        int l = val[lines[i].y1], r = val[lines[i].y2];
        Change(1, l, r - 1, lines[i].tag);
        ans += tree[1].len * (lines[i + 1].x - lines[i].x);
    }
    cout << ans << endl;
    //system("pause");
    return 0;
}