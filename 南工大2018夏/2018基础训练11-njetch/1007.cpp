#include<iostream>
#include<cstring>
using namespace std;
#define N 105
#define inf 0x3f3f3f3f
int a[N][N];
int n;
int sum[N][N];
int dp[N];
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n)
    {
        memset(sum,0,sizeof(sum));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++) 
            {
                cin>>a[i][j];
                if(i==1) sum[1][j]=a[1][j];
                else sum[i][j]=sum[i-1][j]+a[i][j];
                //计算前缀和
            }
        }
        //对于不同行的sum和计算最大连续和
        int ans=-inf;
        for(int i=1;i<=n;i++)//起始行为1-n
        {
            for(int j=i;j<=n;j++)//终止行i-n
            {
                dp[1]=sum[j][1]-sum[i-1][1];
                for(int k=1;k<=n;k++)
                {
                    if(dp[k-1]<=0) dp[k]=sum[j][k]-sum[i-1][k];
                    else dp[k]=dp[k-1]+sum[j][k]-sum[i-1][k];
                }
                int temp=-inf;
                for(int k=1;k<=n;k++) temp=max(temp,dp[k]);
                ans=max(ans,temp);
            }
        }
        cout<<ans<<endl;
    }
}
