#include<iostream>
#include<math.h>
using namespace std;
const int N=4e5+50;
#define ll long long
ll GCD(ll a,ll b)
{
    return b?GCD(b,a%b):a;
}
ll n;
ll prime[105],cnt[105];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    ll val;
    ll gcd;
    for(int i=1;i<=n;i++)
    {
        cin>>val;
        if(i==1)    gcd=val;
        else gcd=GCD(val,gcd);
    }
    int p=0;
    for(int i=2;i<=sqrt(gcd);i++)
    {
        if(gcd%i==0)
        {
            prime[++p]=i,cnt[p]=0;
            while(gcd%i==0) gcd/=i,cnt[p]++;
        }
    }
    if(gcd>1) prime[++p]=gcd,cnt[p]=1;
    ll ans=1;
    for(int i=1;i<=p;i++)
        ans*=(cnt[i]+1);
    cout<<ans<<endl;
    //system("pause");
    return 0;
}