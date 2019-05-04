#include<iostream>
using namespace std;
#define mod 1000000007
#define N 1000010
#define ll long long
int n;
ll fac[N];//阶乘
ll inv[N];//阶乘逆元
ll h[N/2];
ll quick_pow(ll x,ll n)//快速幂
{
    ll ret=1;
    ll temp=x%mod;
    while(n)
    {
        if(n&1)
        {
            ret=(ret*temp)%mod;
        }
        temp=(temp*temp)%mod; //偶次
        n>>=1;
    }
    return ret;//结果
}
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
    inv[N-1]=quick_pow(fac[N-1],mod-2);//费马小定理 求逆元a^(p-1)%p=1 a的逆元为a^(p-2)
    //如果 ax%p=1 ， 那么x的最小正整数解就是 a 模p的逆元
    for(int i=N-2;i>=0;i--)
    {
        inv[i]=inv[i+1]*(i+1)%mod;
    }
    h[0]=1;
    for(int i=1;i<N/2;i++)
    {
        h[i]=(C(2*i,i)-C(2*i,i+1))%mod;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;cin>>T;
    init();
    while(T--)
    {
        cin>>n;
        long long ans=0;
        /*
        int i;
        if(n&1) i=1;
        else i=0;
        for(;i<=n;i+=2)//枚举停留时间  或者 枚举向右走的步数 都可以
        {
            ans=(ans+C(n,i)*h[(n-i)/2])%mod;
        }
        */
        for(int i=0;i<=n/2;i++)
        {
            ans=(ans+C(n,2*i)*h[i]%mod+mod)%mod;
        }
        cout<<ans<<endl;
    }
}