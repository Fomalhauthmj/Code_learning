#include<bits/stdc++.h>
using namespace std;
#define N 17
int n,E;
int value[N];
int energy[N];
int make_need[N];
int dp[1<<N];//做好S状态后获得的最大val
int left_E[1<<N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int C;cin>>C;
    int q,pre;
    while(C--)
    {
        cin>>n>>E;
        for(int i=0;i<n;i++) cin>>value[i];//获得
        for(int i=0;i<n;i++) cin>>energy[i];//损耗
        memset(make_need,0,sizeof(make_need));
        for(int i=0;i<n;i++)
        {
            cin>>q;
            for(int j=0;j<q;j++)
            {
                cin>>pre;
                make_need[i]|=(1<<(pre-1));
            }
            //cout<<"make need:"<<make_need[i]<<endl;
        }
        memset(dp,-1,sizeof(dp));
        memset(left_E,-1,sizeof(left_E));
        dp[0]=0;
        left_E[0]=E;
        for(int i=0;i<(1<<n);i++)//每个状态
        {
            if(dp[i]>-1)//已计算过
            {
                for(int j=0;j<n;j++)//每种汉堡
                {
                    if(i&(1<<j)) continue;//已做过此种
                    //未做过
                    //cout<<"will make:"<<j<<endl;
                    if(((i&make_need[j])==make_need[j])&&left_E[i]>=energy[j])
                    //TODO:注意这里条件的书写
                    {
                        //cout<<"have energy and haven't make it before"<<endl;
                        //满足前置条件且剩余能量满足要求
                        int temp=i|(1<<j);//下一状态
                        if(dp[temp]<value[j]+dp[i])//此状态max
                        {
                            dp[temp]=value[j]+dp[i];
                            left_E[temp]=left_E[i]-energy[j];//下一状态剩余的能量
                        }
                    }
                }
            }
        }
        int ans=0;//寻找最大val
        for(int i=0;i<(1<<n);i++)
        {
            //cout<<"dp"<<i<<":"<<dp[i]<<endl;
            ans=max(ans,dp[i]);
        }
        cout<<ans<<endl;
    }
}