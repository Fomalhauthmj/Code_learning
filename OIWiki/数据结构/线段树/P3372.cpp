//https://www.luogu.org/problemnew/show/P3372
#include <iostream>
using namespace std;
#define ll long long
const int N = 1e5 + 50;
int n, m;
ll a[N];
#define ls(a) (a << 1)
#define rs(a) (a << 1 | 1)
struct node
{
    ll val;
    ll lazy;
    node()
    {
        val = 0;
        lazy = 0;
    }
};
node tree[N << 2];
void PushUp(ll rt)
{
    tree[rt].val = tree[ls(rt)].val + tree[rs(rt)].val;
}
void PushDown(ll ls, ll rs, ll rt)
{
    if (tree[rt].lazy)
    {
        tree[ls(rt)].val += ls * tree[rt].lazy;
        tree[rs(rt)].val += rs * tree[rt].lazy;
        tree[ls(rt)].lazy += tree[rt].lazy;
        tree[rs(rt)].lazy += tree[rt].lazy;
        tree[rt].lazy = 0;
    }
}
void Build(ll left, ll right, ll rt)
{
    if (left == right)
    {
        tree[rt].val = a[left];
        return;
    }
    ll mid = (left + right) >> 1;
    Build(left, mid, ls(rt));
    Build(mid + 1, right, rs(rt));
    PushUp(rt);
    //向上更新
}
void Update(ll left, ll right, ll rt, ll s, ll t, ll val)
{
    if (left >= s && right <= t)
    {
        tree[rt].val += (right - left + 1) * val;
        tree[rt].lazy += val;
        return;
    }
    ll mid = (left + right) >> 1;
    if (tree[rt].lazy)
    {
        PushDown(mid - left + 1, right - mid, rt);
    }
    if (mid < s)
        Update(mid + 1, right, rs(rt), s, t, val);
    else if (mid >= t)
        Update(left, mid, ls(rt), s, t, val);
    else
    {
        Update(left, mid, ls(rt), s, t, val);
        Update(mid + 1, right, rs(rt), s, t, val);
    }
    PushUp(rt);
}
ll Query(ll left, ll right, ll s, ll t, ll rt)
{
    if (left >= s && right <= t)
    {
        return tree[rt].val;
    }
    ll mid = (left + right) >> 1;
    if (tree[rt].lazy)
        PushDown(mid - left + 1, right - mid, rt);
    long long sum = 0;
    if (mid < s)
        sum += Query(mid + 1, right, s, t, rs(rt));
    else if (mid >= t)
        sum += Query(left, mid, s, t, ls(rt));
    else
    {
        sum += Query(left, mid, s, t, ls(rt));
        sum += Query(mid + 1, right, s, t, rs(rt));
    }
    return sum;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll kind, x, y, k;
    Build(1, n, 1);
    for (ll i = 0; i < m; i++)
    {
        cin >> kind;
        if (kind & 1)
        {
            cin >> x >> y >> k;
            Update(1, n, 1, x, y, k);
        }
        else
        {
            cin >> x >> y;
            cout << Query(1, n, x, y, 1) << endl;
        }
    }
    //system("pause");
    return 0;
}