#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
const int N=3e6+50;
const int M=8e6+50;
#define inf 0x3f3f3f3f
int head[N],ver[M],nxt[M],tot=1,edge[M];
int n,m,S,T,d[N];
char str[N],line[N];
void add(int x,int y,int z)
{
    ver[++tot]=y,nxt[tot]=head[x],head[x]=tot,edge[tot]=z;
    ver[++tot]=x,nxt[tot]=head[y],head[y]=tot,edge[tot]=0;
}
int H(int x,int y)
{
    return (x-1)*m+y;
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
int Dinic(int x, int flow)
{
    if (x == T)
        return flow;
    int rest = flow, k;
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
bool Judge(int x,int y)
{
    if(x<1||x>n||y<1||y>m||str[H(x,y)]=='#')
        return false;
    return true;
}
int main()
{
    scanf("%d%d",&n,&m);
    int cnt=n*m;
    for(int i=1;i<=n;i++)
    {
        scanf("%s",line);
        for(int j=1;j<=m;j++)
            str[H(i,j)]=line[j-1];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            add(H(i,j),H(i,j)+cnt,1);
            if(Judge(i+1,j))
                add(H(i,j)+cnt,H(i+1,j),1);
            if(Judge(i,j+1))
                add(H(i,j)+cnt,H(i,j+1),1);
        }
    }
    int maxflow=0,flow;
    S=0,T=2*n*m+1;
    add(S,H(1,1),inf),add(H(n,m)+cnt,T,inf);
    add(H(1,1),H(1,1)+cnt,inf),add(H(n,m),H(n,m)+cnt,inf);
    while(BFS())
        while(flow=Dinic(S,inf)) maxflow+=flow;
    printf("%d\n",maxflow);
    //system("pause");
    return 0;
}
/*
4 5
.....
....#
.....
..#..
*/   