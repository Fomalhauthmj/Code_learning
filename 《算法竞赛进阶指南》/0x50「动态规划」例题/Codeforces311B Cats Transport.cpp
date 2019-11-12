#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 50;
ll dp[105][N];
ll a[N], s[N], h[N], t[N], d[N], sumd[N];
int q[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, p;
    cin >> n >> m >> p;
    sumd[1] = 0;
    for (int i = 2; i <= n; i++)
        cin >> d[i], sumd[i] = sumd[i - 1] + d[i];
    for (int i = 1; i <= m; i++)
    {
        cin >> h[i] >> t[i];
        a[i] = t[i] - sumd[h[i]];
    }
    sort(a + 1, a + 1 + m);
    s[0] = 0;
    for (int i = 1; i <= m; i++)
        s[i] = s[i - 1] + a[i];
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 1; i <= p; i++)
    {
        int l = 1, r = 1;
        q[1] = 0, dp[i - 1][0] = 0;
        for (int j = 1; j <= m; j++)
        {
            while (l < r && (dp[i - 1][q[l + 1]] + s[q[l + 1]] - dp[i - 1][q[l]] - s[q[l]]) <= a[j] * (q[l + 1] - q[l]))
                l++;
            dp[i][j] = dp[i - 1][q[l]] + (j - q[l]) * a[j] - (s[j] - s[q[l]]);
            while (l < r && (dp[i - 1][j] + s[j] - dp[i - 1][q[r]] - s[q[r]]) * (q[r] - q[r - 1]) <= (dp[i - 1][q[r]] + s[q[r]] - dp[i - 1][q[r - 1]] - s[q[r - 1]]) * (j - q[r]))
                r--;
            q[++r] = j;
        }
    }
    cout << dp[p][m] << endl;
    //system("pause");
    return 0;
}