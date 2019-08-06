#include <iostream>
#include <stdio.h>
using namespace std;
const int N = 1E4 + 50;
const int M = 5e4 + 50;
int head[N], ver[M << 1], nxt[M << 1], tot;
int n, m;
int stack[M<<1], top, ans[M<<1], t;
void add(int u, int v)
{
    ver[++tot] = v;
    nxt[tot] = head[u];
    head[u] = tot;
}
void Euler()
{
    stack[++top] = 1;
    while (top > 0)
    {
        int x = stack[top], i = head[x];
        if (i)
        {
            stack[++top] = ver[i];
            head[x] = nxt[i];
        }
        else
        {
            top--;
            ans[++t] = x;
        }
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    int a, b;
    for (int i = 0; i < m; i++)
        scanf("%d%d", &a, &b), add(a, b), add(b, a);
    Euler();
    for (int i = t; i >= 1; i--)
        printf("%d\n", ans[i]);
    system("pause");
    return 0;
}