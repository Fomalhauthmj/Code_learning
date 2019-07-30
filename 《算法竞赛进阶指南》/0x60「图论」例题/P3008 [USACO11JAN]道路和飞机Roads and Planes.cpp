#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int N = 25010;
#define pii pair<int, int>
#define inf 0x3f3f3f3f
vector<pii> v[N];
int t, r, p, s, color[N], deg[N], dis[N], tot = 0;
bool vis[N];
void DFS(int x)
{
    color[x] = tot;
    for (auto it : v[x])
    {
        int y = it.first;
        if (!color[y])
            DFS(y);
    }
}
void Topo()
{
    queue<int> q;
    q.push(color[s]);
    for (int i = 1; i <= tot; i++)
    {
        if (!deg[i])
            q.push(i);
    }
    memset(dis, 0x7f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    dis[s] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        for (int i = 1; i <= t; i++)
        {
            if (color[i] == u)
                pq.push({dis[i], i});
        }
        while (!pq.empty())
        {
            int x = pq.top().second;
            pq.pop();
            if (!vis[x])
            {
                vis[x] = 1;
                for (auto it : v[x])
                {
                    int y = it.first;
                    if (dis[y] > dis[x] + it.second)
                    {
                        dis[y] = dis[x] + it.second;
                        if (color[x] == color[y])
                            pq.push({dis[y], y});
                    }
                    if (color[x] != color[y])
                    {
                        --deg[color[y]];
                        if (!deg[color[y]])
                            q.push(color[y]);
                    }
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t >> r >> p >> s;
    int a, b, c;
    for (int i = 0; i < r; i++)
    {
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    for (int i = 1; i <= t; i++)
    {
        if (!color[i])
        {
            ++tot;
            DFS(i);
        } //联通块划分
    }
    for (int i = 0; i < p; i++)
    {
        cin >> a >> b >> c;
        deg[color[b]]++;
        v[a].push_back({b, c}); //统计入度
    }
    Topo();
    for (int i = 1; i <= t; i++)
    {
        if (dis[i] < inf)
            cout << dis[i] << endl;
        else
            cout << "NO PATH" << endl;
    }
    //system("pause");
    return 0;
}