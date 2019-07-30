#include <algorithm>
#include <iostream>
using namespace std;
const int N = 6050;
#define inf 0x3f3f3f3f
int fa[N], sze[N], n, ans;
struct edge
{
    int x, y, z;
    bool operator<(const edge &e) const
    {
        return z < e.z;
    }
};
edge es[N];
void Init()
{
    for (int i = 1; i <= n; i++)
        fa[i] = i, sze[i] = 1;
}
int Find(int x)
{
    if (fa[x] == x)
        return x;
    return fa[x] = Find(fa[x]);
}
void Kruskal()
{
    for (int i = 0; i < n - 1; i++)
    {
        int x = Find(es[i].x);
        int y = Find(es[i].y);
        if (x != y)
        {
            fa[x] = y;
            ans += (es[i].z + 1) * (sze[x] * sze[y]-1);
            sze[y] += sze[x];
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        Init();
        for (int i = 0; i < n - 1; i++)
            cin >> es[i].x >> es[i].y >> es[i].z;
        sort(es, es + n - 1);
        ans = 0;
        Kruskal();
        cout << ans << endl;
    }
    system("pause");
    return 0;
}