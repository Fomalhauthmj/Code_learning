/*
扩展欧几里得算法
    裴蜀定理
    对于任意整数a,b，存在一对整数x,y，满足ax+by=gcd(a,b)。
    d=gcd(a,b)
*/
#define ll long long
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

ll a[N], m[N];
// x≡a(mod m)
// TODO 可能溢出 参考2009年国家集训队论文，骆可强：《论程序底层优化的一些方法与技巧》
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
