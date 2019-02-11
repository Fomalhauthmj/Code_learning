#include <iostream>
using namespace std;
long long n, b;
//计算b进制下的n!的末尾连续0数量
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n >> b)
    {
        long long ans = 1e18;
        for (long long i = 2;i <= b; i++) //对b质因子分解
        {
            if(1ll*i*i>b)
                i = b;
            long long cnt = 0; //记录指数
            while (b % i == 0)
            {
                b /= i;
                cnt++;
            }
            if (cnt == 0)
                continue; //无此质因子
            long long temp = n;
            long long k = 0; //记录指数
            while (temp)     //对n!分解 找出其含有i的指数
            {
                k += temp / i;
                temp = temp / i;
            }
            ans = min(ans, k / cnt);
        }
        cout << ans << endl;
    }
}