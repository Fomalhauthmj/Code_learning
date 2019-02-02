#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define size 100010
long long a[size];
long long dp[size][3];
// 1买 2卖 0不做
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    int n;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++) cin>>a[i];
        dp[0][0]=0;
        dp[0][1]=
        for(int i=1;i<n;i++)
        {
            dp[i][1]=max(dp[i-1][0]-a[i],max(dp[i-1][1]-a[i],dp[i-1][2]-a[i]));
            dp[i][2]=max(dp[i-1][0]+a[i],)
        }
        cout<<dp[n-1]<<endl;
    }
}