#include <cstring>
#include <iostream>
#include <stdio.h>
using namespace std;
const int N = 1e5 + 50;
const int M = 4e5 + 50;
#define pii pair<int, int>
int n, m, k;
int sze[N], fa[N];
bool monster[N];
int Find(int x)
{
    if (fa[x] == x)
        return x;
    return fa[x] = Find(fa[x]);
}
pii road[M];
int head[N], ver[M], nxt[M], tot, deg[N];
void add(int x, int y)
{
    ver[++tot] = y, nxt[tot] = head[x], head[x] = tot;
}
void Init()
{
    tot = 0;
    memset(deg, 0, sizeof(deg));
    memset(head, 0, sizeof(head));
    memset(monster, 0, sizeof(monster));
    for (int i = 1; i <= n; i++)
        fa[i] = i, sze[i] = 1;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d", &n, &m, &k);
        Init();
        for (int i = 0; i < m; i++)
            scanf("%d%d", &road[i].first, &road[i].second);
        for (int i = 0, pos; i < k; i++)
            scanf("%d", &pos), monster[pos] = true, sze[pos] = 0;
        for (int i = 0; i < m; i++)
        {
            int fx = Find(road[i].first);
            int fy = Find(road[i].second);
            if (fx != fy && !monster[fx] && !monster[fy])
            {
                fa[fx] = fy;
                sze[fy] += sze[fx];
            }
            else if (monster[fx] || monster[fy])
            {
                if (monster[fx])
                    deg[fx]++;
                if (monster[fy])
                    deg[fy]++;
                add(fx, fy);
                add(fy, fx);
            }
        }
        int start = Find(1);
        double ans = sze[start];
        sze[start] = 0;
        double temp = 0;
        for (int i = 1; i <= n; i++)
        {
            if (monster[i])
            {
                int sum = 0;
                int connect = 0;
                for (int j = head[i]; j; j = nxt[j])
                {
                    int z = ver[j], fz = Find(z);
                    if (fz == start)
                        connect++;
                    sum += sze[fz];
                }
                if (connect)
                    temp = max(temp, sum * 1.0 / deg[i]);
            }
        }
        printf("%.6f\n", ans + temp);
    }
    //system("pause");
    return 0;
}