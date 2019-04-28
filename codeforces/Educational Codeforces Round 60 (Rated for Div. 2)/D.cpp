#include <cstring>
#include <iostream>
using namespace std;
#define N 105
#define mod 1000000007
//组合数考虑 显然复杂度过于庞大 ans=ΣC[分割数量][N-分割数量*(M-1)]
//dp  显然dp[n]=dp[n-1]+dp[n-m]
//意味着空间为n的状态=n-1的状态加一个不分割 + n-m的状态加一个分割
//但是由于N<10^18 直接转移不可行 需要矩阵加速
//构造加速矩阵
long long n, m;
struct matrix
{
    long long a[N][N];
    matrix()
    {
        memset(a, 0, sizeof(a));
    }
};
matrix matrix_mul(matrix m1, matrix m2)
{
    matrix ans;
    for (int k = 0; k < m; k++)
    {
        for (int i = 0; i < m; i++)
        {
            if (m1.a[i][k]) //剪枝
            {
                for (int j = 0; j < m; j++)
                {
                    if (m2.a[k][j]) //剪枝
                    {
                        ans.a[i][j] = (ans.a[i][j] + (m1.a[i][k] * m2.a[k][j]) % mod) % mod;
                    }
                }
            }
        }
    }
    return ans;
}
matrix quick_pow_matrix(matrix m1, long long k)
{
    matrix ans;//递归写法 堆栈溢出
    for (int i = 0; i < m; i++)
        ans.a[i][i] = 1;
    while (k)
    {
        if (k & 1)
            ans = matrix_mul(ans, m1);
        m1 = matrix_mul(m1, m1);
        k >>= 1;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n >> m)
    {
        if (m > n)
        {
            cout << 1 << endl;
            continue;
        }
        else if (m == n)
        {
            cout << 2 << endl;
            continue;
        }
        matrix init;
        for (int i = 0; i < m; i++)
        {
            init.a[i][0] = 1;
        }         //初始化 对于小于分割数m的方案显然只有一种：不分割
        matrix A; //构造矩阵
        A.a[0][0] = A.a[0][m - 1] = 1;
        for (int i = 1; i < m; i++)
            A.a[i][i - 1] = 1;
        init = matrix_mul(quick_pow_matrix(A, n - m + 1), init);
        cout << init.a[0][0] << endl;
    }
}