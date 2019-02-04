#include<iostream>
#include<cstring>
using namespace std;
//通过DFS判定是否联通
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
bool matrix[3][4];
bool vis[3][4];
int ans;
bool legal(int r,int c)
{
    if(r<0||r>=3) return false;
    if(c<0||c>=4) return false;
    if(vis[r][c]) return false;
    if(!matrix[r][c]) return false;
    return true;
}
int temp_cnt;
void DFS(int r,int c)
{
    for(int i=0;i<4;i++)
    {
        int nr=r+dir[i][0];
        int nc=c+dir[i][1];
        if(legal(nr,nc))
        {
            temp_cnt++;
            vis[nr][nc]=1;
            DFS(nr,nc);
        }
    }
}
bool connect()
{
    bool temp_flag=false;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(matrix[i][j]==1)
            {
                memset(vis,0,sizeof(vis));
                vis[i][j]=1;
                temp_cnt=1;
                DFS(i,j);
                temp_flag=true;
                break;
            }
        }
        if(temp_flag) break;
    }
    if(temp_cnt==5) return true;
    else return false;
}
void select(int cur,int d)
{
    if(d>=5||cur>=12)
    {
        if(connect()&&d>=5) ans++;
        return;
    }
    int r=cur/4;
    int c=cur%4;
    matrix[r][c]=1;
    select(cur+1,d+1);//选
    matrix[r][c]=0;
    select(cur+1,d);//不选
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ans=0;
    select(0,0);
    cout<<ans<<endl;
    system("pause");
}