#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
#define size 25
char room[size][size];
bool vis[size][size];
int w,h;
int ans;
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
queue<pair<int,int>> Q;
// '.' - a black tile 
// '#' - a red tile 
// '@' - a man on a black tile(appears exactly once in a data set) 
bool legal(int r,int c)
{
    if(r<0||r>=h) return false;
    if(c<0||c>=w) return false;
    return true;
}
void BFS(int startr,int startc)
{
    while(!Q.empty()) Q.pop();
    Q.push(make_pair(startr,startc));
    vis[startr][startc]=1;
    while(!Q.empty())
    {
        pair<int,int> a=Q.front();
        Q.pop();
        for(int i=0;i<4;i++)
        {
            int nextr=a.first+dir[i][0];
            int nextc=a.second+dir[i][1];
            if(room[nextr][nextc]=='.'&&vis[nextr][nextc]==0&&legal(nextr,nextc))
            {
                Q.push(make_pair(nextr,nextc));
                vis[nextr][nextc]=1;
                ans++;
            }
        }
    }
}
void DFS(int startr,int startc)
{
    room[startr][startc]='#';
    ans++;
    for(int i=0;i<4;i++)
    {
        int nextr=startr+dir[i][0];
        int nextc=startc+dir[i][1];
        if(legal(nextr,nextc)&&room[nextr][nextc]=='.') 
        {
            DFS(nextr,nextc);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int startr,startc;
    while(cin>>w>>h)
    {
        if(w==0&&h==0) break;
        memset(vis,0,sizeof(vis));
        for(int i=0;i<h;i++)//h高度 行 y
        {
            for(int j=0;j<w;j++) //w宽度 列 x
            {
                cin>>room[i][j];
                if(room[i][j]=='@')
                {
                    startr=i;
                    startc=j;
                }
            }
        }
        //ans=1;
        //BFS(startr,startc);
        ans=0;
        DFS(startr,startc);
        cout<<ans<<endl;
    }
}
