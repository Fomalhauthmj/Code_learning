#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <stdio.h>
using namespace std;
const int N = 1e3 + 50;
const int M = 1e6 + 50;
#define inf 0x3f3f3f3f
int head[N], ver[M], nxt[M], cost[M], edge[M], tot = 1, pre[N];
int dis[N], incf[N];
map<string, int> city;
string name[N];
int S, T;
bool vis[N];
void add(int x, int y, int z, int c)
{
    ver[++tot] = y, nxt[tot] = head[x], head[x] = tot, edge[tot] = z, cost[tot] = c;
    ver[++tot] = x, nxt[tot] = head[y], head[y] = tot, edge[tot] = 0, cost[tot] = -c;
}
bool SPFA()
{
    memset(dis, 0xcf, sizeof(dis)); //-inf
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
    if (dis[T] < 0)
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
    max_flow += incf[T];
    ans += incf[T] * dis[T];
}
int n, v;
void DFS_go(int x)
{
    cout << name[x] << endl;
    if (x != 1 && x != n)
        vis[x] = 1;
    for (int i = head[x + n]; i; i = nxt[i])
    {
        int y = ver[i];
        if (!edge[i] && !vis[y])
        {
            DFS_go(y);
            break;
        }
    }
}
void DFS_back(int x)
{
    if (x != n)
        cout << name[x] << endl;
    if (x != 1 && x != n)
        vis[x] = 1;
    for (int i = head[x]; i; i = nxt[i])
    {
        int y = ver[i];
        if (edge[i] && !vis[y - n])
        {
            DFS_back(y - n);
            break;
        }
    }
}
int main()
{
    scanf("%d%d", &n, &v);
    for (int i = 1; i <= n; i++)
    {
        cin >> name[i], city[name[i]] = i;
        if (i == 1 || i == n)
            add(i, i + n, 2, 1);
        else
            add(i, i + n, 1, 1);
    }
    S = 1, T = n + n;
    string c1, c2;
    for (int i = 1; i <= v; i++)
    {
        cin >> c1 >> c2;
        if (city[c1] > city[c2])
            swap(c1, c2);
        if (city[c1] == 1 && city[c2] == n)
            add(city[c1] + n, city[c2], 2, 0);
        else
            add(city[c1] + n, city[c2], 1, 0);
    }
    max_flow = 0, ans = 0;
    while (SPFA())
        Update();
    if (edge[2])
        printf("No Solution!\n");
    else
    {
        memset(vis, 0, sizeof(vis));
        printf("%d\n", ans - 2);
        DFS_go(1);
        DFS_back(n);
    }
    //system("pause");
    return 0;
}