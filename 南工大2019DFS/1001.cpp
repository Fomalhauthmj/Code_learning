#include<bits/stdc++.h>
using namespace std;
#define N 25
char room[N][N];
int width,height;
int start_r,start_c;
int ans;
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
bool vis[N][N];
bool legal(int r,int c)
{
    if(vis[r][c]) return false;
    if(r<=0||r>height) return false;
    if(c<=0||c>width)  return false;
    if(room[r][c]=='#') return false;
    return true;
}
void DFS(int sr,int sc)
{
    int nr,nc;
    for(int i=0;i<4;i++)
    {
        nr=sr+dir[i][0];
        nc=sc+dir[i][1];
        if(legal(nr,nc))
        {
            vis[nr][nc]=1;
            ans++;
            DFS(nr,nc);
        }
    }
}
void disp()
{
    for(int i=1;i<=height;i++)
    {
        for(int j=1;j<=width;j++)
        {
            cout<<vis[i][j];
        }
        cout<<endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>width>>height)
    {
        if(width+height==0) break;
        ans=0;
        for(int i=1;i<=height;i++)
        {
            for(int j=1;j<=width;j++)
            {
                cin>>room[i][j];//room[height][width]
                if(room[i][j]=='@')
                {
                    start_r=i;
                    start_c=j;
                }
            }
        }
        memset(vis,0,sizeof(vis));
        vis[start_r][start_c]=1;
        DFS(start_r,start_c);
        //disp();
        cout<<ans+1<<endl;
    }
}



/*
#include<bits/stdc++.h>
using namespace std;
#define N 25
char room[N][N];
int width,height;
int start_r,start_c;
int ans;
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
bool vis[N][N];
queue<pair<int,int>> Q;
bool legal(int r,int c)
{
    if(vis[r][c]) return false;
    if(r<=0||r>height) return false;
    if(c<=0||c>width)  return false;
    if(room[r][c]=='#') return false;
    return true;
}
void BFS(int sr,int sc)
{
    while(!Q.empty()) Q.pop();
    Q.push(make_pair(sr,sc));
    int nr,nc;
    while(!Q.empty())
    {
        pair<int,int> now=Q.front();
        Q.pop();
        for(int i=0;i<4;i++)
        {
            nr=now.first+dir[i][0];
            nc=now.second+dir[i][1];
            if(legal(nr,nc))
            {
                vis[nr][nc]=1;
                ans++;
                Q.push(make_pair(nr,nc));
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>width>>height)
    {
        if(width+height==0) break;
        ans=0;
        for(int i=1;i<=height;i++)
        {
            for(int j=1;j<=width;j++)
            {
                cin>>room[i][j];//room[height][width]
                if(room[i][j]=='@')
                {
                    start_r=i;
                    start_c=j;
                }
            }
        }
        memset(vis,0,sizeof(vis));
        vis[start_r][start_c]=1;
        BFS(start_r,start_c);
        //disp();
        cout<<ans+1<<endl;  
    }
}
*/
