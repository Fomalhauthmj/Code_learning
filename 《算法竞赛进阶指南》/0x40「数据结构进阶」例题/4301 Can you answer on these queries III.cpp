#include <iostream>
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f3f3f3f3f
const int N = 5E5 + 50;
ll a[N];
struct SegmentTree
{
    ll l, r;
    ll sum, dat, lmax, rmax;
} t[N << 2];
void PushUp(int rt)
{
    //区间最大子段和
    t[rt].sum = t[rt << 1].sum + t[rt << 1 | 1].sum;
    t[rt].lmax = max(t[rt << 1].sum + t[rt << 1 | 1].lmax, t[rt << 1].lmax);
    t[rt].rmax = max(t[rt << 1 | 1].sum + t[rt << 1].rmax, t[rt << 1 | 1].rmax);
    t[rt].dat = max(t[rt << 1].rmax + t[rt << 1 | 1].lmax, max(t[rt << 1].dat, t[rt << 1 | 1].dat));
}
void Build(int rt, int l, int r)
{
    t[rt].l = l;
    t[rt].r = r;
    if (l == r)
    {
        t[rt].dat = t[rt].sum = t[rt].lmax = t[rt].rmax = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    Build(rt << 1, l, mid);
    Build(rt << 1 | 1, mid + 1, r);
    PushUp(rt);
}
void Change(int rt, int pos, int val)
{
    if (t[rt].l == t[rt].r)
    {
        t[rt].dat = t[rt].lmax = t[rt].rmax = t[rt].sum = val;
        return;
    }
    int mid = (t[rt].l + t[rt].r) >> 1;
    if (pos <= mid)
        Change(rt << 1, pos, val);
    else
        Change(rt << 1 | 1, pos, val);
    PushUp(rt);
}
SegmentTree Query(int rt, int l, int r)
{
    if (l <= t[rt].l && t[rt].r <= r)
    {
        return t[rt];
    }
    int mid = (t[rt].l + t[rt].r) >> 1;
    SegmentTree a,b,ans;
    a.dat=a.lmax=a.rmax=a.sum=b.dat=b.lmax=b.rmax=b.sum=-inf;
    ans.sum=0;
    if (l <= mid)
    {
        a = Query(rt << 1, l, r);
        ans.sum+=a.sum;
    }
    if (r > mid)
    {
        b= Query(rt << 1 | 1, l, r);
        ans.sum+=b.sum;
    }
    ans.dat=max(max(a.dat,b.dat),a.rmax+b.lmax);
    ans.lmax=max(a.sum+b.lmax,a.lmax);
    ans.rmax=max(b.sum+a.rmax,b.rmax);
    if(l>mid) ans.lmax=max(ans.lmax,b.lmax);
    //为了处理单侧查询导致的错误结果 完全保持正确性
    if(r<=mid) ans.rmax=max(ans.rmax,a.rmax);
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    Build(1,1,n);
    int k, x, y;
    for (int i = 1; i <= m; i++)
    {
        cin >> k >> x >> y;
        if(k==1)
        {
            if(x>y) swap(x,y);
            cout<<Query(1,x,y).dat<<endl;
        }
        else
        {
            Change(1,x,y);
        }
    }
    system("pause");
    return 0;
}