//TODO:此题的b范围未知！
#include<iostream>
#include<algorithm>
#include<cstring>
#include<iomanip>
using namespace std;
#define N 105
#define inf 0x3f3f3f3f
struct node
{
    int b;
    int p;
    node(int i1,int i2)
    {
        b=i1;p=i2;
    }
};
int n;
int dp[N][100*N];//dp[i][j] 表示选取前i种最小b为j时的最小p之和
int main()
{
    ios::sync_with_stdio(false);
    int t;cin>>t;
    while(t--)
    {
        cin>>n;
        int each_num;
        int b,p;//online处理 
        int max_b=0;
        memset(dp,-1,sizeof(dp));
        for(int i=1;i<=n;i++)
        {
            cin>>each_num;
            if(i==1)
            {
                for(int j=0;j<each_num;j++) 
                {
                    cin>>b>>p;
                    if(dp[1][b]!=-1) dp[1][b]=min(dp[1][b],p);
                    else dp[1][b]=p;
                    max_b=max(max_b,b);
                }
            }
            else
            {
                for(int j=0;j<each_num;j++)
                {
                    cin>>b>>p;
                    for(int k=0;k<=max_b;k++)
                    {
                        if(dp[i-1][k]!=-1)
                        {
                            if(k<=b)
                            {
                                if(dp[i][k]==-1) dp[i][k]=dp[i-1][k]+p;
                                else dp[i][k]=min(dp[i][k],dp[i-1][k]+p);
                            }
                            else 
                            {
                                if(dp[i][b]==-1) dp[i][b]=dp[i-1][k]+p;
                                else dp[i][b]=min(dp[i][b],dp[i-1][k]+p);
                            }
                        }
                    }
                }
            }
        }
        double ans=0;
        for(int i=0;i<=max_b;i++)
        {
            if(dp[n][i]!=-1)
            {
                ans=max(ans,i*1.0/dp[n][i]);
            }
        }
        cout<<fixed<<setprecision(3)<<ans<<endl;
    }
}
//此题也可枚举输入的b值 剪枝降低复杂度



















/*//TODO:WA
#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
using namespace std;
#define N 105
#define inf 0x3f3f3f3f
struct node1
{
    int b;
    int p;
    node1(int i1,int i2)
    {
        b=i1;p=i2;
    }
};
struct node2
{
    int min_b;
    int tot_p;
    double now_max_bp;
};
vector<node1> V[N];
int n;
node2 dp[N][N];
int main()
{
    ios::sync_with_stdio(false);
    int t;cin>>t;
    while(t--)
    {
        cin>>n;
        int each_num;
        int b,p;
        for(int i=1;i<=n;i++)
        {
            cin>>each_num;
            V[i].clear();
            for(int j=0;j<each_num;j++)
            {
                cin>>b>>p;V[i].push_back(node1(b,p));
            }
        }
        for(int i=0;i<V[1].size();i++)
        {
            dp[1][i].min_b=V[1][i].b;
            dp[1][i].tot_p=V[1][i].p;
            dp[1][i].now_max_bp=V[1][i].b*1.0/V[1][i].p;
        }
        for(int i=2;i<=n;i++)
        {
            int now_len=V[i].size();
            int pre_len=V[i-1].size();
            for(int j=0;j<now_len;j++)
            {
                dp[i][j].now_max_bp=0;
                for(int k=0;k<pre_len;k++)
                {
                    int a=min(V[i][j].b,dp[i-1][k].min_b);
                    int b=dp[i-1][k].tot_p+V[i][j].p;
                    if(a*1.0/b>dp[i][j].now_max_bp)
                    {
                        dp[i][j].min_b=a;
                        dp[i][j].tot_p=b;
                        dp[i][j].now_max_bp=a*1.0/b;
                    }
                }
            }
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<V[i].size();j++)
            {
                 cout<<i<<" "<<j<<" "<<dp[i][j].now_max_bp<<endl;
            }
        }
        //TODO:此种思路在处理时对于前面忽略的选择不能进行回顾 WA！  实质是贪心并非dp
        double ans=0;
        for(int i=0;i<V[n].size();i++) ans=max(ans,dp[n][i].now_max_bp);
        cout<<fixed<<setprecision(3)<<ans<<endl;
    }
}
*/