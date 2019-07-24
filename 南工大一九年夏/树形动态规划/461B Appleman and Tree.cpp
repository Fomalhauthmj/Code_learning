//http://codeforces.com/problemset/problem/461/B 2200
#include<iostream>
#include<vector>
using namespace std;
#define ll long long
const int N=2E5+50;
const ll MOD=1e9+7;
vector<int> son[N];
bool color[N],vis[N];
ll dp[N][2];
int n;
/*
dp[rt][0] 以rt为根的子树 0个黑点
dp[rt][1] 以rt为根的子树 1个黑点

rt为黑点 对于s∈son[rt]
dp[rt][0]=0 dp[rt][1]=1

dp[rt][1]=dp[rt][1]*(dp[s][1]+dp[s][0]) 断开+不断开
dp[rt][0]=0
rt为白点
dp[rt][0]=1 dp[rt][1]=0

 */
void DP(int rt)
{
    vis[rt]=1;
    if(color[rt]) dp[rt][1]=1,dp[rt][0]=0;
    else dp[rt][0]=1,dp[rt][1]=0;
    for(int i=0;i<son[rt].size();i++)
    {
        int s=son[rt][i];
        if(!vis[s])
        {
            DP(s);
            if(color[rt])
            {
                dp[rt][1]=((dp[s][0]+dp[s][1])*dp[rt][1])%MOD;
            }
            else
            {
                dp[rt][1]=(dp[rt][0]*dp[s][1]+dp[rt][1]*(dp[s][0]+dp[s][1]))%MOD;
                dp[rt][0]=((dp[s][0]+dp[s][1])*dp[rt][0])%MOD;
                //注意更新顺序
            }
        }
    }
    //cout<<"rt:"<<rt<<" 0:"<<dp[rt][0]<<" 1:"<<dp[rt][1]<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    int con;
    for(int i=1;i<=n-1;i++)
    {
        cin>>con;
        son[i].push_back(con);
        son[con].push_back(i);
    }
    for(int i=0;i<=n-1;i++)
        cin>>color[i];
    int root=0;
    DP(root);
    cout<<dp[root][1]%MOD<<endl;
    //system("pause");
    return 0;
}