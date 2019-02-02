#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define size 100010
int n;
int a[size][11];
int dp[size][11];
//dp[i][j]=max(dp[i-1][j+1],dp[i-1][j-1],dp[i-1][j])+a[i][j]
int main()
{
    ios::sync_with_stdio(false);
    int x,t;
    while(cin>>n)
    {
        if(n==0) break;
        memset(a,0,sizeof(a));
        int time=0;
        for(int i=0;i<n;i++)
        {
            cin>>x>>t;
            time=max(time,t);
            a[t][x]++;
        }
        memset(dp,0,sizeof(dp));
        //为了使问题简化，假设在接下来的一段时间里，馅饼都掉落在0-10这11个位置。
        //开始时gameboy站在5这个位置，因此在第一秒，他只能接到4,5,6这三个位置中其中一个位置上的馅饼。
        /*//TODO:顺序！
        for(int i=1;i<=time;i++)
        {
            if(i==1)
            {
                for(int j=4;j<=6;j++)
                {
                    dp[i][j]=max(dp[i-1][j],max(dp[i-1][j+1],dp[i-1][j-1]))+a[i][j];
                    //cout<<"dp:"<<i<<" "<<j<<" "<<dp[i][j]<<endl;
                }
            }
            else
            {
                for(int j=0;j<11;j++)
                {
                    if(j==0) dp[i][j]=max(dp[i-1][j+1],dp[i-1][j])+a[i][j];
                    else if(j==10) dp[i][j]=max(dp[i-1][j-1],dp[i-1][j])+a[i][j];
                    else dp[i][j]=max(dp[i-1][j],max(dp[i-1][j+1],dp[i-1][j-1]))+a[i][j];
                    //cout<<"dp:"<<i<<" "<<j<<" "<<dp[i][j]<<endl;
                }
            }
        }
        int ans=0;
        for(int i=0;i<11;i++)
        {
            if(dp[time][i]>ans) ans=dp[time][i];
        }
        cout<<ans<<endl;
        */
        //TODO:逆序
        for(int i=time;i>=1;i--)
        {
            dp[i][0]=max(dp[i+1][0],dp[i+1][1])+a[i][0];
            for(int j=1;j<=9;j++)
            {
                dp[i][j]=max(max(dp[i+1][j+1],dp[i+1][j-1]),dp[i+1][j])+a[i][j];
                //cout<<"dp:"<<i<<" "<<j<<" "<<dp[i][j]<<endl;
            }
            dp[i][10]=max(dp[i+1][10],dp[i+1][9])+a[i][10];
        }
        cout<<max(dp[1][4],max(dp[1][5],dp[1][6]))<<endl;
    }
}