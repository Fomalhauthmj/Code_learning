#include <cstring>
#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;
#define pii pair<int, int>
#define inf 0x3f3f3f3f
const int N = 55;
const int M = 1e5 + 50;
pii e[N * N];
int n, m, S, T, d[N * 2];
bool connect[N][N];
int head[N * 2], nxt[M], ver[M], edge[M], tot;
void add(int u, int v, int w)
{
    ver[++tot] = v, edge[tot] = w, nxt[tot] = head[u], head[u] = tot;
    ver[++tot] = u, edge[tot] = 0, nxt[tot] = head[v], head[v] = tot;
}
bool BFS()
{
    memset(d, 0, sizeof(d));
    queue<int> q;
    q.push(S), d[S] = 1;
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
            k = Dinic(y, min(rest, edge[i]));
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
    while (cin>>n>>m)
    {
        memset(connect, 0, sizeof(connect));
        char str[20];
        for (int i = 0; i < n; i++)
            connect[i][i] = true;
        for (int i = 0; i < m; i++)
        {
            scanf("%s", str);
            int a = 0, b = 0, j;
            for (j = 1; str[j] != ','; j++)
                a = a * 10 + str[j] - '0';
            for (j++; str[j] != ')'; j++)
                b = b * 10 + str[j] - '0';
            e[i].first = a, e[i].second = b;
            connect[a][b] = connect[b][a] = true;
        }
        int ans = inf;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!connect[i][j])
                {
                    S = i + n, T = j;
                    tot = 1, memset(head, 0, sizeof(head));
                    for (int k = 0; k < n; k++)
                        if (k + n != S && k != T)
                            add(k, k + n, 1);
                    for (int k = 0, x, y; k < m; k++)
                    {
                        x = e[k].first, y = e[k].second;
                        add(x + n, y, inf);
                        add(y + n, x, inf);
                    }
                    int cnt = 0, temp;
                    while (BFS())
                        while (temp = Dinic(S, inf))
                            cnt += temp;
                    ans = min(ans, cnt);
                }
            }
        }
        if (ans == inf)
            cout << n << endl;
        else
            cout << ans << endl;
    }
    return 0;
}