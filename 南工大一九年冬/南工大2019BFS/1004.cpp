#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
#define N 25
int m,n;
bool vis[N][N][2];
char room[N][N];
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}}; 
//0 1 down up 2 3 right left
struct node
{
    int r;
    int c;
    int t;
    node(int rr,int cc, int tt)
    {
        r=rr,c=cc,t=tt;
    }
    friend bool operator<(node n1,node n2)
    {
        return n1.t>n2.t;
    }
};
priority_queue<node> Q;
bool legal(int r,int c)
{
    if(r<0||r>=m) return false;
    if(c<0||c>=n) return false;
    if(room[r][c]=='*') return false;
    return true;
}
void BFS(int s_r,int s_c)
{
    while(!Q.empty()) Q.pop();
    memset(vis,0,sizeof(vis));
    Q.push(node(s_r,s_c,0));
    vis[s_r][s_c][0]=1;
    int n_r,n_c;
    while(!Q.empty())
    {
        node now=Q.top();
        Q.pop();
        if(room[now.r][now.c]=='T')
        {
            cout<<now.t<<endl;
            break;
        }
        for(int i=0;i<4;i++)
        {
            n_r=now.r+dir[i][0];
            n_c=now.c+dir[i][1];
            if(!legal(n_r,n_c)) continue;
            int temp=now.t;
            //0 1 down up     2 3 right left
            if(room[n_r][n_c]=='-')
            {
                if((i==0||i==1)&&temp%2==1)//|
                {
                    if(i==0) n_r++;
                    else n_r--;
                    //cout<<"A |"<<endl;
                }
                else if((i==2||i==3)&&temp%2==0)//-
                {
                    if(i==2) n_c++;
                    else n_c--;
                    //cout<<"A -"<<endl;
                }
                else 
                {
                    n_r=now.r;//停留
                    n_c=now.c;
                }
            }
            else if(room[n_r][n_c]=='|')
            {
                if((i==0||i==1)&&temp%2==0)//|
                {
                    if(i==0) n_r++;
                    else  n_r--;
                    //cout<<"B |"<<endl;
                }
                else if((i==2||i==3)&&temp%2==1)//-
                {
                    //cout<<n_r<<" "<<n_c<<endl;
                    if(i==2) n_c++;
                    else n_c--;
                    //cout<<"B -"<<endl;
                }
                else 
                {
                    n_r=now.r;
                    n_c=now.c;
                }
            }
            //cout<<"cur:"<<now.r<<" "<<now.c<<" time:"<<now.t<<endl;
            //cout<<"will add:"<<n_r<<" "<<n_c<<" time:"<<temp<<endl;
            if(!vis[n_r][n_c][(temp+1)%2])  
            {
                Q.push(node(n_r,n_c,temp+1));
                vis[n_r][n_c][(temp+1)%2]=1;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int s_r,s_c;
    while(cin>>m>>n)
    {
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>room[i][j];
                if(room[i][j]=='S')
                {
                    s_r=i;
                    s_c=j;
                }
            }
        }
        BFS(s_r,s_c);
    }
}