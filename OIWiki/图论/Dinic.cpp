#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
#define inf 0x3f3f3f3f3f
#define N 1200
#define M 245000
#define ll long long
//反向边的存在 实际边数的两倍
struct Edge
{
    ll to;
    ll w;
    ll next;
};
Edge edge[M];
ll dep[N];
ll head[N];
ll cur[N]; //当前弧优化
ll cnt = 0;
ll n, m;
void Init()
{
    memset(head, -1, sizeof(head));
}
void add(ll u, ll v, ll w)
{
    edge[cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}
void Add(ll u, ll v, ll w)
{
    add(u, v, w);
    add(v, u, 0); //反向边
}
ll s, t;
bool BFS()
{
    queue<ll> q;
    memset(dep, -1, sizeof(dep));
    dep[s] = 0;
    q.push(s);
    while (!q.empty())
    {
        ll now = q.front();
        q.pop();
        for (ll i = head[now]; i != -1; i = edge[i].next)
        {
            if (edge[i].w > 0 && dep[edge[i].to] == -1)
            {
                dep[edge[i].to] = dep[now] + 1;
                q.push(edge[i].to);
            }
        }
    }
    if (dep[t] == -1)
        return false; //不存在分层图
    return true;
}
ll DFS(ll now, ll flow)
{
    if (now == t)
        return flow;
    ll used = 0;
    for (ll &i = cur[now]; i != -1; i = edge[i].next)
    {
        //&：当前弧优化
        if (dep[edge[i].to] == dep[now] + 1 && edge[i].w)
        {
            ll inc = DFS(edge[i].to, min(flow - used, edge[i].w));
            if (inc > 0)
            {
                edge[i].w -= inc;
                edge[i ^ 1].w += inc;
                used += inc;
                if (flow == used)
                    break;
            }
        }
    }
    if (!used)
        dep[now] = -1;
    return used;
}
ll Dinic()
{
    ll ans = 0;
    while (BFS())
    {
        for (ll i = 1; i <= n; i++)
        {
            cur[i] = head[i];
        }
        //每次建完分层图后 cur重置
        ans += DFS(s, inf);
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> s >> t;
    ll u, v, w;
    Init();
    for (ll i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        Add(u, v, w);
    }
    cout << Dinic() << endl;
    //system("pause");
    return 0;
}
/*
多路增广 √
当前弧优化 √
https://www.luogu.org/problemnew/show/P3376
 */