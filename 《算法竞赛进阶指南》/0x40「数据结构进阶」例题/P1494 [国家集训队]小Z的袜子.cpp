#include <algorithm>
#include <cstring>
#include <iostream>
#include <math.h>
using namespace std;
const int N = 5E4 + 50;
#define ll long long
#define pii pair<int, int>
int n, m, t;
int c[N], L[N], R[N], num[N];
struct node
{
    int l, r, id;
} p[N];
pii ret[N];
bool cmp_left(node &p1, node &p2)
{
    return p1.l < p2.l;
}
bool cmp_right(node &p1, node &p2)
{
    return p1.r < p2.r;
}
ll GCD(ll a, ll b)
{
    return b ? GCD(b, a % b) : a;
}
ll calc(ll l, ll r)
{
    return (r - l + 1) * (r - l) / 2;
}
pii answer(ll a, ll b)
{
    ll t = GCD(a, b);
    return make_pair(a / t, b / t);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 1; i <= m; i++)
        cin >> p[i].l >> p[i].r, p[i].id = i;
    sort(p + 1, p + 1 + m, cmp_left);
    t = sqrt(m);
    for (int i = 1; i <= t; i++)
        L[i] = (i - 1) * t + 1, R[i] = i * t;
    if (R[t] < m)
        t++, L[t] = R[t - 1] + 1, R[t] = m;
    for (int i = 1; i <= t; i++)
    {
        sort(p + L[i], p + R[i] + 1, cmp_right);
        memset(num, 0, sizeof(num));
        ll ans = 0;
        int fl = p[L[i]].l, fr = p[L[i]].r, fid = p[L[i]].id;
        for (int j = fl; j <= fr; j++)
            num[c[j]]++, ans += num[c[j]] - 1;
        if (fl != fr&&ans)
            ret[fid] = answer(ans, calc(fl, fr));
        else
            ret[fid] = make_pair(0, 1);
        for (int j = L[i] + 1; j <= R[i]; j++)
        {
            for (int k = p[j - 1].r + 1; k <= p[j].r; k++)
                num[c[k]]++, ans += num[c[k]] - 1;
            if (p[j - 1].l <= p[j].l)
                for (int k = p[j - 1].l; k < p[j].l; k++)
                    num[c[k]]--, ans -= num[c[k]];
            else
                for (int k = p[j].l; k < p[j - 1].l; k++)
                    num[c[k]]++, ans += num[c[k]] - 1;
            if (p[j].l != p[j].r&&ans)
                ret[p[j].id] = answer(ans, calc(p[j].l, p[j].r));
            else
                ret[p[j].id] = make_pair(0, 1);
        }
    }
    for (int i = 1; i <= m; i++)
        cout << ret[i].first << '/' << ret[i].second << endl;
    system("pause");
    return 0;
}