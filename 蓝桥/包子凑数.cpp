#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
#define N 105
int a[N];
int n;
int GCD(int a, int b)
{
    if (b == 0)
        return a;
    else
        return GCD(b, a % b);
}
int dp[N * N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;

    //根据a[i]的最大公因数是否为1 不为1 INF
    int gcd;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i == 0)
            gcd = a[i];
        else
            gcd = GCD(gcd, a[i]);
    }
    if (gcd != 1)
    {
        cout << "INF" << endl;
        return 0;
    }
    //小于最小的ai 全部无法凑出
    //试探 整数分拆
    //母函数 75%
    sort(a, a + n);
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j + a[i] < N * N; j++)
        {
            if (dp[j])
                dp[j + a[i]]++;
        }
    }
    int ans = 0;
    for (int i = 1; i < N * N; i++)
    {
        if (!dp[i])
            ans++;
    }
    cout << ans << endl;
}