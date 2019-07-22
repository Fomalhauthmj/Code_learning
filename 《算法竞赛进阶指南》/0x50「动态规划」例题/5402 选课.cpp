#include<iostream>
#include<vector>
using namespace std;
const int N=305;
int n,m;
int credit[N];
vector<int> son[N];
int dp[N][N];
// dp[i][j] 以i为根的子树中选修j门 最大学分
void DP(int rt)
{
    dp[rt][0]=0;
    for(int i=0;i<son[rt].size();i++)//组
    {
        int s=son[rt][i];
        DP(s);
        for(int j=m;j>=0;j--)//已选体积
        {
            for(int k=0;k<=j;k++)//子树s选择体积
            //倒序?
            {
                if(j>=k) dp[rt][j]=max(dp[rt][j],dp[s][k]+dp[rt][j-k]);
            }            
        }
    }
    if(rt)
    {
        //这里正序会导致加入多个credit[rt]
        for(int i=m;i>=1;i--)
            dp[rt][i]=dp[rt][i-1]+credit[rt];
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    int fa;
    for(int i=1;i<=n;i++)
    {
        cin>>fa>>credit[i];
        son[fa].push_back(i);
    }
    DP(0);
    cout<<dp[0][m]<<endl;
    system("pause");
    return 0;
}