#include <iostream>
using namespace std;
#define ll long long
ll a, b, p;
ll power(ll a, ll b, ll p)
{
    ll ans = 1 % p;
    for (; b; b >>= 1)
    {
        if (b & 1)
            ans = ans * a % p;
        a = a * a % p;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    int n;
    cin >> t;
    while (t--)
    {
        cin >> p >> n;
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a >> b;
            ans += power(a, b, p);
        }
        cout << ans % p << endl;
    }
    //system("pause");
    return 0;
}