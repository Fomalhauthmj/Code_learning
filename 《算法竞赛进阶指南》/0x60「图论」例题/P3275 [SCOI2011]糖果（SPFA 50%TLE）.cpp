#include<iostream>
#include<stdio.h>
#include<queue>
#include<cstring>
using namespace std;
const int N=1e5+50;
#define inf 0x3f3f3f3f
#define ll long long
int head[N],ver[N],nxt[N],edge[N],tot=1,cnt[N];
int d[N],n,m;
bool vis[N];
//差分约束
void add(int u,int v,int w)
{
    ver[++tot]=v;
    nxt[tot]=head[u];
    head[u]=tot;
    edge[tot]=w;
}
bool SPFA()
{
    for(int i=0;i<N;i++) d[i]=-inf;
    queue<int> q;
    q.push(0);
    d[0]=0,vis[0]=1,cnt[0]=0;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        vis[x]=false;
        for(int i=head[x];i;i=nxt[i])
        {
            int y=ver[i];
            if(d[y]<d[x]+edge[i])
            {
                d[y]=d[x]+edge[i];
                cnt[y]=cnt[x]+1;
                if(cnt[y]>=n+1) return false;
                if(!vis[y])
                {
                    q.push(y),vis[y]=true;
                }
            }
        }
    }
    return true;
}
int main()
{
    scanf("%d%d",&n,&m);
    int x,a,b;
    //d[i]>=1  d[i]>=d[0]+1
    for(int i=1;i<=n;i++)
        add(0,i,1);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&x,&a,&b);
        switch (x)
        {
        case 1:
        //a=b d[a]-d[b]>=0 d[a]-d[b]<=0
            add(a,b,0);
            add(b,a,0);
            break;
        case 2:
        //a<b d[b]-d[a]>=1
            add(a,b,1);
            break;
        case 3:
        //a>=b  d[a]-d[b]>=0
            add(b,a,0);
            break;
        case 4:
        //a>b d[a]-d[b]>=1
            add(b,a,1);
            break;
        case 5:
        //a<=b d[b]-d[a]>=0
            add(a,b,0);
            break;
        }
    }
    if(!SPFA()) cout<<-1<<endl;
    else
    {
        ll ans=0;
        for(int i=1;i<=n;i++) ans+=d[i];
        cout<<ans<<endl;
    }
    system("pause");
    return 0;
}