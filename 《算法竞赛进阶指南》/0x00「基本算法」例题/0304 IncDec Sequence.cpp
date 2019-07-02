#include <iostream>
#include <math.h>
using namespace std;
const int N = 1e5 + 50;
#define ll long long
int n;
ll a[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input", "r", stdin);
    //freopen("output", "w", stdout);
    cin >> n;
    ll p = 0, q = 0;
    ll pre, cur;
    pre = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> cur;
        a[i] = cur - pre;
        pre = cur;
        if (i)
        {
            if (a[i] >= 0)
                p += a[i];
            else
                q += a[i];
        }
    }
    cout << max(p, -q) << endl
         << abs(p + q) + 1 << endl;
    //system("pause");
    return 0;
}