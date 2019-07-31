#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define ll long long
#define pii pair<int, int>
const ll mod = (1 << 31) - 1;
const int N = 1010;
int dist[N], n, m;
vector<pii> v[N];
bool vis[N];
void Dijkstra()
{
    memset(dist, 0x3f, sizeof(dist));
    memset(vis, 0, sizeof(vis));
    priority_queue<pii, vector<pii>, greater<pii>> q;
    dist[1] = 0;
    q.push({dist[1], 1});
    while (!q.empty())
    {
        int x = q.top().second;
        q.pop();
        if (!vis[x])
        {
            vis[x] = 1;
            for (auto it : v[x])
            {
                int y = it.first;
                if (dist[y] > dist[x] + it.second)
                {
                    dist[y] = dist[x] + it.second;
                    q.push({dist[y], y});
                }
            }
        }
    }
}
ll Solve()
{
    vector<pii> ps;
    for (int i = 1; i <= n; i++)
        ps.push_back({dist[i], i});
    sort(ps.begin(), ps.end());
    memset(vis, 0, sizeof(vis));
    ll ans = 1;
    for (auto it1 : ps)
    {
        int cnt = 0;
        int cur = it1.second;
        for (auto it2 : v[cur])
        {
            int x = it2.first;
            if (vis[x] && dist[cur] == dist[x] + it2.second)
                cnt++;
        }
        vis[cur] = 1;
        if (cnt)
            ans = ans * cnt % mod;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    int x, y, l;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> l;
        v[x].push_back({y, l});
        v[y].push_back({x, l});
    }
    Dijkstra();
    cout << Solve() << endl;
    system("pause");
    return 0;
}