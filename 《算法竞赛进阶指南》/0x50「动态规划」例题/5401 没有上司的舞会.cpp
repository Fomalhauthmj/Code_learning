#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
const int N=6E3+20;
int n,h[N];
int dp[N][2];
vector<int> son[N];
bool vis[N];
/*
dp[i][0] 以i为根的子树中邀请部分 且i不参与 
dp[i][1] 以i为根的子树中邀请部分 且i参与
 */
void DP(int rt)
{
    dp[rt][0]=0;
    dp[rt][1]=h[rt];
    for(int i=0;i<son[rt].size();i++)
    {
        int s=son[rt][i];
        DP(s);
        dp[rt][0]+=max(dp[s][0],dp[s][1]);
        dp[rt][1]+=dp[s][0];
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>h[i];
    int r,s;
    for(int i=0;i<n-1;i++)
    {
        cin>>s>>r;
        son[r].push_back(s);
        vis[s]=1;// s is a son of r
    }
    int root;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            root=i;
            break;
        }
    }
    DP(root);
    cout<<max(dp[root][0],dp[root][1])<<endl;
    system("pause");
    return 0;
}