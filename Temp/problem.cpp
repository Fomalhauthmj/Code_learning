#include <iostream>
#include <stdio.h>
using namespace std;
const int N = 3e5 + 50;
#define ll long long
#define inf 0x3f3f3f3f
ll a[N], b[N], dp[N][2];
int n;
int main()
{
    int Q;
    scanf("%d", &Q);
    while (Q--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%lld%lld", &a[i], &b[i]);
        dp[0] = 0, a[0] = 0, b[0] = inf;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == a[i - 1])
            {
                if (b[i] > b[i - 1])
                    dp[i] = dp[i - 1] + b[i - 1], a[i - 1]++;
                else
                    dp[i] = dp[i - 1] + b[i], a[i]++;
            }
            else
                dp[i] = dp[i - 1];
        }
        printf("%lld\n", dp[n]);
    }
    //system("pause");
    return 0;
}