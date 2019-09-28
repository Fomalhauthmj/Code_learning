#include <cstring>
#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;
const int N = 1e6 + 50;
const int M = 2e6 + 50;
#define inf 0x3f3f3f3f
int head[N], nxt[M], edge[M], ver[M], d[N], tot;
int S, T, n, m;
#define col_in 0
#define col_out 1
#define row_in 2
#define row_out 3
void Init()
{
    tot = 1;
    memset(head, 0, sizeof(head));
}
void add(int x, int y, int z)
{
    ver[++tot] = y, nxt[tot] = head[x], head[x] = tot, edge[tot] = z;
    ver[++tot] = x, nxt[tot] = head[y], head[y] = tot, edge[tot] = 0;
}
int H(int x, int y, int st)
{
    return (x - 1) * m + y + st * n * m;
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
char board[105][105];
inline bool Judge(int x, int y)
{
    return x >= 1 && x <= n && y >= 1 && y <= m && board[x][y] == '0';
}
int main()
{
    int t, a, b;
    scanf("%d", &t);
    while (t--)
    {
        Init();
        scanf("%d%d%d%d", &n, &m, &a, &b);
        for (int i = 1; i <= n; i++)
            scanf("%s", board[i] + 1);
        //for (int i = 1; i <= n; i++)
        //printf("%s\n", board[i] + 1);
        S = 0, T = 5e4;
        for (int i = 1, p; i <= a; i++)
        {
            scanf("%d", &p);
            if (board[1][p] == '0')
                add(S, H(1, p, col_in), inf);
        }
        for (int i = 1, e; i <= b; i++)
        {
            scanf("%d", &e);
            if (board[n][e] == '0')
                add(H(n, e, col_out), T, inf);
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (board[i][j] == '0')
                {
                    add(H(i, j, col_in), H(i, j, col_out), 1);
                    add(H(i, j, row_in), H(i, j, row_out), 1);
                    add(H(i, j, col_out), H(i, j, row_in), 1);
                    add(H(i, j, row_out), H(i, j, col_in), 1);
                    if (Judge(i, j - 1))
                        add(H(i, j, row_out), H(i, j - 1, row_in), inf);
                    if (Judge(i, j + 1))
                        add(H(i, j, row_out), H(i, j + 1, row_in), inf);
                    if (Judge(i - 1, j))
                        add(H(i, j, col_out), H(i - 1, j, col_in), inf);
                    if (Judge(i + 1, j))
                        add(H(i, j, col_out), H(i + 1, j, col_in), inf);
                }
            }
        }
        int maxflow = 0, flow;
        while (BFS())
            while (flow = Dinic(S, inf))
                maxflow += flow;
        //cout << "maxflow:" << maxflow << endl;
        if (maxflow == a)
            printf("Yes\n");
        else
            printf("No\n");
    }
    //system("pause");
    return 0;
}
/*
2
3 4 2 2
0000
0011
0000
1 4
2 4
3 4 2 2
0000
0011
0000
3 4
2 4

Yes
No

1
2 2 2 2
00
00
1 2
1 2
*/