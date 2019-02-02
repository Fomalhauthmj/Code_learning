#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
#define N 105
int height,width;
char grid[N][N];
queue<pair<int,int>> Q;
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
bool vis[N][N];
bool legal(int r,int c)
{
    if(vis[r][c]) return false;
    if(r>height||r<=0) return false;
    if(c>width||c<=0) return false;
    return true;
}
void DFS(int sr,int sc)
{
    int nr,nc;
    for(int i=0;i<4;i++)
    {
        nr=sr+dir[i][0];
        nc=sc+dir[i][1];
        if(legal(nr,nc)&&grid[nr][nc]=='#')
        {
            vis[nr][nc]=1;
            DFS(nr,nc);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int t;cin>>t;
    while(t--)
    {
        cin>>height>>width;
        while(!Q.empty()) Q.pop();
        for(int i=1;i<=height;i++)
        {
            for(int j=1;j<=width;j++)   
            {
                cin>>grid[i][j];
                if(grid[i][j]=='#')
                {
                    Q.push(make_pair(i,j));
                }
            }
        }
        memset(vis,0,sizeof(vis));
        int ans=0;
        while(!Q.empty())
        {
            pair<int,int> now=Q.front();
            Q.pop();
            if(!vis[now.first][now.second])
            {
                ans++;
                DFS(now.first,now.second);
            }
        }
        cout<<ans<<endl;
    }
}