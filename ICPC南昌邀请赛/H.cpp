#include <algorithm>
#include <iostream>
using namespace std;
#define mod 1000000007
long long n;
int num = 0;
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
    cin >> n;
    long long ans;
    if (n == 1)
    {
        ans = 1;
    }
    else
    {
        ans = (4 * quick_pow(3, n - 2)) % mod;
    }
    cout << ans << endl;
    //system("pause");
    return 0;
}