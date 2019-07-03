#include <algorithm>
#include <iostream>
using namespace std;
#define ll long long
const int N = 1E5 + 10;
ll n, a[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    ll mid;
    if (n & 1)
        mid = a[n / 2];
    else
        mid = (a[n / 2 - 1] + a[n / 2]) >> 1;
    ll ans = 0;
    for (size_t i = 0; i < n; i++)
    {
        ans += abs(a[i] - mid);
    }
    cout << ans << endl;
    //system("pause");
    return 0;
}