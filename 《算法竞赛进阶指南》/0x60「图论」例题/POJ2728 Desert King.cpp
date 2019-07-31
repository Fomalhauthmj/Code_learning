#include <cstring>
#include <iomanip>
#include <iostream>
#include <math.h>
using namespace std;
#define N 1010
#define pii pair<int, int>
#define eps 1e-6
#define inf 0x3f3f3f3f
int n;
int x[N], y[N], z[N];
double dis[N][N], cost[N][N], weight[N][N], d[N];
bool vis[N];
double distance(pii p1, pii p2)
{
    return sqrt((p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second));
}
bool Prim(double mid)
{
    //重新构图 求最小生成树
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            if (i == j)
                weight[i][j] = inf;
            else
                weight[i][j] = weight[j][i] = cost[i][j] - mid * dis[i][j];
        }
    }
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++)
        d[i] = inf;
    d[1] = 0;
    double ret = 0;
    int temp = n;
    while (temp--)
    {
        int min_pos = 0;
        for (int i = 1; i <= n; i++)
            if (!vis[i] && (!min_pos || d[i] < d[min_pos]))
                min_pos = i;
        if (min_pos)
        {
            vis[min_pos] = 1;
            ret += d[min_pos];
            for (int i = 1; i <= n; i++)
                d[i] = min(d[i], weight[min_pos][i]);
        }
    }
    if (ret < 0.0)
        return true;
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n && n)
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> x[i] >> y[i] >> z[i];
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                dis[i][j] = dis[j][i] = distance({x[i], y[i]}, {x[j], y[j]});
                cost[i][j] = cost[j][i] = fabs(z[i] - z[j]);
            }
        }
        double left = 0.0;
        double right = inf;
        double mid;
        while (left + eps <= right)
        {
            mid = (left + right) / 2;
            //cout << "cur:" << mid << endl;
            if (Prim(mid))
            {
                right = mid;
            }
            else
                left = mid;
        }
        cout << fixed << setprecision(3) << (left + right) / 2 << endl;
    }
    system("pause");
    return 0;
}