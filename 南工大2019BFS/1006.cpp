#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
#define N 10
#define inf 0x3f3f3f3f
int m,n;
int room[N][N];
int vis[N][N][N][N];//到达人的位置+箱子的位置所需的最佳步数?已访问?
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
//0down  1up   2right 3left
//http://acm.hdu.edu.cn/showproblem.php?pid=1254
int s_pr,s_pc;
int s_br,s_bc;
struct node
{
    int pr;
    int pc;
    int br;//箱子的位置
    int bc;
    int m;//箱子移动数
    node(int npr,int npc,int nbr,int nbc,int mm)
    {
        pr=npr;
        pc=npc;
        br=nbr;
        bc=nbc;
        m=mm;
    }
    void print()
    {
        cout<<"cur p:"<<pr<<" "<<pc<<endl;
        cout<<"cur b:"<<br<<" "<<bc<<endl;
        cout<<"cur m:"<<m<<endl;
    }
};
bool legal_p(node nd)
{
    if(nd.pr<0||nd.pr>=m) return false;
    if(nd.pc<0||nd.pc>=n) return false;
    if(vis[nd.pr][nd.pc][nd.br][nd.bc]<=nd.m) return false;//更优解为什么是<=的筛选条件
    //若不筛选=可能出现箱子不动 人一直BFS的情况 MLE内存不够
    if(room[nd.pr][nd.pc]==1) return false;//遇到墙
    return true;
}
bool legal_b(node nd)
{
    if(nd.br<0||nd.br>=m) return false;
    if(nd.bc<0||nd.bc>=n) return false;
    if(vis[nd.pr][nd.pc][nd.br][nd.bc]<=nd.m) return false;//更优解
    if(room[nd.br][nd.bc]==1) return false;//遇到墙
    return true;
}
queue<node> Q;
int ans;
void BFS()
{
    while(!Q.empty()) Q.pop();
    Q.push(node(s_pr,s_pc,s_br,s_bc,0));
    //初始化
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            for(int s=0;s<N;s++)
            {
                for(int t=0;t<N;t++)
                {
                    vis[i][j][s][t]=inf;
                }
            }
        }
    }
    vis[s_pr][s_pc][s_br][s_bc]=0;
    while(!Q.empty())
    {
        node now=Q.front();
        Q.pop();
        if(room[now.br][now.bc]==3)
        {
            ans=min(ans,now.m);
        }
        for(int i=0;i<4;i++)
        {
            node next=now;
            next.pr+=dir[i][0];
            next.pc+=dir[i][1];
            if(legal_p(next))
            {
                if(next.pr==next.br&&next.pc==next.bc)//人与箱子位置重合
                {
                    next.br+=dir[i][0];
                    next.bc+=dir[i][1];
                    next.m++;
                    if(legal_b(next))//箱子可前进
                    {
                        vis[next.pr][next.pc][next.br][next.bc]=next.m;
                        //cout<<"B will add:";
                        //next.print();
                        Q.push(next);
                    }
                }
                else
                {
                    vis[next.pr][next.pc][next.br][next.bc]=next.m;
                    //cout<<"A will add:";
                    //next.print();
                    Q.push(next);
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;cin>>t;
    while(t--)
    {
        cin>>m>>n;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>room[i][j];
                if(room[i][j]==4)
                {
                    s_pr=i;
                    s_pc=j;
                }
                else if(room[i][j]==2)
                {
                    s_br=i;
                    s_bc=j;
                }
            }
        }
        ans=inf;
        BFS();
        if(ans!=inf) cout<<ans<<endl;//有可行解
        else cout<<-1<<endl;
    }
}
//https://www.cnblogs.com/chenchengxun/p/4107955.html