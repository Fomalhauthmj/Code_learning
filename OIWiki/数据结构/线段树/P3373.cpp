#include <iostream>
using namespace std;
const int N = 1e5 + 50;
#define ll long long
long long n, m, p;
ll a[N];
#define ls(a) (a << 1)
#define rs(a) (a << 1 | 1)
struct node
{
    ll val;
    ll lazy_plus;
    ll lazy_mult;
    node()
    {
        val = 0;
        lazy_plus = 0;
        lazy_mult = 1;
    }
};
node tree[N << 2];
void PushUp(ll rt)
{
    tree[rt].val = (tree[ls(rt)].val + tree[rs(rt)].val) % p;
}
void PushDown(ll ls, ll rs, ll rt)
{
    //! 核心维护 先乘法 后加法 对于加法标记的维护要考虑其根的乘法标记

    tree[ls(rt)].val = tree[ls(rt)].val * tree[rt].lazy_mult % p;
    tree[rs(rt)].val = tree[rs(rt)].val * tree[rt].lazy_mult % p;
    tree[ls(rt)].lazy_mult = tree[ls(rt)].lazy_mult * tree[rt].lazy_mult % p;
    tree[rs(rt)].lazy_mult = tree[rs(rt)].lazy_mult * tree[rt].lazy_mult % p;

    tree[ls(rt)].val = (tree[ls(rt)].val + ls * tree[rt].lazy_plus % p) % p;
    tree[rs(rt)].val = (tree[rs(rt)].val + rs * tree[rt].lazy_plus % p) % p;
    tree[ls(rt)].lazy_plus = (tree[ls(rt)].lazy_plus * tree[rt].lazy_mult + tree[rt].lazy_plus) % p;
    tree[rs(rt)].lazy_plus = (tree[rs(rt)].lazy_plus * tree[rt].lazy_mult + tree[rt].lazy_plus) % p;

    tree[rt].lazy_plus = 0;
    tree[rt].lazy_mult = 1;
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
void Update_plus(ll left, ll right, ll rt, ll s, ll t, ll val)
{
    if (left >= s && right <= t)
    {
        //? 核心修改
        tree[rt].val = (tree[rt].val + (right - left + 1) * val % p) % p;
        tree[rt].lazy_plus = (tree[rt].lazy_plus + val) % p;
        return;
    }
    ll mid = (left + right) >> 1;
    if (tree[rt].lazy_plus || tree[rt].lazy_mult != 1)
    {
        PushDown(mid - left + 1, right - mid, rt);
    }
    if (mid < s)
        Update_plus(mid + 1, right, rs(rt), s, t, val);
    else if (mid >= t)
        Update_plus(left, mid, ls(rt), s, t, val);
    else
    {
        Update_plus(left, mid, ls(rt), s, t, val);
        Update_plus(mid + 1, right, rs(rt), s, t, val);
    }
    PushUp(rt);
}
void Update_mult(ll left, ll right, ll rt, ll s, ll t, ll val)
{
    if (left >= s && right <= t)
    {
        //? 核心修改
        tree[rt].val = (tree[rt].val * val) % p;
        tree[rt].lazy_mult = (tree[rt].lazy_mult * val) % p;
        tree[rt].lazy_plus = (tree[rt].lazy_plus * val) % p;
        return;
    }
    ll mid = (left + right) >> 1;
    if (tree[rt].lazy_plus || tree[rt].lazy_mult != 1)
    {
        PushDown(mid - left + 1, right - mid, rt);
    }
    if (mid < s)
        Update_mult(mid + 1, right, rs(rt), s, t, val);
    else if (mid >= t)
        Update_mult(left, mid, ls(rt), s, t, val);
    else
    {
        Update_mult(left, mid, ls(rt), s, t, val);
        Update_mult(mid + 1, right, rs(rt), s, t, val);
    }
    PushUp(rt);
}
ll Query(ll left, ll right, ll s, ll t, ll rt)
{
    if (left >= s && right <= t)
    {
        return tree[rt].val % p;
    }
    ll mid = (left + right) >> 1;
    if (tree[rt].lazy_plus || tree[rt].lazy_mult != 1)
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
    return sum % p;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll kind, x, y, k;
    Build(1, n, 1);
    for (int i = 0; i < m; i++)
    {
        cin >> kind;
        if (kind == 1)
        {
            cin >> x >> y >> k;
            Update_mult(1, n, 1, x, y, k);
        }
        else if (kind == 2)
        {
            cin >> x >> y >> k;
            Update_plus(1, n, 1, x, y, k);
        }
        else
        {
            cin >> x >> y;
            cout << Query(1, n, x, y, 1) << endl;
        }
        /*
        cout << "array:";
        for (int i = 1; i <= n; i++)
        {
            cout << Query(1, n, i, i, 1) << " ";
        }
        cout << endl;
        */
    }
    //system("pause");
    return 0;
}
/*
5 5 1111
1 5 4 2 3
2 1 4 1
1 2 4 2
1 1 5 3
2 3 3 5
1 1 1 7
*/