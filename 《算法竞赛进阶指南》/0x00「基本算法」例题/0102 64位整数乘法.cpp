#include <iostream>
using namespace std;
#define ll long long
ll a, b, p;
ll mul(ll a, ll b, ll p)
{
    ll ans = 0;
    for (; b; b >>= 1)
    {
        if (b & 1)
            ans = (ans + a) % p;
        a = a * 2 % p;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> a >> b >> p;
    cout << mul(a, b, p) << endl;
    //system("pause");
    return 0;
}