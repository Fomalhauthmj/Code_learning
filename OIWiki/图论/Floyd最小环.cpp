//给一个正权无向图，找一个最小权值和的环
//http://acm.hdu.edu.cn/showproblem.php?pid=1599
#include <cstring>
#include <iostream>
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f
const int N = 105;
ll G[N][N];
ll dis[N][N];
int n, m;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n >> m)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                G[i][j] = inf;
            }
        }
        ll u, v, c;
        for (int i = 0; i < m; i++)
        {
            cin >> u >> v >> c;
            G[u][v] = min(G[u][v], c);
            G[v][u] = G[u][v];
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dis[i][j] = G[i][j];
            }
        }
        ll ans = inf;
        for (int k = 1; k <= n; k++)
        {
            for (int i = 1; i < k; i++)
            {
                for (int j = i + 1; j < k; j++)
                {
                    ans = min(ans, dis[i][j] + G[i][k] + G[k][j]);
                    //求环
                }
            }
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
        if (ans < inf)
            cout << ans << endl;
        else
            cout << "It's impossible." << endl;
    }
    return 0;
}