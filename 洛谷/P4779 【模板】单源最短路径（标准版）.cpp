//https://www.luogu.org/problemnew/show/P4779
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define N 100100
#define ll long long
#define inf 2147483647
vector<pair<int, ll>> G[N];
struct edge
{
    int to;
    ll weight;
    edge(int i, ll w) : to(i), weight(w)
    {
    }
    bool operator<(const edge &e) const
    {
        return weight > e.weight;
    }
};
ll dis[N];
bool vis[N];
int n, m, s;
void Dijkstra(int start)
{
    for (int i = 1; i <= n; i++)
    {
        dis[i] = inf;
    }
    priority_queue<edge> q;
    q.push(edge(start, 0));
    dis[start] = 0;
    while (!q.empty())
    {
        edge now = q.top();
        q.pop();
        if (!vis[now.to])
        {
            vis[now.to] = 1;
            for (auto ele : G[now.to])
            {
                if (!vis[ele.first] && now.weight + ele.second < dis[ele.first])
                {
                    dis[ele.first] = now.weight + ele.second;
                    q.push(edge(ele.first, dis[ele.first]));
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> s;
    int u, v;
    ll w;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        G[u].push_back(make_pair(v, w));
    }
    Dijkstra(s);
    for (int i = 1; i <= n; i++)
    {
        cout << dis[i] << " ";
    }
    cout << endl;
    //system("pause");
    return 0;
}