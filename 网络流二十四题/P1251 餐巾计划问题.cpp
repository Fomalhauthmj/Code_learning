#include <cstring>
#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;
const int N = 1e4 + 50;
const int M = 1e6 + 50;
#define inf 0x3f3f3f3f
#define ll long long
int head[N], ver[M], nxt[M], cost[M], tot = 1, pre[N];
ll dis[N], incf[N], edge[M];
int S, T, r[N];
bool vis[N];
void add(int x, int y, int z, int c)
{
    ver[++tot] = y, nxt[tot] = head[x], head[x] = tot, edge[tot] = z, cost[tot] = c;
    ver[++tot] = x, nxt[tot] = head[y], head[y] = tot, edge[tot] = 0, cost[tot] = -c;
}
bool SPFA()
{
    memset(dis, 0x3f, sizeof(dis)); //inf
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
                if (dis[y] > dis[x] + cost[i])
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
    if (dis[T] >= inf)
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
int main()
{
    int days;
    scanf("%d", &days);
    S = 0, T = 2 * days + 1;
    for (int i = 1; i <= days; i++)
        scanf("%d", &r[i]);
    int p, m, f, n, s;
    scanf("%d%d%d%d%d", &p, &m, &f, &n, &s);
    for (int i = 1; i <= days; i++)
    {
        //assume i:需要的干净餐巾  i+days:使用过的脏餐巾
        add(S, i, inf, p);         //可以购买干净餐巾
        add(S, i + days, r[i], 0); //脏餐巾
        add(i, T, r[i], 0);        //干净餐巾
        if (i + 1 <= days)
            add(i + days, i + 1 + days, inf, 0); //延期送洗
        if (i + m <= days)                       //快洗
            add(i + days, i + m, inf, f);
        if (i + n <= days) //慢洗
            add(i + days, i + n, inf, s);
    }
    max_flow = 0, ans = 0;
    while (SPFA())
        Update();
    cout << ans << endl;
    //system("pause");
    return 0;
}