#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <stdio.h>
#include <vector>
using namespace std;
const int N = 2e6 + 50;
struct point
{
    double x, y;
    bool operator<(const point &p) const
    {
        if (x != p.x)
            return x < p.x;
        return y < p.y;
    }
} pa[N], pb[N];
set<point> S1;
map<point, int> M;
vector<point> v;
inline point center(point &p1, point &p2)
{
    return {(p1.x + p2.x) / 2.0, (p1.y + p2.y) / 2};
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1, x, y; i <= n; i++)
        scanf("%d%d", &x, &y), pa[i].x = x, pa[i].y = y, S1.insert(pa[i]);
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
        {
            point t = center(pa[i], pa[j]);
            M[t]++;
        }
    int max_val = 0;
    for (auto it : M)
    {
        if (it.second > max_val)
        {
            max_val = it.second;
        }
    }
    for (auto it : M)
    {
        if (it.second == max_val)
        {
            v.push_back(it.first);
        }
    }
    int ans = 0x3f3f3f3f;
    for (auto c : v)
    {
        int temp = 0;
        set<point> S=S1;
        for (int i = 1; i <= n; i++)
        {
            point add;
            add.x = 2.0 * c.x - pa[i].x;
            add.y = 2.0 * c.y - pa[i].y;
            if (S.find(add) == S.end())
            {
                S.insert(add);
                temp++;
            }
        }
        ans = min(ans, temp);
    }
    printf("%d\n", ans);
    system("pause");
    return 0;
}