//!:完全背包:必须恰好装满


//!:解法1 基于完全背包装满下的最大价值
/*
#include<iostream>
#include<cstring>
#include<math.h>
using namespace std;
#define N 505
#define inf 0x3f3f3f3f
int p[N];
int w[N];
int dp[10010];//dp[i]表示当质量为i时的最小价值和
int weight;
int main()
{
    ios::sync_with_stdio(false);
    int t;cin>>t;
    int e,f;
    int n;
    while(t--)
    {
        cin>>e>>f;
        weight=f-e;
        cin>>n;
        for(int i=1;i<=n;i++) 
        {
            cin>>p[i]>>w[i];
            p[i]=-p[i];//以负数存入 ans=最大值的绝对值！
        }
        for(int i=0;i<=weight;i++) dp[i]=-inf;
        dp[0]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=w[i];j<=weight;j++)
            {
              if(dp[j-w[i]]!=-inf) dp[j]=max(dp[j],dp[j-w[i]]+p[i]);
            }
        }
        if(dp[weight]!=-inf) cout<<"The minimum amount of money in the piggy-bank is "<<abs(dp[weight])<<"."<<endl;
        else cout<<"This is impossible."<<endl;
    }
}
*/

//!:参考解法
#include<iostream>
#include<cstring>
#include<math.h>
using namespace std;
#define N 505
#define inf 0x3f3f3f3f
int p[N];
int w[N];
int dp[10010];//dp[i]表示当质量为i时的最小价值和
int weight;
int main()
{
    ios::sync_with_stdio(false);
    int t;cin>>t;
    int e,f;
    int n;
    while(t--)
    {
        cin>>e>>f;
        weight=f-e;
        cin>>n;
        for(int i=1;i<=n;i++) 
        {
            cin>>p[i]>>w[i];
        }
        for(int i=0;i<=weight;i++) dp[i]=inf;//求min 初始化为极大值
        dp[0]=0;//自然状态下w=0 价值为0
        for(int i=1;i<=n;i++)
        {
            for(int j=w[i];j<=weight;j++)//完全背包正向循环
            {
              dp[j]=min(dp[j],dp[j-w[i]]+p[i]);//如果dp[j-w[i]]=inf dp[j]=inf
            }
        }
        //如果到最后装满时的dp[weight] 未改变 则无法装满 
        if(dp[weight]!=inf) cout<<"The minimum amount of money in the piggy-bank is "<<dp[weight]<<"."<<endl;
        else cout<<"This is impossible."<<endl;
    }
}