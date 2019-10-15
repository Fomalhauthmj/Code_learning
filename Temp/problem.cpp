#include<iostream>
using namespace std;
const int N=2e5+50;
#define ll long long
int a[N];
ll dp[N][2];
int main()
{
    ll n;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),a[i]=(a[i]>0)?1:-1;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>0)
        {
            dp[i][0]=1,dp[i][1]=0;
            dp[i][0]+=dp[i-1][0];
            dp[i][1]+=dp[i-1][1];
        }
        else
        {
            dp[i][0]=0,dp[i][1]=1;
            dp[i][0]+=dp[i-1][1];
            dp[i][1]+=dp[i-1][0];
        }
    }
    ll sum=n*(n+1)/2;
    ll ans=0;
    for(int i=1;i<=n;i++)
        ans+=dp[i][0];
    printf("%lld %lld\n",sum-ans,ans);
    //system("pause");
    return 0;
}