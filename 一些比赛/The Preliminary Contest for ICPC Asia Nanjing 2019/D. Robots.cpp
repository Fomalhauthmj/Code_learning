#include <cstring>
#include <iostream>
#include <queue>
#include <stdio.h>
#include <vector>
using namespace std;
const int N = 1E5 + 50;
const int M = 2E5 + 50;
int head[N], ver[M], nxt[M], n, m, tot, out[N], in[N];
double dp1[N], dp2[N];
vector<int> v[N];
void add(int x, int y)
{
    ver[++tot] = y, nxt[tot] = head[x], head[x] = tot, out[x]++;
}
void Dp1(int x)
{
    double temp = 0;
    for (int i = head[x]; i; i = nxt[i])
    {
        int y = ver[i];
        temp += dp1[y];
    }
    dp1[x] = (temp + out[x] + 1) / out[x];
}
void Dp2(int x)
{
    double temp = (out[x] + 1) * dp1[x];
    for (int i = head[x]; i; i = nxt[i])
    {
        int y = ver[i];
        temp += dp2[y];
    }
    dp2[x] = temp / out[x];
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        tot = 0;
        memset(head, 0, sizeof(head));
        memset(out, 0, sizeof(out));
        memset(in, 0, sizeof(in));
        for (int i = 1; i <= n; i++)
            v[i].clear();
        scanf("%d%d", &n, &m);
        for (int i = 0, x, y; i < m; i++)
            scanf("%d%d", &x, &y), add(x, y), v[y].push_back(x), in[x]++;
        queue<int> q;
        q.push(n);
        dp1[n] = 0;
        dp2[n] = 0;
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            if (x != n)
                Dp1(x), Dp2(x);
            //cout << dp1[x] << " " << dp2[x] << endl;
            for (int i = 0; i < v[x].size(); i++)
            {
                int y = v[x][i];
                if (--in[y] == 0)
                    q.push(y);
            }
        }
        printf("%.2f\n", dp2[1]);
    }
    //system("pause");
    return 0;
}