#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define pii pair<int, int>
const int N = 1E5 + 50;
vector<int> ori[N];
vector<int> rev[N];
int n, m, price[N], min_price[N], max_price[N];
bool vis[N];
//反向建图 正反两次最短路更新
void Dijkstra_on_ori()
{
    memset(min_price, 0x3f, sizeof(min_price));
    memset(vis, 0, sizeof(vis));
    priority_queue<pii, vector<pii>, greater<pii>> q;
    min_price[1] = price[1];
    q.push({min_price[1], 1});
    while (!q.empty())
    {
        int x = q.top().second;
        q.pop();
        if (vis[x])
            continue;
        vis[x] = 1;
        for (auto y : ori[x])
        {
            if (!vis[y] && min_price[y] > min(min_price[x], price[y]))
            {
                min_price[y] = min(min_price[x], price[y]);
                q.push({min_price[y], y});
            }
        }
    }
}
void Dijkstra_on_rev()
{
    memset(max_price, 0, sizeof(max_price));
    memset(vis, 0, sizeof(vis));
    priority_queue<pii> q;
    max_price[n] = price[n];
    q.push({max_price[n], n});
    while (!q.empty())
    {
        int x = q.top().second;
        q.pop();
        if (vis[x])
            continue;
        vis[x] = 1;
        for (auto y : rev[x])
        {
            if (!vis[y] && max_price[y] < max(max_price[x], price[y]))
            {
                max_price[y] = max(max_price[x], price[y]);
                q.push({max_price[y], y});
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> price[i];
    int x, y, z;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> z;
        if (z & 1)
            ori[x].push_back(y), rev[y].push_back(x);
        else
            ori[x].push_back(y), ori[y].push_back(x), rev[x].push_back(y), rev[y].push_back(x);
    }
    Dijkstra_on_ori();
    Dijkstra_on_rev();
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        //cout << min_price[i] << " " << max_price[i] << endl;
        ans = max(ans, max_price[i] - min_price[i]);
    }
    cout << ans << endl;
    system("pause");
    return 0;
}