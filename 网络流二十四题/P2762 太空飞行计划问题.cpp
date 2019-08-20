#include <cstring>
#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;
const int N = 205;
const int M = 1e6 + 50;
#define inf 0x3f3f3f3f
int head[N], ver[M], nxt[M], edge[M], tot = 1;
int d[N], S, T;
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
    int m, n, money;
    scanf("%d%d", &m, &n);
    S = 0, T = m + n + 1;
    int sum = 0;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &money);
        add(S, i, money);
        sum += money;
        char tools[10000];
        memset(tools, 0, sizeof tools);
        cin.getline(tools, 10000);
        int ulen = 0, tool;
        while (sscanf(tools + ulen, "%d", &tool) == 1) //之前已经用scanf读完了赞助商同意支付该实验的费用
        {                                              //tool是该实验所需仪器的其中一个
            //这一行，你可以将读进来的编号进行储存、处理，如连边。
            add(i, m + tool, inf);
            if (tool == 0)
                ulen++;
            else
                while (tool)
                    tool /= 10, ulen++;
            ulen++;
        }
    }
    int cost;
    for (int i = 1; i <= n; i++)
        scanf("%d", &cost), add(m + i, T, cost);
    int maxflow = 0, flow;
    while (BFS())
        while (flow = Dinic(S, inf))
            maxflow += flow;
    for (int i = 1; i <= m; i++)
        if (d[i])
            cout << i << " ";
    cout << endl;
    for (int i = m + 1; i <= m + n; i++)
        if (d[i])
            cout << i - m << " ";
    cout << endl;
    cout << sum - maxflow << endl;
    //system("pause");
    return 0;
}