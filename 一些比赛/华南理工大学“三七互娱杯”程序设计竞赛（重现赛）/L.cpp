#include <cstring>
#include <iostream>
using namespace std;
long long n, k;
int m[1010];
int prime_factor(long long num)
{
    //不同的质因子数
    int temp = 0;
    long long i;
    bool square = false;
    int cnt;
    for (i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            temp++;
            if (!square)
            {
                cnt = 0;
            }
            while (num % i == 0)
            {
                num /= i;
                cnt++;
            }
            if (cnt >= 2)
                square = true;
            if (square)
                break;
        }
    }
    if (num != 1)
        temp++;
    if (square)
        return 0;
    if (temp & 1)
        return -1;
    else
        return 1;
}
long long u(long long num)
{
    if (num == 1)
        return 1;
    return prime_factor(num);
}
long long f(long long n, long long k)
{
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int pre = ans;
        int temp = u(i);
        if (temp == 1)
            ans += 1;
        else if (temp == 0)
        {
            if (k == 0)
                ans += 1;
        }
        else if (temp == -1)
        {
            if (k == 0)
                ans += 1;
            else if (k & 1)
                ans += -1;
            else
                ans += 1;
        }
        cout << ans - pre << endl;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> k;
        cout << f(n, k) << endl;
    }
    system("pause");
    return 0;
}