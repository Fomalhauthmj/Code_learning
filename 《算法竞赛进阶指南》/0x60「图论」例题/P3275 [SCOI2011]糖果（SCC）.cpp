#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
const int N=1e5+50;
#define inf 0x3f3f3f3f
#define ll long long
int head[N],ver[2*N],nxt[2*N],edge[2*N],tot=1,n,m;
//差分约束
void add(int u,int v,int w)
{
    ver[++tot]=v;
    nxt[tot]=head[u];
    head[u]=tot;
    edge[tot]=w;
}
int num,dfn[N],low[N],stack[N],top,color[N],cnt;
bool in_stack[N];
void Tarjan(int x)
{
    dfn[x]=low[x]=++num;
    stack[++top]=x,in_stack[x]=true;
    for(int i=head[x];i;i=nxt[i])
    {
        int y=ver[i];
        if(!dfn[y])
        {
            Tarjan(y);
            low[x]=min(low[x],low[y]);
        }
        else if(in_stack[y]) low[x]=min(low[x],dfn[y]);
    }
    if(dfn[x]==low[x])
    {
        ++cnt;
        int y;
        do
        {
            y=stack[top--],color[y]=cnt,in_stack[y]=false;
        } while (x!=y);
    }
}
bool SCC()
{
    for(int i=0;i<=n;i++)
        if(!dfn[i]) Tarjan(i);
    for(int i=1;i<=cnt;i++)
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
    system("pause");
    return 0;
}