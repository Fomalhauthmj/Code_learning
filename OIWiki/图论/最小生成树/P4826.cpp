//https: //www.luogu.org/problemnew/show/P4826
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
#define ll long long
#define N 2050
ll n;
ll id[N];
int fa[N];
struct edge
{
    int u, v;
    ll w;
    bool operator<(const edge &e) const
    {
        return w > e.w;
    }
    edge(int uu, int vv, ll ww) : u(uu), v(vv), w(ww)
    {
    }
};
vector<edge> edges;
int Find(int x)
{
    if (fa[x] == -1)
        return x;
    return fa[x] = Find(fa[x]);
}
ll Kruskal()
{
    memset(fa, -1, sizeof(fa));
    sort(edges.begin(), edges.end());
    int len = edges.size();
    int fu, fv;
    ll ans = 0;
    int cnt = 0;
    for (int i = 0; i < len; i++)
    {
        fu = Find(edges[i].u);
        fv = Find(edges[i].v);
        if (fu != fv)
        {
            fa[fu] = fv;
            ans += edges[i].w;
            cnt++;
        }
        if (cnt == n - 1)
            break;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> id[i];
    }
    /*
    动态规划？   转移方程❓ 怒拿10分  猜错了💢
    memset(dp, 0, sizeof(dp));
    for (int r = 1; r < n; r++)
    {
        for (int i = 0; i + r < n; i++)
        {
            dp[i][i + r] = max(max(dp[i + 1][i + r], dp[i][i + r - 1]) + (id[i] ^ id[i + r]), dp[i + 1][i + r] + dp[i][i + r - 1] - dp[i + 1][i + r - 1]);
        }
    }
    cout << dp[0][n - 1] << endl;
    找最长链路？ 复杂度❌ 原来这个思路是对的，叫最大生成树🎈
     */
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            edges.push_back(edge(i, j, id[i] ^ id[j]));
        }
    }
    cout << Kruskal() << endl;
    //system("pause");
    return 0;
}