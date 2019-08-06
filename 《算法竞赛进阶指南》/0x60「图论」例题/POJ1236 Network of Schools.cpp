#include<iostream>
#include<stdio.h>
using namespace std;
const int N=1E4+50;
const int M=5E6+20;
int head[N],ver[M<<1],nxt[M<<1],tot;
void add(int u,int v)
{
    ver[++tot]=v,nxt[tot]=head[u],head[u]=tot;
}
int n,stack[N],top,dfn[N],low[N],num,cnt,color[N];
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
        else if(in_stack[y])
            low[x]=min(low[x],dfn[y]);
    }
    if(dfn[x]==low[x])
    {
        cnt++;
        int y;
        do
        {
            y=stack[top--],in_stack[y]=false;
            color[y]=cnt;
        } while (x!=y);
    }
}
int ind[N],outd[N];
void SCC()
{
    for(int i=1;i<=n;i++)
        if(!dfn[i]) Tarjan(i);
    //SCC 缩点
    for(int x=1;x<=n;x++)
    {
        for(int i=head[x];i;i=nxt[i])
        {
            int y=ver[i];
            int u=color[x],v=color[y];
            if(u!=v)
            {
                ind[v]++,outd[u]++;  
            }
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int x=1;x<=n;x++)
    {
        int y;
        while(scanf("%d",&y)&&y)
        {
            add(x,y);
        }
    }
    SCC();
    int in0=0,out0=0;
    for(int i=1;i<=cnt;i++)
    {
        if(!ind[i]) in0++;
        if(!outd[i]) out0++;
    }
    if(cnt!=1)cout<<in0<<endl<<max(in0,out0)<<endl;
    else cout<<1<<endl<<0<<endl;
    system("pause");
    return 0;
}