#include<iostream>
#include<cstring>
using namespace std;
#define size 1010
int n;
int value[size];
int dp[size];
void LIS(int pos)
{
    memset(dp,0,sizeof(dp));
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        dp[i]=value[i];
        for(int j=1;j<i;j++)
        {
            if(value[j]<value[i]&&(dp[j]+value[i])>dp[i]) dp[i]=dp[j]+value[i];
        }
        if(ans<dp[i]) ans=dp[i];
    }
    cout<<ans<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n)
    {
        if(n==0) break;
        for(int i=1;i<=n;i++) cin>>value[i];
        LIS(n);
    }
}