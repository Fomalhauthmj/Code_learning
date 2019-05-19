#include<iostream>
#include<cstring>
using namespace std;
#define N 17
#define inf 0x3f3f3f3f
int n;
int a[N];
int pos[N];
long long dp[N][1<<17];//dp[i][S]表示最后一位为a[i]且状态为S的最大相邻乘积和
//dp[j][S|1<<j]=max(dp[j][S|1<<j],dp[i][S]+a[i]*a[j]) a[i]为最后一位  a[j]为下一位
int get_1_bit(int x)
{
    int ret=0;
    while(x>0)
    {
        x-=x&(-x);
        ret++;
    }
    return ret;//获得该状态1的数量
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;cin>>T;
    int casenum=1;
    while(T--)
    {
        cin>>n;
        memset(pos,-1,sizeof(pos));
        for(int i=0;i<n;i++) 
        {
            cin>>a[i]>>pos[i];
        }
        //状压dp
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<(1<<n);j++)
            {
                dp[i][j]=-inf;
            }
        }
        /*
        for(int i=0;i<n;i++)//枚举最后一位 !:上下两层循环位置调换
        {
            for(int j=0;j<(1<<n);j++)//枚举当前状态 j中1的个数表示已经排好的数量
            {
                if(get_1_bit(j)<=1) dp[i][j]=0;
                if(pos[i]>-1&&pos[i]+1!=get_1_bit(j)) continue;//若pos[i]固定 已经排好的数量必须等于pos[i]+1
                if(j&(1<<i))
                {
                    for(int k=0;k<n;k++)//枚举下一位
                    {
                        if(j&(1<<k)) continue;//已有
                        if(pos[k]>-1&&pos[k]!=get_1_bit(j)) continue;
                        dp[k][j|(1<<k)]=max(dp[k][j|(1<<k)],dp[i][j]+a[i]*a[k]);
                    }
                }
            }
        }
        */
        for(int i=0;i<(1<<n);i++)//枚举当前状态
        {
            for(int j=0;j<n;j++)//枚举结束位
            {
                if(get_1_bit(i)<=1) dp[j][i]=0;
                if(pos[j]>-1&&pos[j]+1!=get_1_bit(i)) continue;
                if(i&(1<<j))
                {
                    for(int k=0;k<n;k++)//枚举下一位
                    {
                        if(i&(1<<k)) continue;
                        if(pos[k]>-1&&pos[k]!=get_1_bit(i)) continue;
                        dp[k][i|(1<<k)]=max(dp[k][i|(1<<k)],dp[j][i]+a[j]*a[k]);
                    }
                }
            }
        }
        /*
        for(int i=0;i<n;i++)
        {
            cout<<dp[i][(1<<n)-1]<<endl;
        }
        */
        cout<<"Case #"<<casenum++<<":"<<endl;
        long long ans=-inf;
        for(int i=0;i<n;i++) ans=max(ans,dp[i][(1<<n)-1]);//获得不同结尾的最大值
        cout<<ans<<endl;
    }
}