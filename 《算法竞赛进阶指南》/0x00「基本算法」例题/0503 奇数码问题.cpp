#include <iostream>
using namespace std;
#define ll long long
const ll N = 505;
ll n;
ll a[N * N], b[N * N], c[N * N];
ll cnta, cntb;
ll ans;
void merge(ll left, ll right, ll *a, ll *b)
{
    ll mid;
    if (left == right)
        return;
    else
    {
        mid = (left + right) >> 1;
        merge(left, mid, a, b);
        merge(mid + 1, right, a, b);
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
    //freopen("input", "r", stdin);
    //freopen("result", "w", stdout);
    ll num;
    while (cin >> n)
    {
        cnta = cntb = 0;
        for (ll i = 0; i < n * n; i++)
        {
            cin >> num;
            if (num)
                a[cnta++] = num;
        }
        for (ll i = 0; i < n * n; i++)
        {
            cin >> num;
            if (num)
                b[cntb++] = num;
        }
        ans = 0;
        if (cnta)
            merge(0, cnta - 1, a, c);
        //cout<<ans<<endl;
        ll ans1 = ans % 2;
        ans = 0;
        if (cntb)
            merge(0, cntb - 1, b, c);
        //cout<<ans<<endl;
        ll ans2 = ans % 2;
        if (ans1 == ans2)
            cout << "TAK" << endl;
        else
            cout << "NIE" << endl;
    }
    //system("pause");
    return 0;
}