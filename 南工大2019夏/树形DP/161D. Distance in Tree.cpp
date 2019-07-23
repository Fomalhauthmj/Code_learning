//http://codeforces.com/problemset/problem/161/D
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
#define ll long long
const int N=5E4+50,K=5e2+5;
int n,k;
ll dp[N][K];
/*
dp[rt][j] 以rt为根距离为j的顶点个数
dp[rt][j]=sigma(dp[s][j-1])

二次扫描换根法的应用 💢
 */
vector<int> son[N];
bool vis[N];
void DP(int rt)
{
    vis[rt]=1;
    dp[rt][0]=1;
    for(int i=0;i<son[rt].size();i++)
    {
        int s=son[rt][i];
        if(!vis[s])
        {
            DP(s);
            for(int j=1;j<=k;j++)
            {
                dp[rt][j]+=dp[s][j-1];
            }
        }
    }
}
void DFS(int rt)
{
    vis[rt]=1;
    for(int i=0;i<son[rt].size();i++)
    {
        int s=son[rt][i];
        if(!vis[s])
        {
            for(int j=k;j>=1;j--)
            {
                //注意这里倒序更新 正序更新会将新值代入计算
                dp[s][j]+=dp[rt][j-1];
                if(j>=2)    dp[s][j]-=dp[s][j-2];
            }
            DFS(s);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    int u,v;
    for(int i=0;i<n-1;i++)
    {
        cin>>u>>v;
        son[u].push_back(v);
        son[v].push_back(u);
    }
    int root=1;
    DP(root);
    memset(vis,0,sizeof(vis));
    DFS(root);
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=dp[i][k];
    }
    cout<<ans/2<<endl;
    //system("pause");
    return 0;
}