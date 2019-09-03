#include <iostream>
#include <map>
#include <queue>
#include <stdio.h>
using namespace std;
#define pii pair<int, int>
const int N = 1e6 + 50;
int head[N], nxt[N], ver[N], tot, in[N], ans[N], n;
void add(int x, int y)
{
    ver[++tot] = y, nxt[tot] = head[x], head[x] = tot, in[y]++;
}
int index(int x, int y)
{
    if (x > y)
        swap(x, y);
    return (x - 1) * (2 * n - x) / 2 + y - x;
}
int main()
{
    scanf("%d", &n);
    for (int u = 1; u <= n; u++)
    {
        for (int j = 0, v, pre; j < n - 1; j++)
        {
            scanf("%d", &v);
            if (j)
                add(index(u, pre), index(u, v));
            pre = v;
        }
    }
    queue<int> q;
    for (int i = 1; i <= n * (n - 1) / 2; i++)
        if (!in[i])
            q.push(i), ans[i] = 1;
    int pcnt = 0;
    int ret = 0;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        ret = max(ret, ans[x]);
        pcnt++;
        for (int i = head[x]; i; i = nxt[i])
        {
            int y = ver[i];
            ans[y] = ans[x] + 1;
            if (--in[y] == 0)
            {
                q.push(y);
            }
        }
    }
    if (pcnt < n * (n - 1) / 2)
        printf("-1\n");
    else
        printf("%d\n", ret);
    //system("pause");
    return 0;
}