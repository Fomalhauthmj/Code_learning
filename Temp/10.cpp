#include <algorithm>
#include <cstring>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
#define ll long long
struct circle
{
    int x, y, r;
    bool operator<(const circle &n) const
    {
        return r > n.r;
    }
};
vector<circle> cs;
double Dis(circle c1, circle c2)
{
    return sqrt((c1.x - c2.x) * (c1.x - c2.x) + (c1.y - c2.y) * (c1.y - c2.y));
}
bool Intersect(circle c1, circle c2)
{
    double dis = Dis(c1, c2);
    if (c1.r + c2.r <= dis)
        return false;
    return true;
}
bool vis[50];
ll ans = 0, temp = 0;
int n;
void DFS(int cur)
{
    if (cur >= n)
    {
        ans = max(ans, temp);
        return;
    }
    vis[cur] = 0;
    DFS(cur + 1);
    bool flag = true;
    for (int i = 0; i < cur; i++)
    {
        if (vis[i] && Intersect(cs[i], cs[cur]))
        {
            flag = false;
            break;
        }
    }
    if (flag)
    {
        vis[cur] = 1;
        temp += cs[cur].r * cs[cur].r;
        DFS(cur + 1);
        temp -= cs[cur].r * cs[cur].r;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    circle c;
    for (int i = 0; i < n; i++)
    {
        cin >> c.x >> c.y >> c.r;
        cs.push_back(c);
    }
    sort(cs.begin(), cs.end());
    memset(vis, 0, sizeof(vis));
    DFS(0);
    cout << ans << endl;
    system("pause");
    return 0;
}
/*
6
1 1 2
1 4 2
1 7 2
4 1 2
4 4 2
4 7 2

4
1 3 1
2 2 1
4 1 1
4 3 1
*/