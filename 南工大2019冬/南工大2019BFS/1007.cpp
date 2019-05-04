//http://acm.hdu.edu.cn/showproblem.php?pid=1175
#include<iostream>
#include<queue>
#include<cstring>
#define N 1010
#define inf 0x3f3f3f3f
using namespace std;
int chess[N][N];
bool vis[N][N][4];
int n,m;
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
//BFS+优先队列 转折次数少的优先
bool legal(int r,int c,int dir)
{
    if(r<1||r>n) return false;
    if(c<1||c>m) return false;
    if(vis[r][c][dir]) return false;
    return true;
}
struct node
{
    int r;
    int c;
    int dir;
    int t;//次数
    bool operator<(const node &n) const
    {
        return t>n.t;//转折次数少的优先
    }
};
priority_queue<node> Q;
bool BFS(int sr,int sc,int er,int ec)
{
    while(!Q.empty()) Q.pop();
    memset(vis,0,sizeof(vis));
    for(int i=0;i<4;i++) vis[sr][sc][i]=1;
    node start;
    start.r=sr,start.c=sc;
    start.t=-1;//TODO:注意-1的初始化
    start.dir=-1;
    Q.push(start);
    int ans=inf;
    while(!Q.empty())
    {
        node now=Q.top();
        if(now.r==er&&now.c==ec)
        {
            ans=min(ans,now.t);
        }
        Q.pop();
        for(int i=0;i<4;i++)
        {
            node next=now;
            next.r+=dir[i][0];
            next.c+=dir[i][1];
            if(legal(next.r,next.c,i)&&(chess[next.r][next.c]==0||(next.r==er&&next.c==ec)))
            {
                if(now.dir!=i)
                {
                    next.t++;
                }
                next.dir=i;
                vis[next.r][next.c][i]=1;
                Q.push(next);
            }
        }
    }
    if(ans<=2) return true;
    else return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>n>>m)
    {
        if(n+m==0) break;
        for(int i=1;i<=n;i++)//n行
        {
            for(int j=1;j<=m;j++)//m列
            {
                cin>>chess[i][j];
            }
        }
        int q;
        cin>>q;
        int x1,y1,x2,y2;
        while(q--)
        {
            cin>>x1>>y1>>x2>>y2;
            if(chess[x1][y1]!=chess[x2][y2])
            {
                cout<<"NO"<<endl;
                continue;
            }
            if(!chess[x1][y1]||!chess[x2][y2])
            {
                cout<<"NO"<<endl;
                continue;
            }
            if(BFS(x1,y1,x2,y2)) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
}