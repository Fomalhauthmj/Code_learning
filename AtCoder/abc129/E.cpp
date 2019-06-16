#include <iostream>
#include <string>
using namespace std;
#define ll long long
const ll mod = 1e9 + 7;
string l;
long long quick_pow(long long a, long long b)
{
    if (b == 0)
        return 1;
    long long temp = quick_pow(a, b >> 1);
    if (b & 1)
        return a % mod * temp % mod * temp % mod;
    else
        return temp % mod * temp % mod; //快速幂
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> l;
    int len = l.length();
    ll ans = 0;
    int num = 0;
    for (int i = 0; i < len; i++)
    {
        if (l[i] == '1')
        {
            ans = (ans + quick_pow(2, num++) * quick_pow(3, len - 1 - i)) % mod;
        }
    }
    ans = (ans + quick_pow(2, num)) % mod;
    cout << ans % mod << endl;
    //system("pause");
    return 0;
}