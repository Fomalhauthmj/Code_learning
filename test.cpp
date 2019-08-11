#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
const int N=105;
int dir[8][2]={{1,2},{-1,2},{1,-2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
vector<int> v[N*N];
int match[N*N],n,m,t;
bool vis[N*N],invalid[N][N];
bool Judge(int x,int y)
{
    if(x<1||x>n||y<1||y>m||invalid[x][y]) return false;
    return true;
}
inline int Pos(int x,int y)
{
    return x*m+y;
}
bool DFS(int x)
{
    for(int i=0;i<v[x].size();i++)
    {
        int y=v[x][i];
        if(!vis[y])
        {
            vis[y]=true;
            if(!match[y]||DFS(match[y]))
            {
                match[y]=x;
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
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(!invalid[i][j])
            {
                for(int k=0;k<8;k++)
                {
                    int nx=i+dir[k][0];
                    int ny=j+dir[k][1];
                    if(Judge(nx,ny))
                        v[Pos(i,j)].push_back(Pos(nx,ny)),v[Pos(nx,ny)].push_back(Pos(i,j));
                }
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(!invalid[i][j]&&((i+j)&1))
            {
                memset(vis,0,sizeof(vis));
                if(DFS(Pos(i,j))) ans++;
            }
        }
    }
    cout<<ans<<endl;
    cout<<n*m-t-ans<<endl;
    system("pause");
    return 0;
}