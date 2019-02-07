#include <iostream>
#include <math.h>
using namespace std;
#define N 100020
int n;
long long a[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n)
    {
        long long sum_max, temp_max;
        long long sum_min, temp_min;
        long long sum = 0;
        temp_max = temp_min = 0;
        sum_max = -0x3f3f3f3f;
        sum_min = 0x3f3f3f3f;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
            temp_max += a[i];
            temp_min += a[i];
            if (temp_max < 0)
                temp_max = 0;
            if (temp_min > 0)
                temp_min = 0;
            sum_max = max(temp_max, sum_max);
            sum_min = min(temp_min, sum_min);
        }
        //cout << "min:" << sum_min << endl;
        //cout << "max:" << sum_max << endl;
        cout << max(sum - sum_min, sum_max) << endl;
    }
}
/*
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
//100 50 -1 1 100 50 -1 1
*/