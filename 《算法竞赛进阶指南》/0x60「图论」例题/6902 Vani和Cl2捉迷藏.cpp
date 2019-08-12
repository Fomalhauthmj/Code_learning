#include<iostream>
#include<cstring>
using namespace std;
const int N=205;
bool a[N][N],vis[N];
int match[N];
int n,m;
bool DFS(int x)
{
    for(int i=1;i<=n;i++)
    {
        if(i!=x&&a[x][i]&&!vis[i])
        {
            vis[i]=1;
            if(!match[i]||DFS(match[i]))
            {
                match[i]=x;
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
    cin>>n>>m;
    for(int i=0,x,y;i<m;i++)
        cin>>x>>y,a[x][y]=1;
    for(int i=1;i<=n;i++)
        a[i][i]=1;
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                a[i][j]|=a[i][k]&a[k][j];
            }
        }
    }
    int ans=n;
    for(int i=1;i<=n;i++)
    {
        memset(vis,0,sizeof(vis));
        if(DFS(i)) ans--;
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
}