#include <cstring>
#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;
const int N = 1e6 + 50;
const int M = 1e6 + 50;
#define inf 0x3f3f3f3f
int S, T, tot = 1;
int head[N], ver[M], nxt[M], edge[M], d[N];
bool vis[N];
int dir[8][2] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
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
bool board[205][205];
int n,m;
inline bool Judge(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > n||board[x][y])
        return false;
    return true;
}
int H(int x,int y)
{
    return (x-1)*n+y;
}
int main()
{
    scanf("%d%d", &n, &m);
    memset(board, 0, sizeof(board));
    for (int i = 0, x, y; i < m; i++)
        scanf("%d%d", &x, &y), board[x][y] = true;
    S=0,T=n*n+1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if(board[i][j]) continue;
            if ((i + j) & 1)//奇偶染色
            {
                add(S,H(i,j),1);
                for (int k = 0; k < 8; k++)
                {
                    int nx = i + dir[k][0];
                    int ny = j + dir[k][1];
                    if (Judge(nx, ny))
                        add(H(i, j), H(nx, ny), inf);
                }
            }
            else add(H(i,j),T,1);
        }
    int maxflow = 0, flow = 0;
    while (BFS())
        while (flow = Dinic(S, inf))
            maxflow += flow;
    printf("%d\n", n*n-m-maxflow);
    system("pause");
    return 0;
}