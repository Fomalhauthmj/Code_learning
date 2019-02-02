#include<iostream>
#include<cstring>
#include<queue>
#include<set>
using namespace std;
#define N 1010
char sea[N][N];
int n;
bool vis[N][N];
int bels[N][N];
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
bool legal(int r,int c)
{
    if(r<0||r>=n) return false;
    if(c<0||c>=n) return false;
    if(vis[r][c]) return false;
    if(sea[r][c]=='.') return false;
    return true;
}
struct node
{
    int r;
    int c;
    int belong;
    node(int rr,int cc,int bb)
    {
        r=rr;c=cc;belong=bb;
    }
};
queue<node> Q;
void BFS(int sr,int sc,int belong)
{
    while(!Q.empty()) Q.pop();
    vis[sr][sc]=1;
    Q.push(node(sr,sc,belong));
    while(!Q.empty())
    {
        node now=Q.front();
        Q.pop();
        for(int i=0;i<4;i++)
        {
            node next=now;
            next.r+=dir[i][0];
            next.c+=dir[i][1];
            if(legal(next.r,next.c))
            {
                Q.push(next);
                bels[next.r][next.c]=now.belong;
                vis[next.r][next.c]=1;
            }
        }
    }
}
bool water(int r,int c)
{
    for(int i=0;i<4;i++)
    {
        int n_r=r+dir[i][0];
        int n_c=c+dir[i][1];
        if(n_r>=0&&n_r<n&&n_c>=0&&n_c<n&&sea[n_r][n_c]=='.') return true;
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>n)
    {
        queue<pair<int,int>> islands;
        memset(bels,0,sizeof(bels));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>sea[i][j];
                if(sea[i][j]=='#')
                {
                    
                    islands.push(make_pair(i,j));
                }
            }
        }
        int before_num=0;
        int belong=1;
        memset(vis,0,sizeof(vis));
        while(!islands.empty())
        {
            pair<int,int> now=islands.front();
            islands.pop();
            if(!vis[now.first][now.second]) 
            {
                before_num++;
                bels[now.first][now.second]=belong;
                BFS(now.first,now.second,belong++);
            }
        }//获得未淹没前的岛屿数量before_num;

        //模拟淹没
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(sea[i][j]=='#'&&water(i,j))
                {
                    sea[i][j]='x';
                }
            }
        }
        //获得淹没后的岛屿数量after_num=S.size();
        set<int> S;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(sea[i][j]=='#')
                {
                    S.insert(bels[i][j]);
                }
            }
        }
        //cout<<before_num<<endl; 未淹没前岛屿数量
        //cout<<S.size()<<endl;  淹没后岛屿数量 根据编号
        cout<<before_num-S.size()<<endl;
    }
}