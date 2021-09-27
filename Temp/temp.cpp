#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 50;
#define pii pair<int, int>
struct edge
{
    int v, s, m;
};
vector<edge> g[N];
int n, m, k, vis[N], stk[N], top = -1, q[N], in[N];
bool onCycle[N];
void DFS(int x)
{
    vis[x] = 1;
    stk[++top] = x;
    for (auto &e : g[x])
    {
        int y = e.v;
        if (!vis[y])
            DFS(y);
        else if (vis[y] == 1)
        {
            for (int i = top; i >= 0; i--)
            {
                onCycle[stk[i]] = 1;
                if (stk[i] == y)
                    break;
            }
        }
    }
    vis[x] = 2;
    top--;
}
bool CycleCheck()
{
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            DFS(i);
    }
    for (int i = 0; i < k; i++)
        if (onCycle[q[i]])
            return false;
    return true;
}
int dis[N], pre[N], mon[N];
void Dij(int x)
{
    memset(vis, 0, sizeof(vis));
    memset(dis, 0x3f, sizeof(dis));
    dis[x] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({dis[x], x});
    while (q.size())
    {
        int x = q.top().second;
        q.pop();
        if (vis[x])
            continue;
        vis[x] = 1;
        for (auto &e : g[x])
        {
            int y = e.v;
            if (dis[y] > dis[x] + e.s || (dis[y] == dis[x] + e.s && mon[y] < mon[x] + e.m))
            {
                dis[y] = dis[x] + e.s, mon[y] = mon[x] + e.m, pre[y] = x;
                q.push({dis[y], y});
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0, t1, t2, s, d; i < m; i++)
    {
        cin >> t1 >> t2 >> s >> d;
        g[t1].push_back({t2, s, d}), in[t2]++;
    }
    cin >> k;
    for (int i = 0; i < k; i++)
        cin >> q[i];
    if (CycleCheck())
        cout << "Okay." << endl;
    else
        cout << "Impossible." << endl;
    for (int i = 0; i < n; i++)
        if (!in[i])
            g[n].push_back({i, 0, 0});
    Dij(n);
    for (int i = 0; i < k; i++)
    {
        if (onCycle[q[i]])
            cout << "Error." << endl;
        else
        {
            if (dis[q[i]] == 0)
                cout << "You may take test " << q[i] << " directly." << endl;
            else
            {
                vector<int> path;
                int x = q[i];
                while (x != n)
                    path.push_back(x), x = pre[x];
                int cnt = path.size();
                reverse(path.begin(), path.end());
                for (int i = 0; i < cnt; i++)
                {
                    if (i)
                        cout << "->" << path[i];
                    else
                        cout << path[i];
                }
                cout << endl;
            }
        }
    }
    return 0;
}