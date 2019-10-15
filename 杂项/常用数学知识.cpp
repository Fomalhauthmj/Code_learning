/*
扩展欧几里得算法
    裴蜀定理
    对于任意整数a,b，存在一对整数x,y，满足ax+by=gcd(a,b)。
    d=gcd(a,b)
    ax+by=c 当且仅当d|c时有解
    ax+by=c 通解:
    x=(c/d)*x0+k*(b/d)
    y=(c/d)*y0-k*(a/d)
    k∈Z,x0,y0为ax+by=gcd(a,b)的一组特解 
*/
#define ll long long
ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if (!b)
    {
        x = 1, y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, x, y), z = x;
    x = y, y = z - y * (a / b);
    return d;
}
/*
    乘法逆元
    a*x≡1(mod m) a,m互质
    a^(p-2)=inv(a,p) p为质数,a<p(a%=p)
*/
//线性递推
inv[1] = 1;
for (int i = 2; i < N; i++)
    inv[i] = (p - p / i) * inv[p % i] % p;
//阶乘逆元 组合数取模
ll fac[N];//阶乘
ll inv[N];//阶乘逆元
ll C(ll a,ll b)
{
    if(b>a) return 0;
    if(b==0) return 1;
    return fac[a]*inv[b]%mod*inv[a-b]%mod;
}
void init()
{
    fac[0]=1;
    for(int i=1;i<N;i++)
    {
        fac[i]=(fac[i-1]*i)%mod;
    }
    inv[N-1]=quick_pow(fac[N-1],mod-2);//费马小定理 求逆元a^(p-1)≡1(mod p)的逆元为a^(p-2)
    for(int i=N-2;i>=0;i--)
    {
        inv[i]=inv[i+1]*(i+1)%mod;
    }
}
//exgcd
ll inv(ll a, ll m)
{
    ll x, y;
    exgcd(a, m, x, y);
    return (x % m + m) % m;
}
/*
    中国剩余定理
*/
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
