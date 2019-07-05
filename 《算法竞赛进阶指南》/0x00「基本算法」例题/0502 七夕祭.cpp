#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
#define ll long long
const ll N = 1E5 + 50;
ll n, m, t;
ll row[N], col[N];
ll a[N], s[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input", "r", stdin);
    //freopen("output", "w", stdout);
    cin >> n >> m >> t;
    ll x, y;
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    for (ll i = 0; i < t; i++)
    {
        cin >> x >> y;
        row[x-1]++;
        col[y-1]++;
    }
    bool flag_r = false, flag_c = false;
    ll ans_r = 0, ans_c = 0;
    if (t % n == 0)
    {
        flag_r = true;
        ll temp = t / n;
        for (ll i = 0; i < n; i++)
            a[i] = row[i] - temp;
        for (ll i = 0; i < n; i++)
        {
            if (i == 0)
                s[i] = a[i];
            else
                s[i] = s[i - 1] + a[i];
        }
        sort(s, s + n);
        //if (n & 1)
            temp = s[n / 2];
        //else
            //temp = (s[n / 2] + s[n / 2 + 1]) / 2;
        for (ll i = 0; i < n; i++)
            ans_r += abs(s[i] - temp);
    }
    if (t % m == 0)
    {
        flag_c = true;
        ll temp = t / m;
        for (ll i = 0; i < m; i++)
            a[i] = col[i] - temp;
        for (ll i = 0; i < m; i++)
        {
            if (i == 0)
                s[i] = a[i];
            else
                s[i] = s[i - 1] + a[i];
        }
        sort(s, s + m);
        //if (m & 1)
            temp = s[m / 2];
        //else
            //temp = (s[m / 2] + s[m / 2 + 1]) / 2;
        for (ll i = 0; i < m; i++)
            ans_c += abs(s[i] - temp);
    }
    if (flag_r && flag_c)
    {
        cout << "both " << ans_c + ans_r << endl;
    }
    else if (flag_r && !flag_c)
    {
        cout << "row " << ans_r << endl;
    }
    else if (!flag_r && flag_c)
    {
        cout << "column " << ans_c << endl;
    }
    else
        cout << "impossible" << endl;
    //system("pause");
    return 0;
}