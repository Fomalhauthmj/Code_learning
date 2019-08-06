#include <cstring>
#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;
const int N = 1e5 + 50;
#define inf 0x3f3f3f3f
#define ll long long
int head[N], ver1[3 * N], ver2[3 * N], nxt[3 * N], edge[3 * N], tot = 1, n, m;
int hc[N], vc[3 * N], nc[3 * N], ec[3 * N], tc;
//差分约束
void add(int u, int v, int w)
{
    ver1[++tot] = v, ver2[tot] = u, nxt[tot] = head[u], head[u] = tot, edge[tot] = w;
}
void add_c(int u, int v, int w)
{
    vc[++tc] = v, nc[tc] = hc[u], hc[u] = tc, ec[tc] = w;
}
int num, dfn[N], low[N], stack[N], top, color[N], cnt, in_degree[N];
bool in_stack[N];
void Tarjan(int x)
{
    dfn[x] = low[x] = ++num;
    stack[++top] = x, in_stack[x] = true;
    for (int i = head[x]; i; i = nxt[i])
    {
        int y = ver1[i];
        if (!dfn[y])
        {
            Tarjan(y);
            low[x] = min(low[x], low[y]);
        }
        else if (in_stack[y])
            low[x] = min(low[x], dfn[y]);
    }
    if (dfn[x] == low[x])
    {
        ++cnt;
        int y;
        do
        {
            y = stack[top--], color[y] = cnt, in_stack[y] = false;
        } while (x != y);
    }
}
bool SCC()
{
    for (int i = 0; i <= n; i++)
        if (!dfn[i])
            Tarjan(i);
    for (int i = 2; i <= tot; i++)
    {
        //检查所有边
        int u = ver1[i], v = ver2[i];
        if (color[u] == color[v] && edge[i])
            return false;
    }
    //缩点
    for (int x = 0; x <= n; x++)
    {
        for (int i = head[x]; i; i = nxt[i])
        {
            int y = ver1[i];
            if (color[x] != color[y])
                add_c(color[x], color[y], edge[i]), in_degree[color[y]]++;
        }
    }
    return true;
}
int dp[N];
void Topo()
{
    //DAG 拓扑排序
    queue<int> q;
    q.push(color[0]);
    for (int i = 1; i <= cnt; i++)
    {
        if (!in_degree[i] && i != color[0])
            q.push(i),dp[i]=1;
    }
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = hc[x]; i; i = nc[i])
        {
            int y = vc[i];
            in_degree[y]--;
            dp[y] = max(dp[y], dp[x] + ec[i]);
            if (!in_degree[y])
            {
                q.push(y);
            }
        }
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    int x, a, b;
    //d[i]>=1  d[i]>=d[0]+1
    for (int i = 1; i <= n; i++)
        add(0, i, 1);
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &x, &a, &b);
        switch (x)
        {
        case 1:
            //a=b d[a]-d[b]>=0 d[a]-d[b]<=0
            add(a, b, 0);
            add(b, a, 0);
            break;
        case 2:
            //a<b d[b]-d[a]>=1
            add(a, b, 1);
            break;
        case 3:
            //a>=b  d[a]-d[b]>=0
            add(b, a, 0);
            break;
        case 4:
            //a>b d[a]-d[b]>=1
            add(b, a, 1);
            break;
        case 5:
            //a<=b d[b]-d[a]>=0
            add(a, b, 0);
            break;
        }
    }
    if (SCC())
    {
        Topo();
        ll ans = 0;
        for (int i = 1; i <= n; i++)
            ans += dp[color[i]];
        cout << ans << endl;
    }
    else
        cout << -1 << endl;
    system("pause");
    return 0;
}