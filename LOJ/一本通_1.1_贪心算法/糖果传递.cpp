#include <algorithm>
#include <iostream>
#include <math.h>
using namespace std;
#define ll long long
const ll N = 1E6 + 50;
ll n;
ll a[N];
ll c[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    ll avg = sum / n;
    for (int i = 0; i < n - 1; i++)
    {
        if (i != 0)
            c[i] = c[i - 1] - avg + a[i];
        else
            c[i] = a[0] - avg;
    }
    c[n - 1] = 0;
    //sort(c, c + n);
    ll x0;
    /*
    if (n & 1)
    {
        x0 = c[n / 2];
    }
    else
    {
        x0 = (c[n / 2 - 1] + c[n / 2]) / 2;
    }
    */
    int pos = (n + 1) / 2;
    nth_element(c, c + pos, c + n);
    x0 = c[pos];
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += abs(x0 - c[i]);
    }
    cout << ans << endl;
    //system("pause");
    return 0;
}