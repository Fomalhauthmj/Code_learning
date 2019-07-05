#include <iostream>
#include<stdio.h>
using namespace std;
#define ll long long
const ll N = 1010;
ll m, n;
ll a[N * N], b[N * N];
ll ans;
void merge(ll left, ll right)
{
    ll mid;
    if (left == right)
        return;
    else
    {
        mid = (left + right) >> 1;
        merge(left, mid);
        merge(mid + 1, right);
    }
    ll i = left, j = mid + 1;
    for (ll k = left; k <= right; k++)
    {
        if (j > right || (i <= mid && a[i] <= a[j]))
            b[k] = a[i++];
        else
        {
            b[k] = a[j++];
            ans += mid - i + 1;
        }
    }
    for (ll k = left; k <= right; k++)
        a[k] = b[k];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll num, cnt, space_row;
    while (scanf("%lld%lld",&m,&n))
    {
        if (m + n == 0)
            break;
        cnt = 0;
        for (ll i = 0; i < m; i++)
        {
            for (ll j = 0; j < n; j++)
            {
                scanf("%lld",&num);
                if (num)
                    a[cnt++] = num;
                else
                    space_row = i + 1;
            }
        }
        ans = 0;
        merge(0, cnt - 1);
        if (n & 1)
        {
            //奇数码情况
            if (ans % 2 == 0)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else
        {
            ll temp1 = ans%2;
            ll temp2 = (m - space_row) % 2;
            //偶数码情况
            if (temp1 == temp2)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    //system("pause");
    return 0;
}