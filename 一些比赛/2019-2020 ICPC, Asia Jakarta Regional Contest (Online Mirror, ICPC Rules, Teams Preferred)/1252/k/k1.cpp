/* 
 * Author: Hemengjie
 * Time: 2019-11-07 11:28:48
**/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
const int N = 1e5 + 50;
int ori[N];
struct matrix
{
    ll mat[2][2];
};
matrix mata, matb, matstd;
matrix mul(matrix m1, matrix m2)
{
    matrix ans;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            ans.mat[i][j] = 0;
            for (int k = 0; k < 2; k++)
                ans.mat[i][j] = (ans.mat[i][j] + m1.mat[i][k] * m2.mat[k][j]) % MOD;
        }
    }
    return ans;
}
void change(matrix &m)
{
    matrix temp = m;
    m.mat[0][0] = temp.mat[1][1], m.mat[0][1] = temp.mat[1][0], m.mat[1][0] = temp.mat[0][1], m.mat[1][1] = temp.mat[0][0];
}
struct SegmentTree
{
    int l, r;
    matrix node;
    int lazy;
#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)
#define l(x) tree[x].l
#define r(x) tree[x].r
#define node(x) tree[x].node
#define lazy(x) tree[x].lazy
} tree[N << 2];
void PushUp(int rt)
{
    node(rt) = mul(node(ls(rt)), node(rs(rt)));
}
void PushDown(int rt)
{
    if (lazy(rt))
    {
        change(node(ls(rt))), change(node(rs(rt)));
        lazy(ls(rt)) ^= 1, lazy(rs(rt)) ^= 1;
        lazy(rt) ^= 1;
    }
}
void SegmentTree_Build(int rt, int l, int r)
{
    l(rt) = l, r(rt) = r;
    if (l == r)
    {
        if (ori[l])
            node(rt) = mata;
        else
            node(rt) = matb;
        return;
    }
    int mid = (l + r) >> 1;
    SegmentTree_Build(ls(rt), l, mid);
    SegmentTree_Build(rs(rt), mid + 1, r);
    PushUp(rt);
    //向上更新
}
void Update(int rt, int l, int r)
{
    if (l <= l(rt) && r(rt) <= r)
    {
        change(node(rt));
        lazy(rt) ^= 1;
        return;
    }
    PushDown(rt);
    int mid = (l(rt) + r(rt)) >> 1;
    if (l <= mid)
        Update(ls(rt), l, r);
    if (r > mid)
        Update(rs(rt), l, r);
    PushUp(rt);
}
matrix Query(int rt, int l, int r)
{
    if (l(rt) >= l && r(rt) <= r)
    {
        return node(rt);
    }
    PushDown(rt);
    matrix ret = matstd;
    int mid = (l(rt) + r(rt)) >> 1;
    if (l <= mid)
        ret = mul(Query(ls(rt), l, r), ret);
    if (r > mid)
        ret = mul(ret, Query(rs(rt), l, r));
    return ret;
}
char str[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);
    mata.mat[0][0] = 1, mata.mat[0][1] = 0, mata.mat[1][0] = 1, mata.mat[1][1] = 1;
    matb.mat[0][0] = 1, matb.mat[0][1] = 1, matb.mat[1][0] = 0, matb.mat[1][1] = 1;
    matstd.mat[0][0] = 1, matstd.mat[0][1] = 0, matstd.mat[1][0] = 0, matstd.mat[1][1] = 1;
    /*
    1 0
    1 1

    1 1
    0 1
    */
    int n, Q;
    scanf("%d%d", &n, &Q);
    scanf("%s", str + 1);
    for (int i = 1; i <= n; i++)
        if (str[i] == 'A')
            ori[i] = 1;
    SegmentTree_Build(1, 1, n);
    while (Q--)
    {
        int casenum, l, r;
        scanf("%d%d%d", &casenum, &l, &r);
        if (casenum == 1)
            Update(1, l, r);
        else
        {
            ll A, B;
            scanf("%lld%lld", &A, &B);
            matrix ans = Query(1, l, r);
            ll ansa, ansb;
            ansa = (ans.mat[0][0] * A + ans.mat[1][0] * B) % MOD;
            ansb = (ans.mat[0][1] * A + ans.mat[1][1] * B) % MOD;
            printf("%lld %lld\n", ansa, ansb);
        }
    }
    //system("pause");
    return 0;
}