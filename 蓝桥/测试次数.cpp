#include<iostream>
#include<cstring>
using namespace std;
#define N 1010
#define inf 0x3f3f3f3f
int dp[N][5];//动态规划测试
//dp[x][y] 表示楼层数 表示手机数  表示x楼层y手机 的最大测试次数
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //init 初始化
    for(int i=0;i<N;i++) dp[i][1]=i;
    //状态转移
    //TODO:dp[i][j]=min(dp[i][j],max(dp[k-1][j-1]+1//第一次碎于k层剩余k-1层j-1部,dp[i-k][j]+1//第一次不碎剩余i-k层j部手机))
    for(int j=2;j<5;j++)//先循环手机
    {
        for(int i=1;i<N;i++)
        {
            dp[i][j]=dp[i-1][j]+1;//多一层
            for(int k=1;k<=i;k++)
            {
                dp[i][j]=min(dp[i][j],max(1+dp[k-1][j-1],1+dp[i-k][j]));
                //前一个min 表示最佳策略 后一个max 表示最坏运气
            }
        }
    }
    //ans=dp[1000][3];
    cout<<dp[1000][3]<<endl;
    system("pause");
}