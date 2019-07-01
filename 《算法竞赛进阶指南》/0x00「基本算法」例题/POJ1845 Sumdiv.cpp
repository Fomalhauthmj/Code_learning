#include <iostream>
#include <vector>
using namespace std;
#define ll long long
#define mod 9901
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
ll a, b;
struct node
{
    ll p;
    ll c;
    node(ll pp, ll cc) : p(pp), c(cc) {}
};
vector<node> v;
ll Sum(ll p, ll c)
{
    if (!c)
        return 1;
    if (c & 1)
    {
        return (1 + quick_pow(p, (c + 1) / 2)) * Sum(p, (c - 1) / 2) % mod;
    }
    else
        return ((1 + quick_pow(p, c / 2)) * Sum(p, c / 2 - 1) % mod + quick_pow(p, c)) % mod;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> a >> b;
    ll temp_c;
    for (int i = 2; i <= a; i++)
    {
        if (a % i == 0)
        {
            temp_c = 0;
            while (a % i == 0)
            {
                temp_c++;
                a /= i;
            }
            v.push_back(node(i, temp_c * b));
        }
    }
    if (a > 1)
        v.push_back(node(a, 1 * b));
    ll ans = 1;
    for (auto it : v)
    {
        //cout << it.p << " " << it.c << endl;
        ans = ans * Sum(it.p, it.c) % mod;
    }
    cout << ans << endl;
    //system("pause");
    return 0;
}