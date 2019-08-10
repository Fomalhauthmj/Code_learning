#include<iostream>
#include<cstring>
#include<iomanip>
#include<math.h>
using namespace std;
#define pii pair<int,int>
#define eps 1e-7
#define inf 0x3f3f3f3f
const int N=55;
const int M=1e6+50;
pii enemy[N],tower[N];
double cost[N];
int n,m,t2,v;
double t1;
int head[N*N],ver[M],nxt[M],tot;
bool vis[N*N];
int match[N*N];
inline double distance(pii &p1,pii &p2)
{
    return sqrt((p1.first-p2.first)*(p1.first-p2.first)+(p1.second-p2.second)*(p1.second-p2.second));
}
void add(int u,int v)
{
    ver[++tot]=v,nxt[tot]=head[u],head[u]=tot;
}
bool DFS(int x)
{
    for(int i=head[x];i;i=nxt[i])
    {
        int y=ver[i];
        if(!vis[y])
        {
            vis[y]=1;
            if(!match[y]||DFS(match[y]))
            {
                match[y]=x;
                return true;
            }
        }
    }
    return false;
}
bool Judge(double mid)
{
    memset(head,0,sizeof(head));
    tot=0;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=m;k++)
            {
                double time_past=cost[k-1];
                double time_need=t1+distance(enemy[i],tower[j])/v;
                if(time_past+time_need<=mid)
                    add(i,j*m+k);
            }
        }
    }
    memset(match,0,sizeof(match));
    for(int i=1;i<=m;i++)
    {
        memset(vis,0,sizeof(vis));
        if(!DFS(i)) return false;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>t1>>t2>>v;
    t1/=60;
    for(int i=1;i<=m;i++)
        cin>>enemy[i].first>>enemy[i].second;
    for(int i=1;i<=n;i++)
        cin>>tower[i].first>>tower[i].second;
    for(int i=1;i<=m;i++) cost[i]=i*(t1+t2);
    double left=0;
    double right=inf;
    double mid;
    while(left+eps<right)
    {
        mid=(left+right)/2;
        //cout<<"cur:"<<mid<<endl;
        if(Judge(mid))
            right=mid;
        else left=mid;
    }
    cout<<fixed<<setprecision(6)<<(left+right)/2<<endl;
    system("pause");
    return 0;
}