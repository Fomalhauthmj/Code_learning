#include <cstring>
#include <iostream>
#include <stdio.h>
using namespace std;
const int N = 1010;
#define ll long long
int city[N][N];
int V, E, S, K, C;
bool vis[N];
int d[N], team[N];
void Init()
{
    memset(city, 0x3f, sizeof(city));
    for (int i = 1; i <= V; i++)
        city[i][i] = 0;
}
int Dijkstra(int S)
{
    memset(d, 0x3f, sizeof(d));  // dist数组
    memset(vis, 0, sizeof(vis)); // 节点标记
    d[S] = 0;
    for (int i = 1; i <= V; i++)
    { // 重复进行n-1次
        int x = 0;
        // 找到未标记节点中dist最小的
        for (int j = 1; j <= V; j++)
            if (!vis[j] && (x == 0 || d[j] < d[x]))
                x = j;
        vis[x] = 1;
        // 用全局最小值点x更新其它节点
        for (int y = 1; y <= V; y++)
            d[y] = min(d[y], d[x] + city[x][y]);
    }
    int ret = 0;
    for (int i = 1; i <= V; i++)
        ret = max(ret, d[i]);
    return ret;
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d%d%d", &V, &E, &S, &K, &C);
        Init();
        for (int i = 1; i <= K; i++)
            scanf("%d", &team[i]);
        for (int i = 1; i <= E; i++)
        {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            city[u][v] = city[v][u] = min(city[u][v], w);
        }
        int hero = Dijkstra(S);
        V++, city[V][V] = 0;
        for (int i = 1; i <= K; i++)
            city[V][team[i]] = city[team[i]][V] = 0;
        int ret = Dijkstra(V) * C;
        if (hero <= ret)
            printf("%d\n", hero);
        else
            printf("%d\n", ret / C);
    }
    //system("pause");
    return 0;
}
