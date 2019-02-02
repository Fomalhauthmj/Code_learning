#include<bits/stdc++.h>
using namespace std;
int main()
{
    int value[41],temp[41];
    int credit[9];
    int num[9];
    int t;
    cin>>t;
    while(t--)
    {
        memset(value,0,sizeof(value));
        memset(temp,0,sizeof(temp));
        memset(num,0,sizeof(num));
        memset(credit,0,sizeof(credit));
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=k;i++) cin>>credit[i]>>num[i];
        for(int i=0;i<=num[1]&&i*credit[1]<=n;i++) value[i*credit[1]]=1;
        for(int i=2;i<=k;i++)
        {
            for(int j=0;j<=n;j++)
            {
                for(int l=0;l<=num[i]&&j+l*credit[i]<=n;l++)
                    temp[j+l*credit[i]]+=value[j];
            }
            for(int j=0;j<=n;j++)
            {
                value[j]=temp[j];
                temp[j]=0;
            }
        }
        cout<<value[n]<<endl;
    }
}
//int main()
//{
//    int dp[41];
//    int credit[9];
//    int num[9];
//    int t;
//    cin>>t;
//    while(t--)
//    {
//        memset(dp,0,sizeof(dp));
//        memset(num,0,sizeof(num));
//        memset(credit,0,sizeof(credit));
//        dp[0]=1;
//        int n,k;
//        cin>>n>>k;
//        for(int i=1;i<=k;i++) cin>>credit[i]>>num[i];
//        for(int i=1;i<=k;i++)
//        {
//            for(int j=n;j>=credit[i];j--)
//            {
//                for(int l=1;l<=num[i]&&j-l*credit[i]>=0;l++)
//                    dp[j]+=dp[j-credit[i]*l];
//            }
//        }
//        cout<<dp[n]<<endl;
//
//    }
//}
