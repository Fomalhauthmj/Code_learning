#include<iostream>
using namespace std;
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int grd[4][5]=
{
{1,2,3,4,5},
{2,3,4,5,6},
{3,4,5,6,7},
{4,5,6,7,8}
};
int ans;
void DFS(int r,int c,int cur)
{
    if(cur==8)
    {
        ans++;
        return;
    }
    for(int i=0;i<4;i++)
    {
        int nr=r+dir[i][0];
        int nc=c+dir[i][1];
        if(nr>=0&&nr<4&&nc>=0&&nc<5)//legal
        {
            if(grd[nr][nc]==cur+1)
            {
                DFS(nr,nc,cur+1);
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ans=0;
    DFS(0,0,1);
    cout<<ans<<endl;
    system("pause");
    //ans=35
}