//TODO:最大连续子序列 输出起始点与结束点 若有多解 输出较前解
#include<iostream>
#include<cstring>
using namespace std;
#define N 100010
#define inf 0x3f3f3f3f
int dp[N];//dp[i]:结束点为a[i]的状态
int a[N];
int n;
int st[N];
int main()
{
    ios::sync_with_stdio(false);
    int t;cin>>t;
    int casenum=1;
    int start,end;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        memset(dp,0,sizeof(dp));
        dp[1]=a[1];
        st[1]=1;
        for(int i=2;i<=n;i++)
        {
            if(dp[i-1]<0) 
            {
                dp[i]=a[i];
                st[i]=i;
            }
            else 
            {
                dp[i]=dp[i-1]+a[i];
                st[i]=st[i-1]; 
            }
        }
        int ans=-inf;
        for(int i=1;i<=n;i++) 
        {
            if(ans<dp[i]) 
            {
                ans=dp[i];
                start=st[i];
                end=i;
            }
        }
        cout<<"Case "<<casenum++<<":"<<endl;
        cout<<ans<<" "<<start<<" "<<end<<endl;
        if(t!=0) cout<<endl;
    }
}