#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const long long MAXN=2e5+20;
struct Edge
{
    long long u, v, w;
    bool operator<(Edge e) const
    {
        return w > e.w;
    }
    Edge(long long uu, long long vv, long long ww) : u(uu), v(vv), w(ww)
    {
    }
};
long long fa[MAXN];
long long Find(long long x)
{
    if (fa[x] == -1)
        return x;
    else
        return fa[x] = Find(fa[x]);
}
priority_queue<Edge> q;
long long n; //点
long long m; //边
long long Kruskal()
{
    memset(fa,-1,sizeof(fa));
    long long cnt=0;
    long long ans=0;
    long long fu,fv;
    while(!q.empty())
    {
        Edge now=q.top();
        q.pop();
        fu=Find(now.u);
        fv=Find(now.v);
        if(fu!=fv)
        {
            //cout<<"add:"<<now.u<<" "<<now.v<<" "<<now.w<<endl;
            ans+=now.w;
            fa[fu]=fv;
            cnt++;
        }
        if(cnt==n-1) break;
    }
    if(cnt<n-1) return -1;
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    long long u, v, w;
    for (long long i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        q.push(Edge(u, v, w));
    }
    cout << Kruskal() << endl;
    system("pause");
    return 0;
}