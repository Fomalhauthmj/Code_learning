#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
//int dis[1010];
//bool inq[1010];
int G[1001][1001];
int start[1001];
int ending[1001];
int T,S,D;
struct node
{
    int dis;
    int dispos;
    bool operator < (const node &n) const
    {
        return dis>n.dis;
    }
};
int Dijkstra(int i)
{
    int dis[1001];
    for(int i=1;i<=1000;i++) dis[i]=inf;
    priority_queue<node> pq;
    node s;
    s.dis=0;
    s.dispos=start[i];
    pq.push(s);
    dis[start[i]]=0;
    while(!pq.empty())
    {
        node temp=pq.top();
        int now=temp.dispos;
        pq.pop();
        for(int i=1;i<=1000;i++)
        {
            if(dis[i]>dis[now]+G[now][i])
            {
                dis[i]=dis[now]+G[now][i];
                node newnode;
                newnode.dis=dis[i];
                newnode.dispos=i;
                pq.push(newnode);
            }
        }
    }
    int result=inf;
    for(int i=1;i<=D;i++)
    {
        if(result>dis[ending[i]]) result=dis[ending[i]];
    }
    return result;
}
//int Floyd()
//{
//    for(int k=1;k<=1000;k++)
//    {
//        for(int i=1;i<=1000;i++)
//        {
//            if(G[i][k]!=inf)
//            {
//                for(int j=1;j<=1000;j++)
//                {
//                    if(G[i][j]>G[i][k]+G[k][j])
//                        G[i][j]=G[i][k]+G[k][j];
//                }
//            }
//        }
//    }
//    int result=inf;
//    for(int i=1;i<=S;i++)
//    {
//        for(int j=1;j<=D;j++)
//        {
//            if(G[start[i]][ending[j]]<result)
//                result=G[start[i]][ending[j]];
//        }
//    }
//    return result;
//}
//int SPFA()
//{
//    memset(inq,0,sizeof(inq));
//    for(int i=1;i<=1000;i++) dis[i]=inf;
//    queue<int>Q;
//    for(int i=1;i<=S;i++)
//    {
//        Q.push(start[i]);
//        dis[start[i]]=0;
//        inq[start[i]]=1;
//    }
//    while(!Q.empty())
//    {
//        int now=Q.front();
//        Q.pop();
//        inq[now]=0;
//        for(int j=1;j<=1000;j++)
//        {
//            if(dis[j]>dis[now]+G[now][j])
//            {
//                dis[j]=dis[now]+G[now][j];
//                if(inq[j]==0)
//                {
//                    inq[j]=1;
//                    Q.push(j);
//                }
//            }
//        }
//    }
//    int result=dis[ending[1]];
//    for(int j=1;j<=D;j++)
//    {
//        if(dis[ending[j]]<result)
//            result=dis[ending[j]];
//    }
//    return result;
//}
int main()
{
    while(cin>>T>>S>>D)
    {
        for(int i=1;i<=1000;i++)
        {
            for(int j=1;j<=1000;j++)
            {
                G[i][j]=inf;
            }
        }
        memset(start,0,sizeof(start));
        memset(ending,0,sizeof(ending));
        for(int i=1;i<=T;i++)
        {
            int a,b,time;
            cin>>a>>b>>time;
            if(G[a][b]>time)
            {
                G[a][b]=time;
                G[b][a]=time;
            }
        }
        for(int i=1;i<=S;i++) cin>>start[i];
        for(int i=1;i<=D;i++) cin>>ending[i];
        int result=inf;
        for(int i=1;i<=S;i++)
        {
            int temp=Dijkstra(i);
            if(temp<result) result=temp;
        }
        cout<<result<<endl;
    }
}
