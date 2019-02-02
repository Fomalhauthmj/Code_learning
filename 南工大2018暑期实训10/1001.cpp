#include<iostream>
#include<cstring>
using namespace std;
#define size 105
int a[size][size];
int dp[size][size];
int n;
int main()
{
    int t;cin>>t;
    while(t--)
    {
        cin>>n;
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=i;j++) cin>>a[i][j];
        }
        dp[1][1]=a[1][1];
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+a[i][j];
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(dp[n][i]>ans) ans=dp[n][i];
        }
        cout<<ans<<endl;
    }
}