#include <cstring>
#include <iostream>
#include <stdio.h>
using namespace std;
const int N = 105;
const int M = 1E4 + 50;
int head[N], nxt[M], ver[M], tot;
int match[N], m, n;
bool vis[N];
void add(int x, int y)
{
    ver[++tot] = y, nxt[tot] = head[x], head[x] = tot;
}
bool DFS(int x)
{
    for (int i = head[x]; i; i = nxt[i])
    {
        int y = ver[i];
        if (!vis[y])
        {
            vis[y] = true;
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
    scanf("%d%d", &m, &n);
    int x, y;
    while (scanf("%d%d", &x, &y) && x != -1 && y != -1)
    {
        add(y, x);
    }
    int cnt = 0;
    for (int i = m + 1; i <= n; i++)
    {
        memset(vis, 0, sizeof(vis));
        if (DFS(i))
            cnt++;
    }
    if (cnt == 0)
        printf("No Solution!\n");
    else
    {
        printf("%d\n", cnt);
        for (int i = 1; i <= m; i++)
        {
            if (match[i])
                printf("%d %d\n", i, match[i]);
        }
    }
    //system("pause");
    return 0;
}