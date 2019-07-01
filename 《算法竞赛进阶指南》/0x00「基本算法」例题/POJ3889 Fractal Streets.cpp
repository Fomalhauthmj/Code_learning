#include <iostream>
#include <math.h>
using namespace std;
#define ll long long
#define p pair<ll, ll>
ll t, n, s, d;
p calc(ll n, ll m)
{
    if (n == 0)
        return make_pair(0, 0);
    ll len = 1 << (n - 1);
    ll cnt = 1 << (2 * n - 2);
    p pos = calc(n - 1, m % cnt);
    ll x = pos.first;
    ll y = pos.second;
    ll z = m / cnt;
    if (z == 0)
        return make_pair(y, x);
    else if (z == 1)
        return make_pair(x, y + len);
    else if (z == 2)
        return make_pair(x + len, y + len);
    else
        return make_pair(2 * len - y - 1, len - x - 1);
}
ll dis(p p1, p p2)
{
    ll x = p1.first - p2.first;
    ll y = p1.second - p2.second;
    return round(sqrt(x * x + y * y) * 10);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n >> s >> d;
        cout << dis(calc(n, s - 1), calc(n, d - 1)) << endl;
    }
    //system("pause");
    return 0;
}