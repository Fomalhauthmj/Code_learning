#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
#define inf 0x3f3f3f3f
bool vis[101][101];//二维记录三维状态 压缩空间
struct node
{
    int s,a,b;
    int t;
    node(int ss,int aa,int bb,int tt)
    {
        s=ss;a=aa;b=bb;t=tt;
    }
};
queue<node> Q;
int ans;
int s,a,b;
//s-a s-b  a-s a-b  b-s b-a 六种倒法  a杯容积大于b杯
void BFS()
{
    while(!Q.empty()) Q.pop();
    Q.push(node(s,0,0,0));
    vis[s][0]=1;
    while(!Q.empty())
    {
        node now=Q.front();
        Q.pop();
        if(now.s==s/2&&now.a==s/2&&now.b==0)
        {
            ans=now.t;
            break;
        }
        if(now.s>0&&now.a<a)//s-a
        {
            if(now.s>=a-now.a&&!vis[now.s+now.a-a][a])
            {
                vis[now.s+now.a-a][a]=1;
                Q.push(node(now.s+now.a-a,a,now.b,now.t+1));
            }
            //vis[0][now.a+now.s][now.b]=1;//不存在
        }
        if(now.s>0&&now.b<b)//s-b
        {
            if(now.s>=b-now.b&&!vis[now.s+now.b-b][now.a])
            {
                vis[now.s+now.b-b][now.a]=1;
                Q.push(node(now.s+now.b-b,now.a,b,now.t+1));
            }
            //vis[0][now.a][now.b+now.s]=1;//不存在
        }
        if(now.a>0&&now.s<s)//a-s
        {
            if(now.a<=s-now.s&&!vis[now.s+now.a][0])
            {
                vis[now.s+now.a][0]=1;
                Q.push(node(now.s+now.a,0,now.b,now.t+1));
            }
        }
        if(now.a>0&&now.b<b)//a-b
        {
            if(now.a>=b-now.b&&!vis[now.s][now.a+now.b-b])
            {
                vis[now.s][now.a+now.b-b]=1;
                Q.push(node(now.s,now.a+now.b-b,b,now.t+1));
            }
            else if(now.a<b-now.b&&!vis[now.s][0])
            {
                vis[now.s][0]=1;
                Q.push(node(now.s,0,now.b+now.a,now.t+1));
            }
        }
        if(now.b>0&&now.s<s)//b-s
        {
            if(now.b<=s-now.s&&!vis[now.s+now.b][now.a])
            {
                vis[now.s+now.b][now.a]=1;
                Q.push(node(now.s+now.b,now.a,0,now.t+1));
            }
        }
        if(now.b>0&&now.a<a)//b-a
        {
            if(now.b>=a-now.a&&!vis[now.s][a])
            {
                vis[now.s][a]=1;
                Q.push(node(now.s,a,now.b+now.a-a,now.t+1));
            }
            else if(now.b<a-now.a&&!vis[now.s][now.a+now.b])
            {
                vis[now.s][now.a+now.b]=1;
                Q.push(node(now.s,now.a+now.b,0,now.t+1));
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    while(cin>>s>>n>>m)
    {
        if(s+n+m==0) break;
        if(s%2==1) 
        {
            cout<<"NO"<<endl;//s为奇数 显然不能等分
            continue;
        }
        //无刻度 只能整杯倒
        a=max(n,m);b=min(n,m);
        memset(vis,0,sizeof(vis));
        ans=inf;
        BFS();
        if(vis[s/2][s/2]) cout<<ans<<endl;
        else cout<<"NO"<<endl;
    }
}