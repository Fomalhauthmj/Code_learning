#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=2E4+50;
const int M=1e5+50;
#define ll long long
int n,m;
struct node
{
    int a,b;
    ll c;
    bool operator<(const node &n) const
    {
        return c>n.c;
    }
}p[M];
int head[N],ver[M<<1],nxt[M<<1],tot=0;
void add(int u,int v)
{
    ver[++tot]=v;
    nxt[tot]=head[u];
    head[u]=tot;
}
int vis[N];
bool DFS(int x,int color)
{
    vis[x]=color;
    for(int i=head[x];i;i=nxt[i])
    {
        int y=ver[i];
        if(!vis[y])
        {
            if(!DFS(y,3-color)) return false;
        }
        else if(vis[y]==color) return false;
    }
    return true;
}
bool Judge(ll mid)
{
    memset(vis,0,sizeof(vis));
    memset(head,0,sizeof(head));
    for(int i=0;i<m;i++)
    {
        if(p[i].c>mid) add(p[i].a,p[i].b),add(p[i].b,p[i].a);
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            if(!DFS(i,1)) return false;
        }
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>p[i].a>>p[i].b>>p[i].c;
    }
    sort(p,p+m);
    //排序后从大到小分配 TLE 
    //二分
    ll left=0;
    ll right=1e9+5;
    ll mid;
    while(left<right)
    {
        mid=(left+right)>>1;
        if(Judge(mid))
        {
            right=mid;
        }
        else left=mid+1;
    }
    cout<<left<<endl;
    system("pause");
    return 0;
}