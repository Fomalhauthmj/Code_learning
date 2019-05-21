#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;
const int N = 1e5 + 50;
#define ll long long
#define inf 0x3f3f3f3f
struct node
{
    ll h, l, r;
    node(ll height, ll left, ll right) : h(height), l(left), r(right)
    {
    }
    node()
    {
    }
    bool operator<(node n) const
    {
        return h < n.h;
    }
};
node ns[N];
ll n, max_h;
ll start_x, start_y;
ll dp[N][2];
int UP(int xpos, int pos, int height)
{
    if (pos == n + 1)
        return n + 1;
    for (int i = pos + 1; i <= n + 1; i++)
    {
        if (ns[i].h - height > max_h)
        {
            return -1;
        }
        if (ns[i].l <= xpos && xpos <= ns[i].r)
        {
            return i;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> max_h;
    cin >> start_x >> start_y;
    ll hi, li, ri;
    for (int i = 1; i <= n; i++)
    {
        cin >> hi >> li >> ri;
        ns[i] = node(hi, li, ri);
    }
    ns[0] = node(start_y, start_x, start_x);
    ns[n + 1] = node(0, 0, 0);
    sort(ns, ns + n + 2);
    //TODO
    int upl;
    int upr;
    dp[n + 1][0] = dp[n + 1][1] = 0;
    for (int i = n + 1; i >= 1; i--)
    {
        upl = UP(ns[i].l, i, ns[i].h);
        upr = UP(ns[i].r, i, ns[i].h);
        if (upl == n + 1)
        {
            dp[i][0] = 0;
        }
        else if (upl != -1 && upl != n + 1)
        {
            dp[i][0] = min(dp[upl][0] + ns[i].l - ns[upl].l, dp[upl][0] + ns[upl].r - ns[i].l);
        }
        else
            dp[i][0] = inf;
        if (upr == n + 1)
        {
            dp[i][1] = 0;
        }
        else if (upr != -1 && upr != n + 1)
        {
            dp[i][1] = min(dp[upr][1] + ns[upr].r - ns[i].r, dp[upr][1] + ns[i].r - ns[upr].l);
        }
        else
            dp[i][1] = inf;
        cout << i << " " << upl << " " << dp[i][0] << " " << upr << " " << dp[i][1] << endl;
    }
    cout << dp[0][0] + start_y << " " << dp[0][1] + start_y << endl;
    system("pause");
    return 0;
}
