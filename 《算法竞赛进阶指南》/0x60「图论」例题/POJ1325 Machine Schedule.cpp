#include <cstring>
#include <iostream>
#include <stdio.h>
using namespace std;
const int N = 105;
const int M = 1050;
int n, m, k;
bool vis[N * 2];
int match[N * 2], head[N * 2], nxt[M], ver[M], tot;
void add(int u, int v)
{
    ver[++tot] = v, nxt[tot] = head[u], head[u] = tot;
}
bool DFS(int x)
{
    for (int i = head[x]; i; i = nxt[i])
    {
        int y = ver[i];
        if (!vis[y])
        {
            vis[y] = 1;
            if (!match[y] || DFS(match[y]))
            {
                match[y] = x;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    while (scanf("%d%d%d", &n, &m, &k) && n)
    {
        memset(head, 0, sizeof(head));
        memset(match, 0, sizeof(match));
        tot = 0;
        int id, a, b;
        for (int i = 0; i < k; i++)
        {
            scanf("%d%d%d", &id, &a, &b);
            if (a && b)
                add(a, n + b);
        }
        int ans = 0;
        for (int i = 1; i < n; i++)
        {
            memset(vis, 0, sizeof(vis));
            if (DFS(i))
                ans++;
        }
        cout << ans << endl;
    }
    //system("pause");
    return 0;
}