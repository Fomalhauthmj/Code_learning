#include <cstring>
#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;
#define inf 0x3f3f3f3f
#define ll long long
const int N = 1e6 + 50;
const int M = 1e6 + 50;
int head[N], ver[M], nxt[M], edge[M], cost[M], incf[N], pre[N], dis[N];
bool vis[N];
int S, T;
int k, p, q, tot = 1;
void add(int x, int y, int z, int c)
{
    ver[++tot] = y, nxt[tot] = head[x], head[x] = tot, edge[tot] = z, cost[tot] = c;
    ver[++tot] = x, nxt[tot] = head[y], head[y] = tot, edge[tot] = 0, cost[tot] = -c;
}
bool SPFA()
{
    memset(dis, 0xcf, sizeof(dis)); //inf
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    dis[S] = 0, vis[S] = 1, incf[S] = 1 << 30;
    q.push(S);
    while (q.size())
    {
        int x = q.front();
        q.pop();
        vis[x] = 0;
        for (int i = head[x]; i; i = nxt[i])
        {
            if (edge[i])
            {
                int y = ver[i];
                if (dis[y] < dis[x] + cost[i])
                {
                    dis[y] = dis[x] + cost[i];
                    incf[y] = min(incf[x], edge[i]);
                    pre[y] = i;
                    if (!vis[y])
                        q.push(y), vis[y] = 1;
                }
            }
        }
    }
    if (dis[T] == 0xcfcfcfcf)
        return false;
    return true;
}
ll max_flow, ans;
void Update()
{
    int x = T;
    while (x != S)
    {
        int i = pre[x];
        edge[i] -= incf[T];
        edge[i ^ 1] += incf[T];
        x = ver[i ^ 1];
    }
    max_flow += incf[T];
    ans += incf[T] * dis[T];
}
int H(int r, int c, int z)
{
    return (r - 1) * p + c + z * p * q;
}
bool Judge(int r, int c)
{
    if (r < 1 || r > q || c < 1 || c > p)
        return false;
    return true;
}
void DFS(int cur_car, int x)
{
    int r = (x - p * q) / p, c = (x - p * q) % p;
    c == 0 ? c = p : r++;
    if (x == H(q, p, 1))
        return;
    //cout << "now: " << r << " " << c << endl;
    for (int i = head[x]; i; i = nxt[i])
    {
        int y = ver[i];
        int nr = y / p, nc = y % p;
        nc == 0 ? nc = p : nr++;
        if (!edge[i ^ 1])
            continue;
        //cout << "goto: " << nr << " " << nc << endl;
        printf("%d %d\n", cur_car, nr == r + 1 ? 0 : 1);
        DFS(cur_car, y + p * q);
        edge[i ^ 1]--;
        break;
    }
}
int main()
{
    scanf("%d%d%d", &k, &p, &q);
    int val;
    S = 0, T = 2 * p * q + 1;
    add(S, H(1, 1, 0), k, 0), add(H(q, p, 1), T, k, 0);
    for (int i = 1; i <= q; i++)
        for (int j = 1; j <= p; j++)
        {
            scanf("%d", &val);
            if (val != 1)
                add(H(i, j, 0), H(i, j, 1), 1, val), add(H(i, j, 0), H(i, j, 1), inf, 0);
        }
    for (int i = 1; i <= q; i++)
        for (int j = 1; j <= p; j++)
        {
            if (Judge(i + 1, j))
                add(H(i, j, 1), H(i + 1, j, 0), inf, 0);
            if (Judge(i, j + 1))
                add(H(i, j, 1), H(i, j + 1, 0), inf, 0);
        }
    max_flow = 0, ans = 0;
    while (SPFA())
        Update();
    //cout << max_flow << " " << ans << endl;
    for (int i = 1; i <= max_flow; i++)
    {
        DFS(i, H(1, 1, 1));
    }
    //system("pause");
    return 0;
}