#include <iostream>
#include <math.h>
#include <queue>
#include <stdio.h>
#include <vector>
using namespace std;
const int N = 3E5 + 50;
const int M = 1e6 + 50;
queue<int> q;
int n, m, w[N];
int head[N], ver[M], nxt[M], tot;
int fa[N][20], d[N], k, cnt1[2 * N], cnt2[2 * N], ans[N];
bool vis[N];
vector<int> v1[N], v2[N], v3[N], v4[N];
void add(int x, int y)
{
    ver[++tot] = y, nxt[tot] = head[x], head[x] = tot;
}
void BFS()
{
    k = log2(n) + 1;
    q.push(1);
    d[1] = 1;
    while (q.size())
    {
        int x = q.front();
        q.pop();
        for (int i = head[x]; i; i = nxt[i])
        {
            int y = ver[i];
            if (!d[y])
            {
                d[y] = d[x] + 1;
                fa[y][0] = x;
                for (int j = 1; j <= k; j++)
                {
                    fa[y][j] = fa[fa[y][j - 1]][j - 1];
                }
                q.push(y);
            }
        }
    }
}
int LCA(int x, int y)
{
    if (d[x] < d[y])
        swap(x, y);
    for (int i = k; i >= 0; i--)
        if (d[fa[x][i]] >= d[y])
            x = fa[x][i];
    if (x == y)
        return y;
    for (int i = k; i >= 0; i--)
        if (fa[x][i] != fa[y][i])
            x = fa[x][i], y = fa[y][i];
    return fa[x][0];
}
void DFS_calc(int x)
{
    int temp1 = cnt1[w[x] + d[x]], temp2 = cnt2[w[x] - d[x] + N];
    vis[x] = 1;
    for (int i = head[x]; i; i = nxt[i])
    {
        int y = ver[i];
        if (!vis[y])
            DFS_calc(y);
    }
    for (int i = 0; i < v1[x].size(); i++)
        cnt1[v1[x][i]]++;
    for (int i = 0; i < v2[x].size(); i++)
        cnt1[v2[x][i]]--;
    for (int i = 0; i < v3[x].size(); i++)
        cnt2[v3[x][i] + N]++;
    for (int i = 0; i < v4[x].size(); i++)
        cnt2[v4[x][i] + N]--;
    ans[x] = cnt1[w[x] + d[x]] - temp1 + cnt2[w[x] - d[x] + N] - temp2;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0, u, v; i < n - 1; i++)
        scanf("%d%d", &u, &v), add(u, v), add(v, u);
    for (int i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    BFS();
    for (int i = 1, x, y; i <= m; i++)
    {
        scanf("%d%d", &x, &y);
        int z = LCA(x, y);
        v1[x].push_back(d[x]);
        v2[fa[z][0]].push_back(d[x]);
        v3[y].push_back(d[x] - 2 * d[z]);
        v4[z].push_back(d[x] - 2 * d[z]);
    }
    DFS_calc(1);
    for (int i = 1; i < n; i++)
        printf("%d ", ans[i]);
    printf("%d\n", ans[n]);
    return 0;
}