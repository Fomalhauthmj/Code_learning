#include<iostream>
#include<cstring>
#include<queue>
#include<set>
using namespace std;
#define N 105
#define inf 0x3f3f3f3f
int m,n;
int k,sx,sy,ex,ey;
char maze[N][N];
bool vis[N][N][4];
int each_min[N][N][4];
int dir[4][2]={{1,0},{0,-1},{0,1},{-1,0}};
bool legal(int r,int c,int dir)
{
    if(r==ey&&c==ex) return true;
    if(vis[r][c][dir]) return false;
    if(r<1||r>m) return false;
    if(c<1||c>n) return false;
    if(maze[r][c]=='*') return false;
    return true;
}
struct node{
    int r;
    int c;
    int t;
    int dir;
    //0 down  
    //1 left 
    //2 right 
    //3 up  
    //-1 init
    node(int rr,int cc,int tt,int dirr)
    {
        r=rr,c=cc,t=tt,dir=dirr;
    }
    /*
    friend bool operator<(node na,node nb)
    {
        return na.t>nb.t; 
    };
    */   
};
//priority_queue<node> Q;//根据拐弯数 优先队列? 回头可以因为方向不同
queue<node> Q;//优先队列 队列均可以
bool BFS(int sr,int sc)
{
    while(!Q.empty()) Q.pop();
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=0;k<4;k++)
            {
                each_min[i][j][k]=inf;
            }
        }
    }
    vis[sr][sc][0]=vis[sr][sc][1]=vis[sr][sc][2]=vis[sr][sc][3]=1;
    Q.push(node(sr,sc,0,-1));
    int ans=inf;
    while(!Q.empty())
    {
        node now=Q.front();
        Q.pop();
        if(now.r==ey&&now.c==ex) 
        {
            //cout<<"t:"<<now.t<<endl;
            ans=min(ans,now.t);
            continue;
        }
        int nr,nc;
        for(int i=0;i<4;i++)
        {
            nr=now.r+dir[i][0];
            nc=now.c+dir[i][1];
            if(legal(nr,nc,i))
            {
                vis[nr][nc][i]=1;
                //cout<<"cur t:"<<now.r<<" "<<now.c<<" "<<now.t<<" dir"<<now.dir<<endl;
                int temp=now.t;
                if(now.dir!=-1&&now.dir!=i) 
                {
                    if(now.dir+i!=3)    temp++;//TODO:注意这里不能对now.t修改 会影响后续路径
                }
                //cout<<"will add:"<<nr<<" "<<nc<<" "<<temp<<" dir"<<i<<endl;
                Q.push(node(nr,nc,temp,i));
            }
            if(vis[nr][nc][i])
            {
                int temp=now.t;
                if(now.dir!=-1&&now.dir!=i) 
                {
                    if(now.dir+i!=3)    temp++;//TODO:注意这里不能对now.t修改 会影响后续路径
                }
                //cout<<"will add:"<<nr<<" "<<nc<<" "<<temp<<" dir"<<i<<endl;
                if(temp<each_min[nr][nc][i])    
                {
                    each_min[nr][nc][i]=temp;
                    Q.push(node(nr,nc,temp,i));
                }
            }
        }
    }
    if(ans<=k) return true;
    else return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;cin>>t;
    while(t--)
    {
        cin>>m>>n;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cin>>maze[i][j];
            }
        }
        cin>>k>>sx>>sy>>ex>>ey;
        if(BFS(sy,sx)) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
}
/*
...**
.*..*
.**..
.***.
.....
0 1 1 5 5

5 5
.....
.*.*.
.....
.*.*.
.....
1 1 1 3 4/ 1 1 1 4 3
*/