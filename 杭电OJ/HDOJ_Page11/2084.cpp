#include<bits/stdc++.h>
using namespace std;
int main()
{
    int c;
    cin>>c;
    while(c--)
    {
        int n;
        cin>>n;
        int num[n+1][n+1]={0};
        for(int i=1;i<=n;i++)
            for(int j=1;j<=i;j++)
            cin>>num[i][j];
        int dp[n+1][n+1]={0};
        dp[1][1]=num[1][1];
        int result=dp[n][1];
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+num[i][j];
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(dp[n][i]>result) result=dp[n][i];
        }
        cout<<result<<endl;
    }
}
//int main()
//{
//    int c;
//    cin>>c;
//    while(c--)
//    {
//        int n;
//        cin>>n;
//        int num[n+1][n+1]={0};
//        for(int i=1;i<=n;i++)
//            for(int j=1;j<=i;j++)
//        {
//            cin>>num[i][j];
//        }
//        int dp[n+1][n+1];
//        memset(dp,0,sizeof(dp));
//        for(int i=1;i<=n;i++) dp[n][i]=num[n][i];
//        for(int i=n-1;i>=1;i--)
//        {
//            for(int j=1;j<=i;j++)
//            {
//                dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+num[i][j];
//            }
//        }
//        cout<<dp[1][1]<<endl;
//    }
//}
