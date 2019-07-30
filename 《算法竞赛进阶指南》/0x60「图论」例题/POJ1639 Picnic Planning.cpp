#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
#define inf 0x3f3f3f3f
#define N 25
#define M 500
map<string, int> name;
struct edge
{
    int u, v, w;
    bool operator<(const edge &e) const
    {
        return w < e.w;
    }
};
int n, s, ptot = 0, a[N][N], ans, fa[N], d[N], ver[N];
vector<edge> e;
bool vis[N][N];
edge dp[N]; //dp[i]  1...i路径上的最大边
void Init()
{
    for (int i = 1; i <= ptot; i++)
        fa[i] = i;
}
int Find(int x)
{
    if (x == fa[x])
        return x;
    return fa[x] = Find(fa[x]);
}
void Kruskal()
{
    Init();
    sort(e.begin(), e.end());
    for (int i = 0; i < e.size(); i++)
    {
        int u = e[i].u, v = e[i].v;
        if (u != 1 && v != 1)
        {
            int fu = Find(u), fv = Find(v);
            if (fu != fv)
            {
                fa[fu] = fv;
                vis[u][v] = vis[v][u] = 1;
                ans += e[i].w;
            }
        }
    }
}
void DFS(int cur, int pre)
{
    for (int i = 2; i <= ptot; i++)
    {
        if (i != pre && vis[cur][i])
        {
            if (dp[i].w == -1)
            {
                if (dp[cur].w < a[cur][i])
                {
                    dp[i].u = cur;
                    dp[i].v = i;
                    dp[i].w = a[cur][i];
                }
                else
                    dp[i] = dp[cur];
            }
            DFS(i, cur);
        }
        \
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    string s1, s2;
    int len;
    name["Park"] = ++ptot;
    memset(a, 0x3f, sizeof(a));
    memset(d, 0x3f, sizeof(d));
    //Park：1
    for (int i = 0; i < n; i++)
    {
        cin >> s1 >> s2 >> len;
        if (!name[s1])
            name[s1] = ++ptot;
        if (!name[s2])
            name[s2] = ++ptot;
        int u = name[s1], v = name[s2];
        a[u][v] = a[v][u] = min(a[u][v], len); //无向图邻接矩阵
        e.push_back({u, v, len});
    }
    cin >> s; //度数限制
    ans = 0;
    Kruskal();
    for (int i = 2; i <= ptot; i++)
    {
        if (a[1][i] != inf)
        {
            int rt = Find(i);
            if (d[rt] > a[1][i])
                d[rt] = a[1][i], ver[rt] = i;
        }
    }
    for (int i = 2; i <= ptot; i++)
    {
        if (d[i] != inf)
        {
            s--;
            ans += d[i];
            vis[1][ver[i]] = vis[ver[i]][1] = 1;
        }
    }
    while (s-- > 0)
    {
        memset(dp, -1, sizeof(dp));
        dp[1].w = -inf;
        for (int i = 2; i <= ptot; i++)
        {
            if (vis[1][i])
                dp[i].w = -inf;
        }
        DFS(1, -1);
        int w = -inf;
        int v;
        for (int i = 2; i <= ptot; i++)
        {
            if (w < dp[i].w - a[1][i])
            {
                w = dp[i].w - a[1][i];
                v = i;
            }
        }
        if (w <= 0)
            break;
        ans -= w;
        vis[1][v] = vis[v][1] = 1;
        vis[dp[v].u][dp[v].v] = vis[dp[v].v][dp[v].u] = 0;
    }
    cout << "Total miles driven: " << ans << endl;
    system("pause");
    return 0;
}