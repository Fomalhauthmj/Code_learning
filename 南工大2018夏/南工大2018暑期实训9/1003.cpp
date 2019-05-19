//m and n, the number of rows and columns
//If m = 0 it signals the end of the input; otherwise 1 <= m <= 100 and 1 <= n <= 100
//* :缺乏  @：油 八个方向相邻属于同一个
/* !:并查集
#include<iostream>
using namespace std;
#define size 105
char map[size][size];
int m,n;
int num1;
int num2;
int parent[size*size];
void init()
{
    for(int i=0;i<m*n;i++)  parent[i]=i;
}
bool legal(int r,int c)
{
    if(r<0||r>=m) return false;
    if(c<0||c>=n) return false;
    return true;
}
int Find(int x)
{
    if(parent[x]==x) return x;
    parent[x]=Find(parent[x]);
    return parent[x];
}
void Union(int r1,int c1,int r2,int c2)
{
    if(!legal(r1,c1)) return;
    if(!legal(r2,c2)) return;
    int flag=0;
    if(map[r1][c1]=='@'&&map[r2][c2]=='@') flag=1;
    if(flag==1)
    {
        int p1=Find(r1*n+c1);  //注意是r1*n+c1  !:WA!!!
        int p2=Find(r2*n+c2);
        if(p1!=p2)
        {
            parent[p1]=p2;
            //cout<<"u1:"<<r1<<" "<<c1<<endl;
            //cout<<"u2:"<<r2<<" "<<c2<<endl;
            num2++;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>m>>n)
    {
        if(m==0) break;
        num1=0;
        num2=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>map[i][j];
                if(map[i][j]=='@') num1++;
            }
        }
        init();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                Union(i,j,i,j+1);//"right";
                Union(i,j,i+1,j);//"down";
                Union(i,j,i+1,j+1);//"right_down";
                Union(i,j,i-1,j);
                Union(i,j,i-1,j+1);
            }
        }
        cout<<num1-num2<<endl;
    }
}
*/


//!:DFS
#include<iostream>
#include<cstring>
using namespace std;
#define size 105
char map[size][size];
int m,n;
int ans;
int dir[8][2]={{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
bool vis[size][size];
bool legal(int r,int c)
{
    if(vis[r][c]) return false;
    if(r<0||r>=m) return false;
    if(c<0||c>=n) return false;
    return true;
}
void DFS(int sr,int sc)
{
    vis[sr][sc]=1;
    for(int k=0;k<8;k++)
    {
        int nr=sr+dir[k][0];
        int nc=sc+dir[k][1];
        if(legal(nr,nc)&&map[nr][nc]=='@')
        {
            DFS(nr,nc);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>m>>n)
    {
        if(m==0) break;
        ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>map[i][j];
            }
        }
        ans=0;
        memset(vis,0,sizeof(vis));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(map[i][j]=='@'&&!vis[i][j])
                {
                    ans++;
                    DFS(i,j);
                }
            }
        }
        cout<<ans<<endl;
    }
}