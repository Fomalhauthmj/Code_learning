#include <iostream>
using namespace std;
#define ll long long
ll a, b, p;
ll powmod(ll a, ll b)
{
    if (!b)
        return 1;
    ll temp = powmod(a, b >> 1);
    if (b & 1)
        return temp * temp % p * a % p;
    return temp * temp % p;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> a >> b >> p;
    cout << powmod(a, b) % p << endl;
    //system("pause");
    return 0;
}