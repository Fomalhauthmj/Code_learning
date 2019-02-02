/*
#include<iostream>
#include<cstring>
using namespace std;
#define mod 1000000007
#define N 1010
int n,m;//<=1000
long long ans;
int a[N];
long long c[N][N];

//对于nxm的棋盘 最多放置数为 min(n,m)
//ans=C(max(n,m),min(n,m))
void init()
{
    memset(c,0,sizeof(c));
    c[0][0]=1;//初始化
    for(int i=1;i<N;i++)
    {
        c[i][0]=c[i][i]=1;//初始化
        for(int j=1;j<i;j++)
        {
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;//打表
        }
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
        int n,m;
        cin>>n>>m;
        cout<<c[max(n,m)][min(n,m)]<<endl;
    }

}
*/




//TODO:组合数取余+逆元
#include<iostream>
using namespace std;
#define N 100010
#define mod 1000000007
#define ll long long
ll fac[N];//阶乘
ll inv[N];//阶乘逆元
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
}
ll C(ll a,ll b)
{
    if(b>a) return 0;
    if(b==0) return 1;
    return fac[a]*inv[b]%mod*inv[a-b]%mod;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;cin>>t;
    init();
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        cout<<C(max(n,m),min(n,m))<<endl;
    }
}