#include <iomanip>
#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;
const int N = 1e5 + 50;
const int M = 2e5 + 50;
int head[N], ver[M], nxt[M], edge[M], tot, in_degree[N], deg[N];
double dis[N];
void add(int x, int y, int z)
{
    ver[++tot] = y, nxt[tot] = head[x], head[x] = tot, edge[tot] = z, in_degree[y]++, deg[y]++;
}
int n, m;
queue<int> q;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1, x, y, z; i <= m; i++)
        scanf("%d%d%d", &x, &y, &z), add(y, x, z);
    q.push(n);
    dis[n] = 0;
    while (q.size())
    {
        int x = q.front();
        q.pop();
        for (int i = head[x]; i; i = nxt[i])
        {
            int y = ver[i];
            dis[y] += (dis[x] + edge[i]) / deg[y];
            if (--in_degree[y] == 0)
                q.push(y);
        }
    }
    cout << fixed << setprecision(2) << dis[1] << endl;
    //system("pause");
    return 0;
}