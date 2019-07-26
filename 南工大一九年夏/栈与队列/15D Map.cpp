//http://codeforces.com/contest/15/problem/D
#include <algorithm>
#include <deque>
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f
const int N = 1010;
int n, m, a, b;
int map[N][N];
bool vis[N][N];
ll sum[N][N], min_ele[N][N], right_down[N][N];
inline bool Judge(int x, int y)
{
    if (vis[x][y] || vis[x + a - 1][y] || vis[x + a - 1][y + b - 1] || vis[x][y + b - 1])
        return false;
    return true;
}
struct node
{
    int x, y;
    ll count;
    node(int i1, int i2, ll l1) : x(i1), y(i2), count(l1) {}
    bool operator<(const node &n) const
    {
        if (count != n.count)
            return count < n.count;
        if (x != n.x)
            return x < n.x;
        return y < n.y;
    }
};
vector<node> task, ret;
void Work()
{
    //对每行进行单调递增队列 确定范围内最小
    for (int i = 1; i <= n; i++)
    {
        deque<int> q; //存放列号
        for (int j = 1; j <= m; j++)
        {
            while (!q.empty() && j - q.front() >= b)
                q.pop_front();
            while (!q.empty() && map[i][j] < map[i][q.back()])
                q.pop_back();
            q.push_back(j);
            min_ele[i][j] = map[i][q.front()];
        }
    }
    //对每列进行单调队列 确定范围内最小
    for (int j = b; j <= m; j++)
    {
        deque<int> q;
        for (int i = 1; i <= n; i++)
        {
            while (!q.empty() && i - q.front() >= a)
                q.pop_front();
            while (!q.empty() && min_ele[i][j] < min_ele[q.back()][j])
                q.pop_back();
            q.push_back(i);
            right_down[i][j] = min_ele[q.front()][j];
        }
    }
}
int main()
{
    scanf("%d%d%d%d", &n, &m, &a, &b);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &map[i][j]), sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + map[i][j];
    Work();
    for (int i = 1; i + a - 1 <= n; i++)
    {
        for (int j = 1; j + b - 1 <= m; j++)
        {
            ll temp = sum[i + a - 1][j + b - 1] - sum[i + a - 1][j - 1] - sum[i - 1][j + b - 1] + sum[i - 1][j - 1] - a * b * right_down[i + a - 1][j + b - 1];
            task.push_back(node(i, j, temp));
        }
    }
    sort(task.begin(), task.end());
    for (auto it:task)
    {
        if (Judge(it.x, it.y))
        {
            ret.push_back(it);
            for (int i = it.x; i < it.x + a; i++)
                for (int j = it.y; j < it.y + b; j++)
                    vis[i][j] = 1;
        }
    }
    printf("%d\n",ret.size());
    for (auto it : ret)
        printf("%d %d %I64d\n", it.x, it.y, it.count);
    //system("pause");
    return 0;
}