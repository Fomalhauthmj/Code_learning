/* 
 * Author: Hemengjie
 * Time: 2019-11-01 16:22:35
**/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 3e4 + 50;
const int M = 1e6 + 50;
#define pii pair<int, int>
#define inf 0x3f3f3f3f
vector<int> A;
vector<int> E[N];
vector<int> material[N];
map<int, int> material_map;
map<pii, int> road_map;
map<int, pii> road_rev_map;
int material_cnt = 0;
int vis[N], pre[N];
bool in_circle[N];
pii answer[N];
void DFS(int x, int fa)
{
    vis[x] = 1, pre[x] = fa;
    for (int y : E[x])
    {
        if (y == fa)
            continue;
        if (!vis[y])
            DFS(y, x);
        else if (vis[y] == 1)
        {
            A.push_back(road_map[{x, y}]);
            int t1 = x, t2 = pre[t1];
            do
            {
                //cout << "cur edge" << t1 << " " << t2 << endl;
                A.push_back(road_map[{t1, t2}]);
                t1 = t2, t2 = pre[t1];
            } while (t1 != y);
        }
    }
    vis[x] = 2;
}
int head[N], ver[M], nxt[M], edge[M], tot = 1;
int d[N];
int S, T;
void add(int x, int y, int z)
{
    ver[++tot] = y, nxt[tot] = head[x], head[x] = tot, edge[tot] = z;
    ver[++tot] = x, nxt[tot] = head[y], head[y] = tot, edge[tot] = 0;
}
bool BFS()
{
    memset(d, 0, sizeof(d));
    queue<int> q;
    q.push(S);
    d[S] = 1; //不为1  陷入死循环
    while (q.size())
    {
        int x = q.front();
        q.pop();
        for (int i = head[x]; i; i = nxt[i])
        {
            int y = ver[i];
            if (edge[i] && !d[y])
            {
                d[y] = d[x] + 1;
                q.push(y);
                if (y == T)
                    return true;
            }
        }
    }
    return false;
}
int Dinic(int x, int flow)
{
    if (x == T)
        return flow;
    int rest = flow, k;
    for (int i = head[x]; i && rest; i = nxt[i])
    {
        int y = ver[i];
        if (edge[i] && d[y] == d[x] + 1)
        {
            k = Dinic(y, min(edge[i], rest));
            if (!k)
                d[y] = 0;
            edge[i] -= k;
            edge[i ^ 1] += k;
            rest -= k;
        }
    }
    return flow - rest;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    scanf("%d%d", &n, &k);
    S = 0, T = 15000;
    for (int x = 1; x <= n; x++)
    {
        int y, mi, bi;
        scanf("%d%d", &y, &mi);
        E[x].push_back(y), E[y].push_back(x);
        road_map[{x, y}] = road_map[{y, x}] = x;
        road_rev_map[x] = {x, y};
        while (mi--)
        {
            scanf("%d", &bi);
            if (!material_map[bi])
                material_map[bi] = ++material_cnt;
            add(x, n + material_map[bi], 1);
        }
    }
    for (int i = 1; i <= k; i++)
    {
        answer[i] = {0, 0};
        int ci;
        scanf("%d", &ci);
        material[material_map[ci]].push_back(i);
    }
    for (int i = 1; i <= material_cnt; i++)
        add(n + i, T, material[i].size());
    //, cout << n + i << " " << T << " " << material[i].size() << endl;
    DFS(1, 0);            //找环
    for (int road_id : A) //in circle road
        in_circle[road_id] = true;
    for (int i = 1; i <= n; i++)
        if (!in_circle[i])
            add(S, i, 1);
    int maxflow = 0, flow;
    bool finish = true;
    while (BFS())
        while (flow = Dinic(S, inf))
            maxflow += flow;
    //cout << "max flow " << maxflow << endl;
    if (maxflow < n - A.size())
        finish = false;
    for (int road_id : A)
        add(S, road_id, 1);
    while (BFS())
        while (flow = Dinic(S, inf))
            maxflow += flow;
    //cout << "max flow " << maxflow << endl;
    if (maxflow < n - 1)
        finish = false;
    if (finish)
    {
        //how to find answer?
        for (int x = 1; x <= n; x++)
        {
            for (int i = head[x]; i; i = nxt[i])
            {
                int y = ver[i];
                if (!edge[i] && y > n)
                {
                    //cout << x << " " << y << endl;
                    answer[material[y - n].back()] = road_rev_map[x];
                    material[y - n].pop_back();
                    break;
                }
            }
        }
        for (int i = 1; i <= k; i++)
            printf("%d %d\n", answer[i].first, answer[i].second);
    }
    else
        printf("-1\n");
    //system("pause");
    return 0;
}