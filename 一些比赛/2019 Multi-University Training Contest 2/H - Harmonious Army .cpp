#include<iostream>
#include<stdio.h>
#include<queue>
#include<cstring>
using namespace std;
const int N=505;
const int M=1e6+500;
#define ll long long
#define inf 0x3f3f3f3f
int head[N],ver[M],nxt[M],tot;
ll edge[M];
int n,m,d[N],S,T;
void add(int x,int y,ll w)
{
    ver[++tot]=y,nxt[tot]=head[x],head[x]=tot,edge[tot]=w;
    ver[++tot]=x,nxt[tot]=head[y],head[y]=tot,edge[tot]=0;
}
bool BFS()
{
    memset(d, 0, sizeof(d));
    queue<int> q;
    q.push(S);
    d[S] = 1; //不为1  陷入死循环
    while (q.size())
    {
        int x = q.front();
        q.pop();
        for (int i = head[x]; i; i = nxt[i])
        {
            int y = ver[i];
            if (edge[i] && !d[y])
            {
                d[y] = d[x] + 1;
                q.push(y);
                if (y == T)
                    return true;
            }
        }
    }
    return false;
}
ll Dinic(int x, ll flow)
{
    if (x == T)
        return flow;
    ll rest = flow, k;
    for (int i = head[x]; i && rest; i = nxt[i])
    {
        int y = ver[i];
        if (edge[i] && d[y] == d[x] + 1)
        {
            k = Dinic(y, min(edge[i], rest));
            if (!k)
                d[y] = 0;
            edge[i] -= k;
            edge[i ^ 1] += k;
            rest -= k;
        }
    }
    return flow - rest;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        tot=1;
        memset(head,0,sizeof(head));
        int u,v,a,b,c;
        S=0,T=n+1;
        ll sum=0;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d%d%d",&u,&v,&a,&b,&c);
            int A,B,C;
            A=a+b;
            B=b+c;
            C=a+c-2*b;
            sum+=2*(a+b+c);
            add(S,u,A),add(S,v,A);
            add(u,T,B),add(v,T,B);
            add(u,v,C),add(v,u,C);
        }
        ll maxflow=0,flow;
        while(BFS())
            while(flow=Dinic(S,inf)) maxflow+=flow;
        cout<<(sum-maxflow)/2<<endl;
    }
    //system("pause");
    return 0;
}