#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
#define N 105
int n,m;
int dp[N][175][175];
int row[N];
int legal_s[1<<11];//合法的状态
int s_cnt[1<<11];//每一合法状态所能放的士兵数量
//曼哈顿距离为两轴坐标差绝对值和
int get_1_bit(int x)
{
    int ret=0;
    while(x>0)
    {
        x-=x&(-x);
        ret++;
    }
    return ret;//获得一个二进制串中1的数量
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>n>>m)
    {
        int bit;
        for(int i=0;i<n;i++)
        {
            row[i]=0;
            for(int j=0;j<m;j++)
            {
                cin>>bit;
                if(!bit)//bit==0  不可放置换为1
                {
                    row[i]=(row[i]<<1)|1;
                }
                else//bit==1  可以放置换为0
                {
                    row[i]<<=1;
                }
            }
            //cout<<"row:"<<row[i]<<endl;
        }
        //枚举合法状态
        int cnt=0;
        for(int i=0;i<(1<<m);i++)
        {
            //因为对于每一行来说只要1之间相距大于1格即可
            if(i&(i<<2)) continue;//不符合
            legal_s[cnt]=i;
            s_cnt[cnt++]=get_1_bit(i);
            //cout<<"legal:"<<i<<" cnt:"<<s_cnt[cnt-1]<<endl;
        }
        //cout<<"max cnt:"<<cnt<<endl;//最多有169种合法状态
        //初始化
        memset(dp,0,sizeof(dp));
        for(int i=0;i<cnt;i++)
        {
            if(row[0]&legal_s[i]) continue;//不一致  0-1正好相对
            //一致
            dp[0][i][0]=s_cnt[i];
        }
        for(int i=1;i<n;i++)//当前行
        {
            for(int j=0;j<cnt;j++)//当前行状态
            {
                if(row[i]&legal_s[j]) continue;//不一致
                //一致 合法状态
                for(int k=0;k<cnt;k++)//前一行状态
                {
                    if((legal_s[j]<<1)&legal_s[k]||(legal_s[j]>>1)&legal_s[k]) continue;
                    //出现斜对角的不合法状态
                    for(int r=0;r<cnt;r++)//再前一行状态
                    {
                        if(legal_s[j]&legal_s[r]) continue;
                        //出现竖直的不合法情况
                        //筛选后留下合法状态
                        dp[i][j][k]=max(dp[i][j][k],dp[i-1][k][r]+s_cnt[j]);
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<cnt;i++)
        {
            for(int j=0;j<cnt;j++)
            {
                ans=max(ans,dp[n-1][i][j]);
            }
        }
        cout<<ans<<endl;
    }
}