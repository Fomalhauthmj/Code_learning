//dp[i]=max(a[i],dp[i-1]+a[i]) ||dp[i-1]<=0 dp[i-1]>0;
#include<iostream>
#include<algorithm>
using namespace std;
#define size 1010
int a[size];
int n;
int dp[size];
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n)
    {
        for(int i=0;i<n;i++) cin>>a[i];
        dp[0]=0;//或者online处理 每输入一个数输出当前结果
        for(int i=1;i<n;i++)
        {
            if(dp[i-1]>0) dp[i]=dp[i-1]+a[i];
            else dp[i]=a[i];
        }//!:测试！
        int ans=0;
        for(int i=0;i<n;i++) ans=max(ans,dp[i]);
        cout<<ans<<endl;
    }
}
//若求端点? 增加一个起点组