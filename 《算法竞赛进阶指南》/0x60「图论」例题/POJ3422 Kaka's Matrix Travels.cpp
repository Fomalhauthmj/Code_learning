#include <cstring>
#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;
const int N = 55 * 55 * 2;
const int M = 55 * 55 * 2 * 4;
int head[N], ver[M], nxt[M], edge[M], cost[M], tot = 1;
int n, k, dis[N], S, T, incf[N], pre[N];
bool vis[N];
inline int Pos(int x, int y, int k)
{
    return x * n + y + k * n * n;
}
void add(int x, int y, int z, int c)
{
    ver[++tot] = y, nxt[tot] = head[x], head[x] = tot, edge[tot] = z, cost[tot] = c;
    ver[++tot] = x, nxt[tot] = head[y], head[y] = tot, edge[tot] = 0, cost[tot] = -c;
}
bool SPFA()
{
    memset(dis, 0xcf, sizeof(dis));
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
int max_flow, ans;
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
    //cout<<"flow "<<incf[T]<<" dis "<<dis[T]<<endl;
    max_flow += incf[T];
    ans += incf[T] * dis[T];
}
int main()
{
    scanf("%d%d", &n, &k);
    int val;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &val);
            add(Pos(i, j, 0), Pos(i, j, 1), 1, val);
            add(Pos(i, j, 0), Pos(i, j, 1), k - 1, 0);
            if (i < n)
                add(Pos(i, j, 1), Pos(i + 1, j, 0), k, 0);
            if (j < n)
                add(Pos(i, j, 1), Pos(i, j + 1, 0), k, 0);
        }
    }
    max_flow = ans = 0;
    S=Pos(1,1,0),T=Pos(n,n,1);
    while (SPFA())
    {
        Update();
    }
    printf("%d\n", ans);
    //system("pause");
    return 0;
}