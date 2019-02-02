//TODO:Dijkstra's Algorithm
/*
#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
#define N 100010
#define inf 0x3f3f3f3f
struct node
{
    int to;
    int weight;
    node(int i1,int i2)
    {
        to=i1;
        weight=i2;
    }
    bool operator<(const node &n) const
    {
        return weight>n.weight;
    }
};
vector<pair<int,int>> G[N];// first:end  second:weight
int n,m;
priority_queue<node> PQ;
int dis[N];
bool vis[N];
int Dijkstra(int start,int end)
{
    for(int i=1;i<=n;i++)
    {
        dis[i]=inf;
    }
    memset(vis,0,sizeof(vis));
    while(!PQ.empty()) PQ.pop();
    PQ.push(node(start,0));
    dis[start]=0;
    while(!PQ.empty())
    {
        node now=PQ.top();
        PQ.pop();
        if(!vis[now.to])
        {
            for(auto ele:G[now.to])
            {
                if(dis[now.to]+ele.second<dis[ele.first])
                {
                    dis[ele.first]=dis[now.to]+ele.second;
                    PQ.push(node(ele.first,dis[ele.first]));
                }
            }
            vis[now.to]=1;
        }
    }
    if(dis[end]==inf) return -1;
    else return dis[end];
}
int main()
{
    ios::sync_with_stdio(false);
    int a,b,c;
    int start,end;
    while(cin>>n>>m)
    {
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=1;i<=m;i++)
        {   
            cin>>a>>b>>c;
            G[a+1].push_back(make_pair(b+1,c));
            G[b+1].push_back(make_pair(a+1,c));
            //无向图
        }
        cin>>start>>end;
        cout<<Dijkstra(start+1,end+1)<<endl;
    }
}
*/
/*
6 9
1 2 1
1 3 4
2 3 2
2 4 7
2 5 5
3 5 1
4 5 3
4 6 2
5 6 6
*/
#include<iostream>
#include<Windows.h>
#include<vector>
using namespace std;
int n,m;
vector<int> G[25];
int ans[20];
bool vis[25];
int cnt;
int path=0;
void DFS(int depth,int cur)
{
    if(depth>=19)
    {
        path++;
        for(int i=0;i<cnt;i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        return;
    }
    for(auto ele:G[cur])
    {
        if(!vis[ele])
        {
            vis[ele]=1;
            ans[cnt++]=ele;
            DFS(depth+1,ele);
            vis[ele]=0;
            cnt--;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    SYSTEMTIME sys;
    cin>>n>>m;
    for(int i=1;i<=n;i++) G[i].clear();
    int a,b;
    for(int i=1;i<=m;i++)
    {
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
    {
        for(auto ele:G[i])
        {
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    memset(vis,0,sizeof(vis));
    cnt=0;
    vis[1]=1;
    GetLocalTime(&sys);
    cout<<"time:"<<sys.wSecond<<":"<<sys.wMilliseconds<<endl;
    DFS(0,1);
    GetLocalTime(&sys);
    cout<<"time:"<<sys.wSecond<<":"<<sys.wMilliseconds<<endl;
    cout<<"path:"<<path<<endl;
    system("pause");
}
/*
1 2
2 3
3 4
4 20
20 1
1 11
2 9
3 7
4 5
20 19
11 10 11 12
9 10 9 8
7 8 7 6
5 6 5 18
19 18 19 12
10 14 12 13 17 18 16 6 8 15
14 13 13 17 17 16 16 15 15 14
*/