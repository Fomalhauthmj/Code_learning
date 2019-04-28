#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;
#define N 100010
long long n, m, k;
int a[N];
long long sum[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n >> m >> k)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n); //由大到小排序
        sum[0] = a[0];
        for (int i = 1; i < n; i++) //前缀和
        {
            sum[i] = sum[i - 1] + a[i];
        }
        //贪心 取最大平均值 共k次操作 其中+1操作最多mi次 i为元素数 则删除操作为n-i次  n-i+mi<=k
        //枚举i
        //如果不删除
        long long temp_sum = sum[n - 1];
        if (m * n > k)
            temp_sum += k;
        else
            temp_sum += m * n;
        double ans = temp_sum * 1.0 / n;
        for (int i = 1; i <= n - 1; i++) //枚举删除元素数量
        {
            if (i > k)
                break;
            temp_sum = sum[n - 1] - sum[i - 1];
            if (k - i > m * (n - i))
                temp_sum += m * (n - i);
            else
                temp_sum += k - i;
            double temp = temp_sum * 1.0 / (n - i);
            ans = max(ans, temp);
        }
        cout << fixed << setprecision(7) << ans << endl;
    }
}