#include <cstring>
#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;
const int N = 5E4 + 50;
#define inf 0x3f3f3f3f
int head[N], ver[N * 3], nxt[N * 3], edge[N * 3], tot = 0;
int n;
bool vis[N];
int dis[N];
void add(int u, int v, int w)
{
    u++, v++; //-1...50000 偏移到0...50001
    ver[++tot] = v;
    nxt[tot] = head[u];
    head[u] = tot;
    edge[tot] = w;
}
void SPFA()
{
    queue<int> q;
    q.push(0);
    for (int i = 0; i < N; i++)
        dis[i] = -inf;
    dis[0] = 0;
    vis[0] = 1;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        vis[x] = 0;
        for (int i = head[x]; i; i = nxt[i])
        {
            int y = ver[i];
            if (dis[y] < dis[x] + edge[i])
            {
                dis[y] = dis[x] + edge[i];
                if (!vis[y])
                    q.push(y), vis[y] = 1;
            }
        }
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = -1; i <= 50000; i++)
        add(i, i + 1, 0), add(i + 1, i, -1);
    int a, b, c;
    for (int i = 1; i <= n; i++)
        scanf("%d%d%d", &a, &b, &c), add(a - 1, b, c);
    SPFA();
    cout << dis[50001] << endl;
    //system("pause");
    return 0;
}