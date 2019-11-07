/* 
 * Author: Hemengjie
 * Time: 2019-11-06 15:23:30
**/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>
const int MOD = 1e9 + 7;
const int N = 1e5 + 50;
char str[N];
int a[N];
pii outa[N], outb[N];
int seg[N], L[N], R[N];
void change(int segnum)
{
    outa[segnum] = {1, 0}, outb[segnum] = {0, 1};
    for (int i = L[segnum]; i <= R[segnum]; i++)
    {
        if (a[i])
        {
            outa[segnum].first = (outa[segnum].first + outb[segnum].first) % MOD;
            outa[segnum].second = (outa[segnum].second + outb[segnum].second) % MOD;
        }
        else
        {
            outb[segnum].first = (outb[segnum].first + outa[segnum].first) % MOD;
            outb[segnum].second = (outb[segnum].second + outa[segnum].second) % MOD;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);
    int n, Q;
    scanf("%d%d", &n, &Q);
    scanf("%s", str + 1);
    for (int i = 1; i <= n; i++)
        if (str[i] == 'A')
            a[i] = 1;
    int seg_cnt = sqrt(n);
    int len = n / seg_cnt;
    for (int i = 1; i <= seg_cnt; i++)
    {
        outa[i] = {1, 0}, outb[i] = {0, 1};
        L[i] = (i - 1) * len + 1, R[i] = i * len;
        for (int j = L[i]; j <= R[i]; j++)
        {
            seg[j] = i;
            if (a[j])
            {
                outa[i].first = (outa[i].first + outb[i].first) % MOD;
                outa[i].second = (outa[i].second + outb[i].second) % MOD;
            }
            else
            {
                outb[i].first = (outb[i].first + outa[i].first) % MOD;
                outb[i].second = (outb[i].second + outa[i].second) % MOD;
            }
        }
    }
    if (R[seg_cnt] < n)
    {
        seg_cnt++;
        outa[seg_cnt] = {1, 0}, outb[seg_cnt] = {0, 1};
        L[seg_cnt] = R[seg_cnt - 1] + 1, R[seg_cnt] = n;
        for (int i = L[seg_cnt]; i <= R[seg_cnt]; i++)
        {
            seg[i] = seg_cnt;
            if (a[i])
            {
                outa[seg_cnt].first = (outa[seg_cnt].first + outb[seg_cnt].first) % MOD;
                outa[seg_cnt].second = (outa[seg_cnt].second + outb[seg_cnt].second) % MOD;
            }
            else
            {
                outb[seg_cnt].first = (outb[seg_cnt].first + outa[seg_cnt].first) % MOD;
                outb[seg_cnt].second = (outb[seg_cnt].second + outa[seg_cnt].second) % MOD;
            }
        }
    }
    while (Q--)
    {
        int casenum, l, r;
        scanf("%d%d%d", &casenum, &l, &r);
        if (casenum == 1)
        {
            if (seg[l] != seg[r])
            {
                for (int i = l; i <= R[seg[l]]; i++)
                    a[i] = a[i] ^ 1;
                change(seg[l]);
                for (int i = seg[l] + 1; i <= seg[r] - 1; i++)
                {
                    pii temp = outa[i];
                    outa[i].first = outb[i].second, outa[i].second = outb[i].first;
                    outb[i].first = temp.second, outb[i].second = temp.first;
                    for (int j = L[i]; j <= R[i]; j++)
                        a[j] = a[j] ^ 1;
                }
                for (int i = L[seg[r]]; i <= r; i++)
                    a[i] = a[i] ^ 1;
                change(seg[r]);
            }
            else
            {
                for (int i = l; i <= r; i++)
                {
                    a[i] ^= 1;
                }
                change(seg[l]);
            }
        }
        else
        {
            ll A, B;
            scanf("%lld%lld", &A, &B);
            if (seg[l] == seg[r])
            {
                for (int i = l; i <= r; i++)
                {
                    if (a[i])
                        A = (A + B) % MOD;
                    else
                        B = (B + A) % MOD;
                }
            }
            else
            {
                for (int i = l; i <= R[seg[l]]; i++)
                {
                    if (a[i])
                        A = (A + B) % MOD;
                    else
                        B = (B + A) % MOD;
                }
                //cout << l << " " << R[seg[l]] << " " << A << " " << B << endl;
                for (int i = seg[l] + 1; i <= seg[r] - 1; i++)
                {
                    ll t1, t2;
                    t1 = (outa[i].first * A + outa[i].second * B) % MOD;
                    t2 = (outb[i].first * A + outb[i].second * B) % MOD;
                    A = t1, B = t2;
                }
                for (int i = L[seg[r]]; i <= r; i++)
                {
                    if (a[i])
                        A = (A + B) % MOD;
                    else
                        B = (B + A) % MOD;
                }
                //cout << L[seg[r]] << " " << r << " " << A << " " << B << endl;
                //cout << A << " " << B << endl;
            }
            printf("%lld %lld\n", A, B);
        }
    }
    //system("pause");
    return 0;
}