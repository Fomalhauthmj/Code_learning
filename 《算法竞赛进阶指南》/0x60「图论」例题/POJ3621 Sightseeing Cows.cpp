#include <cstring>
#include <iomanip>
#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;
const int N = 1010;
const int M = 5050;
#define eps 1e-4
#define inf 0x3f3f3f3f
int l, p;
struct edge
{
    int a, b, t;
} E[M];
int n, m, f[N];
int cnt[N], head[N], nxt[M << 1], ver[M << 1], tot;
double edge[M << 1], dist[N];
bool vis[N];
void add(int u, int v, double w)
{
    ver[++tot] = v;
    nxt[tot] = head[u];
    head[u] = tot;
    edge[tot] = w;
}
bool SPFA(double mid)
{
    //重新建图
    tot = 0;
    memset(head, 0, sizeof(head));
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++)
        dist[i] = inf;
    for (int i = 1; i <= m; i++)
    {
        add(E[i].a, E[i].b, mid * E[i].t - f[E[i].a]);
    }
    queue<int> q;
    q.push(1);
    dist[1] = cnt[1] = 0;
    vis[1] = 1;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        vis[x] = 0;
        for (int i = head[x]; i; i = nxt[i])
        {
            int y = ver[i];
            if (dist[y] > dist[x] + edge[i])
            {
                dist[y] = dist[x] + edge[i];
                cnt[y] = cnt[x] + 1;
                if (cnt[y] >= n)
                    return false;
                if (!vis[y])
                    q.push(y), vis[y] = 1;
            }
        }
    }
    return true; //无负环
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &f[i]);
    for (int i = 1; i <= m; i++)
        scanf("%d%d%d", &E[i].a, &E[i].b, &E[i].t);
    double left = 0;
    double right = 1010;
    double mid;
    while (left + eps < right)
    {
        mid = (left + right) / 2;
        //cout << "cur:" << mid << endl;
        if (SPFA(mid))
        {
            //无负环
            right = mid;
        }
        else
            left = mid;
    }
    cout << fixed << setprecision(2) << (left + right) / 2 << endl;
    //system("pause");
    return 0;
}