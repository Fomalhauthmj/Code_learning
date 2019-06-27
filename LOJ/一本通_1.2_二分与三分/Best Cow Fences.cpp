#include <algorithm>
#include <iostream>
using namespace std;
const int N = 1E5 + 10;
#define ll long long
ll a[N];
ll n, l;
ll diff[N];
ll sum_diff[N];
bool judge(int mid)
{
    for (int i = 1; i <= n; i++)
        diff[i] = a[i - 1] - mid;
    sum_diff[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        sum_diff[i] = sum_diff[i - 1] + diff[i];
    }
    ll min_val = 1 << 30;
    ll ans = -(1 << 30);
    for (int i = l; i <= n; i++)
    {
        min_val = min(min_val, sum_diff[i - l]);
        ans = max(ans, sum_diff[i] - min_val);
    }
    if (ans >= 0)
        return true;
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("cowfnc.14.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    cin >> n >> l;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i] *= 1000;
    }
    ll left, mid, right;
    ll ans;
    left = 0;
    right = 2000 * 1000;
    while (left <= right)
    {
        mid = (left + right) >> 1;
        if (judge(mid))
        {
            ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    cout << ans << endl;
    //system("pause");
    return 0;
}