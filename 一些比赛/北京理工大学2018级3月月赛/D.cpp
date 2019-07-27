#include <cstring>
#include <iostream>
using namespace std;
#define ll long long
const ll mod = 1e9;
const int N = 2E4 + 5;
ll dp[11][N], sum[11][N];
// dp[i][j] 以长度i为末尾为j的递减序列  TLE
int a[N];
int n, k;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
        dp[i][1] = 1;
    
    for (int i = 2; i <= k; i++) // 长度
    {
        for (j = 1; j <= n; )
            for (int j = i; j <= n; j++) // 末尾
            {
                    for (int k = 1; k < j; k++)
                    {
                        if (a[k] > a[j])
                            dp[j][i] = (dp[j][i] + dp[k][i - 1]) % mod;
                    }
            }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
        ans = (ans + dp[i][k]) % mod;
    cout << ans << endl;
    //system("pause");
    return 0;
}