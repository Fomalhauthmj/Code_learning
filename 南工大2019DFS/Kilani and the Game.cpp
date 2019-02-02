#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
#define N 1010
int grid[N][N];
int n,m,p;
int total_space;
struct node
{
    int r,c;
    int t;
    node(int rr,int cc,int tt)
    {
        r=rr,c=cc,t=tt;
    }
};
queue<pair<int,int>> Q[10];
queue<node> temp;
long long s[10];
int ans[10];
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
bool legal(int r,int c)
{
    if(r>n||r<1) return false;
    if(c>m||c<1) return false;
    if(grid[r][c]!='.') return false;
    return true;
}
void BFS(pair<int,int> start,int p)
{
    while(!temp.empty()) temp.pop();
    temp.push(node(start.first,start.second,0));
    int nr,nc;
    while(!temp.empty())
    {
        node now=temp.front();
        temp.pop();
        if(total_space<=0) break;
        for(int i=0;i<4;i++)
        {
            nr=now.r+dir[i][0];
            nc=now.c+dir[i][1];
            if(legal(nr,nc)&&now.t+1<s[i])
            {   
                ans[p]++;
                grid[nr][nc]=p;
                total_space--;
                temp.push(node(nr,nc,now.t+1));
            }
            else if(legal(nr,nc)&&now.t+1==s[i])
            {
                ans[p]++;
                grid[nr][nc]=p;
                total_space--;
                Q[p].push(make_pair(nr,nc));
            }
        }
    }
}
void disp()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>n>>m>>p)
    {
        for(int i=1;i<=p;i++) 
        {
            cin>>s[i];
            while(!Q[i].empty()) Q[i].pop();
        }
        memset(ans,0,sizeof(ans));
        char ch;
        total_space=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>ch;
                if(ch=='#') grid[i][j]=-1;
                else if(ch=='.') grid[i][j]=0,total_space++;
                else 
                {
                    grid[i][j]=ch-'0';
                    Q[grid[i][j]].push(make_pair(i,j));
                    ans[grid[i][j]]++;
                }
            }
        }
        //模拟BFS
        while(total_space>0)
        {
            for(int i=1;i<=p;i++)
            {
                while(!Q[i].empty())
                {
                    pair<int,int> now=Q[i].front();
                    Q[i].pop();
                    if(total_space>0)  BFS(now,i);
                    else break;
                }
                if(total_space<=0) break;
            }
        }
        for(int i=1;i<=p;i++)
        {
            if(i!=p)    cout<<ans[i]<<" ";
            else cout<<ans[i]<<endl;
        }
        disp();
    }
}