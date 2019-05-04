//TODO:区间DP
/*
dp[i][j]=区间[i,j]之间计算的最优值
ans:dp[1][n]
*/
#include<iostream>
#include<cstring>
using namespace std;
#define inf 0x3f3f3f3f
#define N 210
int a[N];
int b[N];
int n;
int dp[N][N];//dp[i][j]击杀区间[i,j]之间的狼遭到伤害的最小值
int main()
{
    ios::sync_with_stdio(false);
    int t;cin>>t;
    int casenum=1;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) cin>>b[i];
        b[0]=b[n+1]=0;//对于可能出现的超界情况
        //初始化很重要
        for(int i=1;i<=n;i++)
        {
            dp[i][i-1]=dp[i+1][i]=0;//对于可能出现的非法情况
            for(int j=i;j<=n;j++) dp[i][j]=inf;//初始化inf
            //dp[i][i]=a[i]+b[i-1]+b[i+1];
        }
        for(int r=0;r<=n;r++)//区间长度 
        {
            for(int i=1;i<=n-r;i++)//区间左端点
            {
                int j=i+r;//区间右端点
                for(int k=i;k<=j;k++)//TODO:区间内断点 枚举最后击杀点 注意k:[i,j]  闭区间
                { 
                    dp[i][j]=min(dp[i][j],dp[i][k-1]+dp[k+1][j]+a[k]+b[j+1]+b[i-1]);//最后击杀受到伤害由三部分组成
                    //dp[i][k-1],dp[k+1][j]区间范围内已全部击杀 此时与a[k]相邻的是i-1,j+1位置
                }
            }
        }
        cout<<"Case #"<<casenum++<<": "<<dp[1][n]<<endl;
    }
}