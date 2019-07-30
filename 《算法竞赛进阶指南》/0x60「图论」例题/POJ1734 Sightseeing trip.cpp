#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
#define N 105
#define inf 0x3f3f3f3f
#define ll long long
ll a[N][N], d[N][N];
int n, m, path[N][N];
vector<int> p;
ll ans;
void get_path(int i, int j)
{
    if (!path[i][j])
        return;
    get_path(i, path[i][j]);
    p.push_back(path[i][j]);
    get_path(path[i][j], j);
}
void Floyd()
{
    memcpy(d, a, sizeof(d));
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i < k; i++)
        {
            for (int j = i + 1; j < k; j++)
            {
                //注意溢出
                ll temp = d[i][j] + a[i][k] + a[k][j];
                if (ans > temp)
                {
                    ans = temp;
                    p.clear();
                    p.push_back(i);
                    get_path(i, j);
                    p.push_back(j);
                    p.push_back(k);
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                ll temp = d[i][k] + d[k][j];
                if (d[i][j] > temp)
                {
                    d[i][j] = temp;
                    path[i][j] = k;
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    ll u, v, w;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            a[i][j] = a[j][i] = inf;
    for (int i = 1; i <= n; i++)
        a[i][i] = 0;
    for (int i = 0; i < m; i++)
        cin >> u >> v >> w, a[u][v] = a[v][u] = min(a[u][v], w);
    ans = inf;
    Floyd();
    if (ans != inf)
    {
        for (int i = 0; i < p.size();i++)
            cout << p[i] << " ";
        cout << endl;
    }
    else
        cout << "No solution." << endl;
    //system("pause");
    return 0;
}