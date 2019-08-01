#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int N = 1e5+50;
int n,k,head[N],nxt[N<<1],edge[N<<1],ver[N<<1],tot=1;
int dp[N];
//dp[rt] 以rt为根的子树 从rt出发最远可达距离
/*
    对于每个结点x f[x]:经过节点x的最长链长度
*/
int diameter,dis[N],path[N];
bool vis[N];
void DP(int rt)
{
    dp[rt]=0;//单点
    vis[rt]=1;
    for(int i=head[rt];i;i=nxt[i])
    {
        int s=ver[i];
        if(!vis[s])
        {
            DP(s);
            diameter=max(diameter,dp[rt]+dp[s]+edge[i]);
            dp[rt]=max(dp[rt],dp[s]+edge[i]);
        }
    }
}
void add(int u,int v,int w)
{   
    ver[++tot]=v;
    nxt[tot]=head[u];
    head[u]=tot;
    edge[tot]=w;
}
void DFS(int start,bool record_path)
{
    vis[start]=1;
    for(int i=head[start];i;i=nxt[i])
    {
        int s=ver[i];
        if(!vis[s])
        {
            dis[s]=dis[start]+edge[i];
            if(record_path) path[s]=i;
            DFS(s,record_path);
        }
    }
    vis[start]=0;//清理
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    int a, b;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        add(a,b,1);
        add(b,a,1);
    }
    dis[1]=0;
    DFS(1,false);
    int temp=0;
    for(int i=1;i<=n;i++)
    {
        if(!temp||dis[temp]<dis[i]) temp=i;
    }
    dis[temp]=0;
    DFS(temp,true);
    temp=0;
    for(int i=1;i<=n;i++)
    {
        if(!temp||dis[temp]<dis[i]) temp=i;
    }
    int l1=dis[temp];
    //cout<<l1<<endl;
    int ans=2*(n-1)-(l1-1);
    if(k==2)
    {
       while(path[temp])
       {
           edge[path[temp]]=edge[path[temp]^1]=-1;
           temp=ver[path[temp]^1];
       }
        diameter=0;
        DP(1);
        int l2=diameter;
        //cout<<l2<<endl;
        ans=2*(n-1)-(l1-1)-(l2-1);
    }
    cout<<ans<<endl;
    //system("pause");
    return 0;
}