#include <algorithm>
#include <iostream>
using namespace std;
const int N = 2E5 + 20;
#define ll long long
ll a[N];
ll b[N], c[N];
ll n, m;
ll all[3 * N];
int cnt = 0;
ll know[3 * N];
int Find(ll x)
{
    return lower_bound(all, all + cnt, x) - all;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        all[cnt++] = a[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
        all[cnt++] = b[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> c[i];
        all[cnt++] = c[i];
    }
    sort(all, all + cnt);
    cnt = unique(all, all + cnt) - all;
    for (int i = 0; i < n; i++)
    {
        know[Find(a[i])]++;
    }
    int temp_b, temp_c;
    int max_b = 0, max_c = 0;
    int ans=1;
    for (int i = 0; i < m; i++)
    {
        temp_b = know[Find(b[i])];
        temp_c = know[Find(c[i])];
        if (temp_b > max_b)
        {
            max_b = temp_b;
            max_c = temp_c;
            ans = i + 1;
        }
        else if (temp_b == max_b && temp_c > max_c)
        {
            max_c = temp_c;
            ans = i + 1;
        }
    }
    cout << ans << endl;
    //system("pause");
    return 0;
}