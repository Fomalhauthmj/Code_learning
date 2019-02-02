#include<iostream>
#include<cstring>
#include<string>
using namespace std;
char grid[16][10];
bool vis[16][10];
int n;
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
void print()
{
    for(int i=0;i<16;i++)
    {
        for(int j=0;j<10;j++)
        {
            cout<<grid[i][j];
        }
        cout<<endl;
    }
}
bool legal(int r,int c)
{
    if(vis[r][c]!=0) return false;
    if(r<0||r>=16) return false;
    if(c<0||c>=10) return false;
    return true;
}
void change(int newcolor,int r,int c,int precolor)
{
    int nr,nc;
    int num=0;
    for(int i=0;i<4;i++)
    {
        nr=r+dir[i][0];
        nc=c+dir[i][1];
        if(precolor==grid[nr][nc]-'0'&&legal(nr,nc))
        {
            cout<<"nr:"<<nr<<" nc:"<<nc<<endl;
            grid[nr][nc]=newcolor+'0';
            vis[nr][nc]=1;
            change(newcolor,nr,nc,precolor);
        }
        else num++;
    }
    if(num==4) return;
}
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        memset(grid,0,sizeof(grid));
        for(int i=0;i<16;i++)
        {
            for(int j=0;j<10;j++)
            {
                cin>>grid[i][j];
            }
        }
        int color,r,c;
        while(n--)
        {
            cin>>color>>r>>c;
            memset(vis,0,sizeof(vis));
            vis[r-1][c-1]=1;
            int pre=grid[r-1][c-1]-'0';
            grid[r-1][c-1]=color+'0';
            change(color,r-1,c-1,pre);
            print();
        }
    }
}
//https://blog.csdn.net/helloworld10086/article/details/40659811