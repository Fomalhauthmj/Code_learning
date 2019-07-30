#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <vector>
using namespace std;
#define N 1010
#define pii pair<int, int>
#define ll long long
#define eps 1e-6
#define inf 0x3f3f3f3f
int n, tot;
map<pii, int> M;
pii ps[N];
int height[N];
double dis(pii p1, pii p2)
{
    return sqrt((p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second));
}
struct edge
{
    int u, v, h;
    double d, w;
    edge(int uu, int vv) : u(uu), v(vv)
    {
        d = dis(ps[uu], ps[vv]);
        h = abs(height[uu] - height[vv]);
    }
    bool operator<(const edge &e) const
    {
        return w < e.w;
    }
};
vector<edge> e;
int fa[N];
void Init()
{
    for (int i = 0; i < N; i++)
        fa[i] = i;
}
int Find(int x)
{
    if (x == fa[x])
        return x;
    else
        return fa[x] = Find(fa[x]);
}
bool Kruskal(double mid)
{
    //重新构图 求最小生成树
    for (int i = 0; i < e.size(); i++)
        e[i].w = e[i].d - mid * e[i].h;
    Init();
    sort(e.begin(), e.end());
    double ret = 0.0;
    for (int i = 0; i < e.size(); i++)
    {
        //cout << e[i].u << " " << e[i].v << " " << e[i].w << endl;
        int fu = Find(e[i].u);
        int fv = Find(e[i].v);
        if (fu != fv)
        {
            fa[fu] = fv;
            ret += e[i].w;
        }
    }
    cout << "ret:" << ret << endl;
    return ret < 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n && n)
    {
        M.clear();
        tot = 0;
        int x, y, z;
        for (int i = 0; i < n; i++)
        {
            cin >> x >> y >> z;
            if (!M[{x, y}])
                M[{x, y}] = ++tot;
            ps[M[{x, y}]] = {x, y};
            height[M[{x, y}]] = z;
        }
        for (int i = 1; i <= tot; i++)
        {
            for (int j = 1; j <= tot; j++)
            {
                if (i != j)
                    e.push_back(edge(i, j));
            }
        }
        double left = 0.0;
        double right = inf;
        double mid;
        while (right - left > eps)
        {
            mid = (left + right) / 2;
            cout << "cur:" << mid << endl;
            if (Kruskal(mid))
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