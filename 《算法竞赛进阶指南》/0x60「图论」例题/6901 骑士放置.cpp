#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
const int N=105;
int dir[8][2]={{1,2},{-1,2},{1,-2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
int match_x[N][N],match_y[N][N],n,m,t;
bool vis[N][N],invalid[N][N];
bool Judge(int x,int y)
{
    if(x<1||x>n||y<1||y>m||invalid[x][y]||vis[x][y]) return false;
    return true;
}
bool DFS(int x,int y)
{
    for(int i=0;i<8;i++)
    {
        int nx=x+dir[i][0],ny=y+dir[i][1];
        if(Judge(nx,ny))
        {
            vis[nx][ny]=true;
            if(!match_x[nx][ny]||DFS(match_x[nx][ny],match_y[nx][ny]))
            {
                match_x[nx][ny]=x;
                match_y[nx][ny]=y;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>t;
    int x,y;
    for(int i=0;i<t;i++)
    {
        cin>>x>>y;
        invalid[x][y]=1;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(!invalid[i][j]&&((i+j)&1))
            {
                memset(vis,0,sizeof(vis));
                if(DFS(i,j)) ans++;
            }
        }
    }
    cout<<n*m-t-ans<<endl;
    system("pause");
    return 0;
}