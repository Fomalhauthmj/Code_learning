//TODO:完全背包
#include<iostream>
#include<cstring>
using namespace std;
#define N 105
int n,m,k,s;
int expe[N];
int endu[N];
int dp[N][N]; //dp[i][j] 消耗忍耐度为i且杀怪数为j时的最大经验值

int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n>>m>>k>>s)
    {
        for(int i=1;i<=k;i++) cin>>expe[i]>>endu[i];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=k;i++)
        {
            /*
            for(int r=1;r<=s;r++)
            {
                for(int j=endu[i];j<=m;j++)
                {
                
                    dp[j][r]=max(dp[j][r],dp[j-endu[i]][r-1]+expe[i]);
                }
            }
            */
            
            for(int j=endu[i];j<=m;j++)
            {
                for(int r=1;r<=s;r++)
                {
                    dp[j][r]=max(dp[j][r],dp[j-endu[i]][r-1]+expe[i]);
                }
            }

            //TODO:两种循环方式都可以
        }
        bool flag=false;
        for(int i=0;i<=m;i++)//消耗忍耐度由低到高
        {
            for(int j=s;j>=0;j--)
            {
                if(dp[i][j]>=n) 
                {
                    flag=true;
                    break;
                }
            }
            if(flag) 
            {
                cout<<m-i<<endl;//剩余忍耐度由高到低
                break;
            }
        }
        if(!flag) cout<<-1<<endl;
    }
}