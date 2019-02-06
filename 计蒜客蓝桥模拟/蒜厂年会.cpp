#include <iostream>
#include <math.h>
using namespace std;
#define N 200020
int n;
long long a[N];
long long dp[N]; //环形最大连续子段和 dp[i] 表示以i结尾的最大子段和
int start[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            a[i + n] = a[i];
        }
        dp[0] = a[0];
        start[0] = 0;
        for (int i = 1; i < 2 * n; i++)
        {
            if (dp[i - 1] > 0)
            {
                dp[i] = dp[i - 1] + a[i];
                start[i] = start[i - 1];
            }
            else
            {
                dp[i] = a[i];
                start[i] = i;
            }
        }
        //TODO:80%
        long long ans = dp[0];
        for (int i = 0; i < 2 * n; i++)
        {
            if (abs(i - start[i]) < n)
                ans = max(ans, dp[i]);
        }
        cout << ans << endl;
    }
}
