//https: //www.luogu.org/problemnew/show/P2738
#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;
int n;
const int N = 205;
#define inf 0x3f3f3f3f
#define ll long long
struct node
{
    int p[9];
    node()
    {
        memset(p, 0, sizeof(p));
    }
    bool operator<(const node &n) const
    {
        for (int i = 0; i < 9; i++)
        {
            if (p[i] != n.p[i])
                return p[i] < n.p[i];
        }
        return false;
    }
    bool operator==(const node &n) const
    {
        for (int i = 0; i < 9; i++)
        {
            if (p[i] != n.p[i])
                return false;
        }
        return true;
    }
};
map<node, int> M;
ll dis[N][N];
ll G[N][N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j < N; j++)
        {
            G[i][j] = inf;
        }
    }
    cin >> n;
    int s, len, lnum, rnum;
    int cnt = 0;
    int u, v;
    for (int i = 0; i < n; i++)
    {
        node n1, n2;
        //要在这里新建变量
        cin >> s >> len >> lnum >> rnum;
        for (int i = 0; i < lnum; i++)
        {
            cin >> n1.p[i];
        }
        n1.p[8] = s;
        for (int i = 0; i < rnum; i++)
        {
            cin >> n2.p[i];
        }
        n2.p[8] = s;
        sort(n1.p, n1.p + 9);
        sort(n2.p, n2.p + 9);
        if (!M[n1])
            M[n1] = ++cnt;
        if (!M[n2])
            M[n2] = ++cnt;
        u = M[n1];
        v = M[n2];
        //cout << "cur:" << u << " " << v << endl;
        G[u][v] = G[v][u] = len;
    }
    for (int i = 1; i <= cnt; i++)
    {
        for (int j = 1; j <= cnt; j++)
        {
            dis[i][j] = G[i][j];
        }
    }
    ll ans = inf;
    for (int k = 1; k <= cnt; k++)
    {
        for (int i = 1; i < k; i++)
        {
            for (int j = i + 1; j < k; j++)
            {
                ans = min(ans, dis[i][j] + G[i][k] + G[k][j]);
            }
        }
        for (int i = 1; i <= cnt; i++)
        {
            for (int j = 1; j <= cnt; j++)
            {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    cout << ans << endl;
    //system("pause");
    return 0;
}