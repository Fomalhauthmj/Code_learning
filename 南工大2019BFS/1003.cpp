#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
#define N 25
char dungen[N][N];
int n,m,t;
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
bool vis[N][N][1025];
int sr,sc;
int ans;
struct node
{
    int r;
    int c;
    int t;
    int key;
    node(int rr,int cc,int tt,int keyy)
    {
        r=rr;c=cc;t=tt;key=keyy;
    }
};
queue<node> Q;
bool legal(int r,int c)
{
    if(r<0||r>=n) return false;
    if(c<0||c>=m) return false;
    if(dungen[r][c]=='*') return false;
    return true;
}
bool have_key(int key,char door)
{
    int len=9-(door-'A');
    for(int i=0;i<len;i++)
    {
        key>>=1;
    }
    if(key&1) return true;
    else return false;
}
bool no_key(int key,char new_key)
{
    int len=9-(new_key-'a');
    for(int i=0;i<len;i++)
    {
        key>>=1;
    }
    if(key&1) return false;
    return true;
}
int keys[10]={
    512,//1000000000,
    256,//0100000000,
    128,//0010000000,
    64,//0001000000,
    32,//0000100000,
    16,//0000010000,
    8,//0000001000,
    4,//0000000100,
    2,//0000000010,
    1//0000000001
};
bool BFS(int s_r,int s_c)
{
    while(!Q.empty()) Q.pop();
    Q.push(node(s_r,s_c,0,0));
    memset(vis,0,sizeof(vis));
    int key=0;
    vis[s_r][s_c][key]=1;
    while(!Q.empty())
    {
        node now=Q.front();
        Q.pop();
        if(dungen[now.r][now.c]=='^')
        {
            //cout<<now.t<<endl;
            if(now.t<t)
            {
                ans=now.t;
                return true;
            }
            else return false;
        }
        int n_r,n_c;
        for(int i=0;i<4;i++)
        {
            n_r=now.r+dir[i][0];
            n_c=now.c+dir[i][1];
            key=now.key;
            if(legal(n_r,n_c)&&!vis[n_r][n_c][key])
            {
                int temp=now.t+1;
                if(dungen[n_r][n_c]>='A'&&dungen[n_r][n_c]<='J'&&have_key(key,dungen[n_r][n_c]))//走到门
                {
                    //cout<<"A1 will add:"<<n_r<<" "<<n_c<<" time:"<<temp<<" key:"<<key<<endl;
                    Q.push(node(n_r,n_c,temp,key));//有钥匙可走
                }
                else if(dungen[n_r][n_c]>='a'&&dungen[n_r][n_c]<='j'&&no_key(key,dungen[n_r][n_c]))//获得钥匙
                {
                    //cout<<"get new key:"<<dungen[n_r][n_c]<<endl;
                    key=key^keys[dungen[n_r][n_c]-'a'];
                    //cout<<"A2 will add:"<<n_r<<" "<<n_c<<" time:"<<temp<<" key:"<<key<<endl;
                    Q.push(node(n_r,n_c,temp,key));
                }
                else if(dungen[n_r][n_c]>='a'&&dungen[n_r][n_c]<='j'&&!no_key(key,dungen[n_r][n_c]))//再次经过钥匙点
                {
                    //cout<<"A4 will add:"<<n_r<<" "<<n_c<<" time:"<<temp<<" key:"<<key<<endl;
                    Q.push(node(n_r,n_c,temp,key));
                }
                else if(dungen[n_r][n_c]=='.'||dungen[n_r][n_c]=='@'||dungen[n_r][n_c]=='^')//未到门
                {
                    //cout<<"A3 will add:"<<n_r<<" "<<n_c<<" time:"<<temp<<" key:"<<key<<endl;
                    Q.push(node(n_r,n_c,temp,key));
                }
                vis[n_r][n_c][key]=1;
            }
        }
    }
    return false;
}
//a-j 十把钥匙  对应A-J十个门
//abcdefghij
//1111111111 2^10=1024
/*
10 10 100
@....a....
....bB...c
*****A****
...e.C...d
D********* 
EfF......g
G*********
h...i....j 
H*********
...I..J..^
---------------------------------------------
ans=82
*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>n>>m>>t)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>dungen[i][j];
                if(dungen[i][j]=='@')
                {
                    sr=i;sc=j;
                }
            }
        }
        if(BFS(sr,sc)) cout<<ans<<endl;
        else cout<<-1<<endl;
    }
}