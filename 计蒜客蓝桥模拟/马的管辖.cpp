#include<iostream>
#include<cstring>
#include<set>
using namespace std;
//两部分
//先求出5x5最少管辖马的数量13 然后确定方案数1
int board[5][5];//0空   1马   2被管辖
int dir1[4][2][2]={{{1,2},{-1,2}},{{1,-2},{-1,-2}},{{2,1},{2,-1}},{{-2,-1},{-2,1}}};
int dir2[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int horse;
int temp_horse;
bool legal(int r,int c)
{
    if(r<0||r>=5) return false;
    if(c<0||c>=5) return false;
    return true;
}
bool control()
{
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(board[i][j]==0) return false;
        }
    }
    return true;
}
int kinds;
void DFS(int depth)
{
    if(control()||depth>=25)
    {
        if(control()&&temp_horse==13) kinds++;
        return;
    }
    int cr=depth/5;
    int cc=depth%5;
    if(board[cr][cc]==0)//空位放马
    {
        set<pair<int,int>> S;
        board[cr][cc]=1;
        temp_horse++;
        for(int i=0;i<4;i++)
        {
            int nr=cr+dir2[i][0];
            int nc=cc+dir2[i][1];
            if(!legal(nr,nc)) continue;
            if(board[nr][nc]!=1)
            {
               for(int j=0;j<2;j++)
               {
                   int xr=cr+dir1[i][j][0];
                   int xc=cc+dir1[i][j][1];
                   if(legal(xr,xc)) 
                   {
                       S.insert(make_pair(xr,xc));
                       board[xr][xc]=2;
                   }
               }
            }
        }
        DFS(depth+1);
        board[cr][cc]=0;
        for(auto ele:S)
        {
            board[ele.first][ele.second]=0;
        }
        temp_horse--;
    }
    DFS(depth+1);//不放马
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    temp_horse=0;
    //horse=30;
    kinds=0;
    DFS(0);
    //cout<<horse<<endl;
    cout<<kinds<<endl;
    system("pause");
}