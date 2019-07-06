#include <algorithm>
#include <cstring>
#include <iostream>
#include <math.h>
using namespace std;
#define ll long long
const ll N = 5e5 + 50;
ll n, m, k, has_sort;
ll a[N], b[N], c[N];
//快速排序复杂度高 最后样例超时 采用归并排序
/*
    a 初始数组
    b 归并数组
    c 结果数组
 */
void merge(ll left, ll mid, ll right)
{
    ll i = left, j = mid + 1;
    for (ll k = left; k <= right; k++)
    {
        if (j > right || (i <= mid && b[i] <= b[j]))
            c[k] = b[i++];
        else
            c[k] = b[j++];
    }
}
ll GetValue(ll left, ll right)
{
    if (right >= n)
        right = n - 1;
    for (ll i = has_sort + 1; i <= right; i++)
        b[i] = a[i];
    sort(b + has_sort + 1, b + right + 1);
    merge(left, has_sort, right);
    //对新增部分b排序后 归并入结果数组c
    ll ans = 0;
    ll pos1 = left, pos2 = right;
    ll cnt = 0;
    while (pos1 < pos2 && cnt < m)
    {
        ans += pow(c[pos2] - c[pos1], 2);
        pos1++;
        pos2--;
        cnt++;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> k;
        for (ll i = 0; i < n; i++)
            cin >> a[i];
        ll ans = 0;
        ll cur_left = 0;
        ll cur_right = 0;
        has_sort = 0;
        b[0] = a[0];
        //why need this statement? because need correct merge start
        while (cur_left < n)
        {
            ll p = 1;
            while (p)
            {
                ll temp = GetValue(cur_left, cur_right + p);
                if (temp <= k)
                {
                    has_sort = cur_right = min(cur_right + p, n - 1);
                    for (int i = cur_left; i <= cur_right; i++)
                        b[i] = c[i];
                    if (cur_right == n - 1)
                        break;
                    p *= 2;
                }
                else
                    p /= 2;
            }
            //cout << cur_left << " ->" << cur_right << endl;
            ans++;
            cur_left = cur_right + 1;
        }
        cout << ans << endl;
    }
    //system("pause");
    return 0;
}