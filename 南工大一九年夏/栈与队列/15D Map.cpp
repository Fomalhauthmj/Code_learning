//http://codeforces.com/contest/15/problem/D
//TODO 2500
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f
const int N = 1010;
int n, m, a, b;
int map[N][N];
bool vis[N][N];
ll sum[N][N];
ll ret[N * N][3];
int tot = 0;
ll Count(int x, int y, int min_x, int min_y)
{
    return sum[x + a - 1][y + b - 1] - sum[x + a - 1][y - 1] - sum[x - 1][y + b - 1] + sum[x - 1][y - 1] - a * b * map[min_x][min_y];
}
struct node
{
    int x, y;
    int min_x, min_y;
    ll count;
    node(int i1, int i2, int i3, int i4) : x(i1), y(i2), min_x(i3), min_y(i4)
    {
        count = Count(x, y, min_x, min_y);
    }
    bool operator<(const node &n) const
    {
        if (count == n.count)
            if (x == n.x)
                return y > n.y;
            else
                return x > n.x;
        return count > n.count;
    }
};
pair<int, int> Find(int x, int y)
{
    int temp = inf;
    pair<int, int> ret;
    for (int i = x; i < x + a; i++)
        for (int j = y; j < y + b; j++)
            if (map[i][j] < temp)
            {
                ret.first = i;
                ret.second = j;
                temp = map[i][j];
            }
    return ret;
}
bool Judge(int x, int y)
{
    for (int i = x; i < x + a; i++)
        for (int j = y; j < y + b; j++)
            if (vis[i][j])
                return false;
    return true;
}
priority_queue<node> pq;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> a >> b;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> map[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + map[i][j];
    for (int i = 1; i + a - 1 <= n; i++)
    {
        for (int j = 1; j + b - 1 <= m; j++)
        {
            pair<int, int> t = Find(i, j);
            pq.push(node(i, j, t.first, t.second));
        }
    }
    while (!pq.empty())
    {
        node now = pq.top();
        pq.pop();
        if (Judge(now.x, now.y))
        {
            ret[tot][0] = now.x;
            ret[tot][1] = now.y;
            ret[tot++][2] = now.count;
            for (int i = now.x; i < now.x + a; i++)
                for (int j = now.y; j < now.y + b; j++)
                    vis[i][j] = 1;
        }
    }
    cout << tot << endl;
    for (int i = 0; i < tot; i++)
        cout << ret[i][0] << ' ' << ret[i][1] << ' ' << ret[i][2] << endl;
    //system("pause");
    return 0;
}