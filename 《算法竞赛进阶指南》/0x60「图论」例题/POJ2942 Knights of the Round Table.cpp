#include <cstring>
#include <iostream>
#include <set>
#include <stdio.h>
#include <vector>
using namespace std;
const int N = 1E3 + 5;
const int M = 1e6 + 50;
int n, m;
bool hate[N][N];
int head[N], ver[M << 1], nxt[M << 1], tot;
void add(int u, int v)
{
    ver[++tot] = v;
    nxt[tot] = head[u];
    head[u] = tot;
}
bool cut[N], tag[N];
int dfn[N], low[N], num, root, stack[N], top;
vector<int> dcc[N];
int cnt, vis[N];
void Init()
{
    memset(hate, 0, sizeof(hate));
    tot = 1;
    for (int i = 1; i < N; i++)
        cut[i] = dfn[i] = low[i] = head[i] = 0, dcc[i].clear();
    num = 0;
}
void Tarjan(int x)
{
    dfn[x] = low[x] = ++num;
    int flag = 0;
    stack[++top] = x;
    if (x == root && !head[x])
    {
        dcc[++cnt].push_back(x);
        return;
    }
    for (int i = head[x]; i; i = nxt[i])
    {
        int y = ver[i];
        if (!dfn[y])
        {
            Tarjan(y);
            low[x] = min(low[x], low[y]);
            if (low[y] >= dfn[x])
            {
                flag++;
                if (x != root || flag >= 2)
                    cut[x] = true;
                cnt++;
                int z;
                do
                {
                    z = stack[top--];
                    dcc[cnt].push_back(z);
                } while (z != y);
                dcc[cnt].push_back(x);
            }
        }
        else
            low[x] = min(low[x], dfn[y]);
    }
}
void v_DCC()
{
    cnt = 0;
    top = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!dfn[i])
            root = i, Tarjan(i);
    }
}
bool DFS(int x, int color)
{
    vis[x] = color;
    for (int i = head[x]; i; i = nxt[i])
    {
        int y = ver[i];
        if (!tag[y])
            continue;
        if (!vis[y])
        {
            if (!DFS(y, 3 - color))
                return false;
        }
        else if (vis[y] == color)
            return false;
    }
    return true;
}
bool Judge(int x)
{
    memset(vis, 0, sizeof(vis));
    memset(tag, 0, sizeof(tag));
    for (int i = 0; i < dcc[x].size(); i++)
    {
        int y = dcc[x][i];
        tag[y] = true;
    }
    for (int i = 0; i < dcc[x].size(); i++)
    {
        int y = dcc[x][i];
        if (!vis[y])
        {
            if (!DFS(y, 1))
                return true;
        }
    }
    return false;
}
int main()
{
    while (scanf("%d%d", &n, &m) && n + m)
    {
        Init();
        int u, v;
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d", &u, &v);
            hate[u][v] = hate[v][u] = 1;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (!hate[i][j])
                    add(i, j), add(j, i);
            }
        }
        v_DCC();
        set<int> s;
        for (int i = 1; i <= cnt; i++)
        {
            //对每个v-DCC 判定是否存在奇环
            if (Judge(i))
            {
                for (int j = 0; j < dcc[i].size(); j++)
                {
                    int y = dcc[i][j];
                    s.insert(y);
                }
            }
        }
        cout << n - s.size() << endl;
    }
    system("pause");
    return 0;
}