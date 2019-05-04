#include <cstring>
#include <iostream>
using namespace std;
#define N 1010
long long n, C;
long long a[N], b[N], c[N];
long long dp[N][N];
//如何降低回溯复杂度
//http://acm.hdu.edu.cn/showproblem.php?pid=6495
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> C;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i] >> b[i] >> c[i];
        }
        //读入数据
        //DP
        memset(dp, 0, sizeof(dp));
        dp[0][0] = C; //初始化
        //dp[i][j]表示前i个中完成j个的最大体力
        /*
        受第 i 个挑战会让你丧失 ai点体力，在挑战它之前你的体力 x 会变成 min(x,bi)，
        当你完成这个挑战的时候，你的体力会变成 x−ai，体力任何时候不允许小于等于 0，
        无论你是否接受第 i 个挑战，在这个挑战结束以后你的体力都会增加 ci。
        */
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (dp[i][j] > 0)
                {
                    //接受第i+1个
                    if (min(dp[i][j], b[i + 1]) > a[i + 1])
                    {
                        dp[i + 1][j + 1] = max(dp[i + 1][j + 1], min(dp[i][j], b[i + 1]) - a[i + 1] + c[i + 1]);
                    }
                    //不接受
                    dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + c[i + 1]);
                }
            }
        }
        int ans=0;
        for (int j = n; j >= 0; j--)
        {
            if (dp[n][j] > 0)
            {
                ans = j;
                break;
            }
        }
        cout << ans << endl;
    }
    //system("pause");
    return 0;
}