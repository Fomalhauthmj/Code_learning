#include <iostream>
#include <stdio.h>
using namespace std;
const int N = 1010;
const int M = 8e6 + 50;
int head[N * 2], ver[M], nxt[M], tot;
void add(int u, int v)
{
    ver[++tot] = v, nxt[tot] = head[u], head[u] = tot;
}
int n;
struct node
{
    int s1, e1, s2, e2;
    node(int i1, int i2, int i3, int i4, int i5)
    {
        s1 = i1 * 60 + i2, e1 = s1 + i5;
        e2 = i3 * 60 + i4, s2 = e2 - i5;
    }
    node() {}
} t[N];
bool Judge(node &n1, node &n2, int f1, int f2)
{
    int s1, e1, s2, e2;
    if (!f1)
        s1 = n1.s1, e1 = n1.e1;
    else
        s1 = n1.s2, e1 = n1.e2;
    if (!f2)
        s2 = n2.s1, e2 = n2.e1;
    else
        s2 = n2.s2, e2 = n2.e2;
    if (e1 <= s2 || e2 <= s1)
        return false;
    return true;
}
/*
assume:
1...n 选择开始时
n+1...2n 选择结束前
 */
int dfn[2 * N], low[2 * N], num, stack[2 * N], top, cnt, color[2 * N];
bool in_stack[2 * N];
void Tarjan(int x)
{
    dfn[x] = low[x] = ++num;
    stack[++top] = x, in_stack[x] = true;
    for (int i = head[x]; i; i = nxt[i])
    {
        int y = ver[i];
        if (!dfn[y])
        {
            Tarjan(y);
            low[x] = min(low[x], low[y]);
        }
        else if (in_stack[y])
            low[x] = min(low[x], dfn[y]);
    }
    if (dfn[x] == low[x])
    {
        cnt++;
        int y;
        do
        {
            y = stack[top--], color[y] = cnt, in_stack[y] = false;
        } while (y != x);
    }
}
void SCC()
{
    for (int i = 1; i <= 2 * n; i++)
        if (!dfn[i])
            Tarjan(i);
}
int opp[2 * N], val[2 * N];
int main()
{
    scanf("%d", &n);
    int h1, m1, h2, m2, d;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d:%d %d:%d %d", &h1, &m1, &h2, &m2, &d);
        t[i] = node(h1, m1, h2, m2, d);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (Judge(t[i], t[j], 0, 0))
                add(i, j + n), add(j, i + n); //满足形式 互为逆否
            if (Judge(t[i], t[j], 0, 1))
                add(i, j), add(j + n, i + n);
            if (Judge(t[i], t[j], 1, 0))
                add(i + n, j + n), add(j, i);
            if (Judge(t[i], t[j], 1, 1))
                add(i + n, j), add(j + n, i);
        }
    }
    SCC();
    for (int i = 1; i <= n; i++)
    {
        if (color[i] == color[i + n])
        {
            cout << "NO" << endl;
            return 0;
        }
        opp[i] = i + n, opp[i + n] = i;
    }
    for (int i = 1; i <= 2 * n; i++)
    {
        val[i] = color[i] > color[opp[i]];
        //若c[i] 大于 c[opp[i]]   opp[i]赋0 
    }
    printf("YES\n");
    for (int i = 1; i <= n; i++)
    {
        if (!val[i])
            printf("%02d:%02d %02d:%02d\n", t[i].s1 / 60, t[i].s1 % 60, t[i].e1 / 60, t[i].e1 % 60);
        else
            printf("%02d:%02d %02d:%02d\n", t[i].s2 / 60, t[i].s2 % 60, t[i].e2 / 60, t[i].e2 % 60);
    }
    //system("pause");
    return 0;
}