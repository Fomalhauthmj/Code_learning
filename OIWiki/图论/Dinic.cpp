#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
#define inf 0x3f3f3f3f
#define N 10100
#define M 201000
//反向边的存在 实际边数的两倍
struct Edge
{
    int to;
    int w;
    int next;
};
Edge edge[M];
int dep[N];
int head[N];
int cur[N]; //当前弧优化
int cnt = 0;
int n, m;
void Init()
{
    memset(head, -1, sizeof(head));
}
void add(int u, int v, int w)
{
    edge[cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}
void Add(int u, int v, int w)
{
    add(u, v, w);
    add(v, u, 0); //反向边
}
int s, t;
bool BFS()
{
    queue<int> q;
    memset(dep, -1, sizeof(dep));
    dep[s] = 0;
    q.push(s);
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        for (int i = head[now]; i != -1; i = edge[i].next)
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
int DFS(int now, int flow)
{
    if (now == t)
        return flow;
    int used = 0;
    for (int &i = cur[now]; i != -1; i = edge[i].next)
    {
        //&：当前弧优化
        if (dep[edge[i].to] == dep[now] + 1 && edge[i].w)
        {
            int inc = DFS(edge[i].to, min(flow - used, edge[i].w));
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
    return used;
}
int Dinic()
{
    int ans = 0;
    while (BFS())
    {
        for (int i = 1; i <= n; i++)
        {
            cur[i] = head[i];
        }
        while (int inc = DFS(s, inf))
        {
            ans += inc;
        }
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> s >> t;
    int u, v, w;
    Init();
    for (int i = 0; i < m; i++)
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