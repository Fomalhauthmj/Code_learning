#include <iostream>
using namespace std;
#define ll long long
const int N = 1e4 + 50;
ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, x, y);
    ll z = x;
    x = y;
    y = z - y * (a / b);
    return d;
}
int n;
ll a[N], m[N];
// x≡a(mod m)
// TODO 引用自2009年国家集训队论文，骆可强：《论程序底层优化的一些方法与技巧》
ll excrt()
{
    ll M = m[1], A = a[1], t, d, x, y;
    for (int i = 2; i <= n; i++)
    {
        d = exgcd(M, m[i], x, y); //解方程
        if ((a[i] - A) % d)
            return -1;                                          //无解
        x *= (a[i] - A) / d, t = m[i] / d, x = (x % t + t) % t; //求x
        A = M * x + A, M = M / d * m[i], A %= M;
    }
    A = (A % M + M) % M;
    return A;
}
ll fib[85];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld%lld", &m[i], &a[i]);
    ll val = excrt();
    if (val == -1)
        printf("Tankernb!\n");
    else
    {
        fib[0] = fib[1] = 1;
        bool flag = true;
        for (int i = 2; i < 85; i++)
        {
            fib[i] = fib[i - 1] + fib[i - 2];
            if (fib[i] == val)
                flag = false;
        }
        if (flag)
            printf("Zgxnb!\n");
        else
            printf("Lbnb!\n");
    }
    //system("pause");
    return 0;
}