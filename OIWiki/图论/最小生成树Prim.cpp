#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
#define inf 0x3f3f3f3f
const int N=2e5+20;
struct node
{
    long long v,w;
    node(int vv,int ww):v(vv),w(ww)
    {
    }
};
vector<node> G[N];
long long n,m;
bool vis[N];
long long lowcost[N];
long long Prim()
{
    long long ans=0;
    memset(vis,0,sizeof(vis));
    vis[1]=1;
    for(int i=1;i<=n;i++)
    {
        lowcost[i]=inf;
    }
    for(auto ele:G[1])
    {
        lowcost[ele.v]=ele.w;
    }
    int t=n-1;
    long long minc;
    long long pos;
    while(t--)
    {
        minc=inf;
        pos=-1;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i]&&minc>lowcost[i])
            {
                minc=lowcost[i];
                pos=i;
            }
        }
        if(minc==inf) return -1;
        ans+=minc;
        //cout<<"add:"<<minc<<" "<<pos<<endl;
        vis[pos]=1;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                for(auto ele:G[pos])
                {
                    if(ele.v==i&&lowcost[i]>ele.w)
                        lowcost[i]=ele.w;
                }
            }
        }
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    long long u,v,w;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v>>w;
        G[u].push_back(node(v,w));
        G[v].push_back(node(u,w));
    }
    cout<<Prim()<<endl;
    //system("pause");
    return 0;
}