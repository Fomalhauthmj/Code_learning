#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
char grid[2][11][11];
bool vis[2][11][11];
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int n,m,t;
struct node
{
    int k,r,c;
    int t;
    node(int kk=0,int rr=0,int cc=0,int tt=0)
    {
        k=kk,r=rr,c=cc,t=tt;
    }
};
node p;
queue<node> Q;
bool legal(int k,int r,int c)
{
    if(vis[k][r][c]) return false;
    if(r<0||r>=n) return false;
    if(c<0||c>=m) return false;
    if(grid[k][r][c]=='*') return false;
    return true;
}
bool BFS()
{
    while(!Q.empty()) Q.pop();
    memset(vis,0,sizeof(vis));
    vis[0][0][0]=1;
    Q.push(node(0,0,0,0));
    while(!Q.empty())
    {
        node now=Q.front();
        Q.pop();
        //cout<<"cur:"<<now.k<<" "<<now.r<<" "<<now.c<<" "<<now.t<<endl;
        for(int i=0;i<4;i++)
        {
            int nr=now.r+dir[i][0];
            int nc=now.c+dir[i][1];
            if(now.k==p.k&&now.r==p.r&&now.c==p.c&&now.t<=t)//TODO:t时刻内
            {
                return true;
            }
            if(legal(now.k,nr,nc))
            {
                vis[now.k][nr][nc]=1;
                if(grid[now.k][nr][nc]=='.'||grid[now.k][nr][nc]=='P')//TODO:注意这里的P
                {
                    //cout<<"next:"<<now.k<<" "<<nr<<" "<<nc<<" "<<now.t+1<<endl;
                    Q.push(node(now.k,nr,nc,now.t+1));
                }
                else if(grid[now.k][nr][nc]=='#'&&grid[1-now.k][nr][nc]!='*'&&grid[1-now.k][nr][nc]!='#')//TODO:注意排除##
                {
                    vis[1-now.k][nr][nc]=1;
                    //cout<<"next:"<<1-now.k<<" "<<nr<<" "<<nc<<" "<<now.t+1<<endl;
                    Q.push(node(1-now.k,nr,nc,now.t+1));
                }
            }
        }
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c;cin>>c;
    while(c--)
    {
        cin>>n>>m>>t;
        for(int k=0;k<2;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    cin>>grid[k][i][j];
                    if(grid[k][i][j]=='P')
                    {
                        p.k=k;
                        p.r=i;
                        p.c=j;
                    }
                }
            }        
        }
        //cout<<p.k<<" "<<p.r<<" "<<p.c<<endl;
        if(BFS()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}