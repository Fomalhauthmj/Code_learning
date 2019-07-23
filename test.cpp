#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5, MOD = 1e9 + 7;
inline int read()
{
    char c = getchar();
    int x = 0, f = 1;
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}
struct edge
{
    int v, ne;
} e[N << 1];
int cnt = 0, h[N], w[N];
inline void ins(int u, int v)
{
    cnt++;
    e[cnt].v = v;
    e[cnt].ne = h[u];
    h[u] = cnt;
    cnt++;
    e[cnt].v = u;
    e[cnt].ne = h[v];
    h[v] = cnt;
}
int n;
ll f[N][2];
void dp(int u, int fa)
{
    if (w[u])
        f[u][1] = 1;
    else
        f[u][0] = 1;
    for (int i = h[u]; i; i = e[i].ne)
    {
        int v = e[i].v;
        if (v == fa)
            continue;
        dp(v, u);
        f[u][1] = (f[u][1] * (f[v][0] + f[v][1]) + f[u][0] * f[v][1]) % MOD;
        f[u][0] = f[u][0] * (f[v][0] + f[v][1]) % MOD;
    }
    cout << "rt: " << u << " 0:" << f[u][0] << " 1:" << f[u][1] << endl;
}
int main()
{
    n = read();
    for (int i = 1; i <= n - 1; i++)
        ins(read(), i);
    for (int i = 0; i < n; i++)
        w[i] = read();
    dp(0, -1);
    cout << f[0][1];
    system("pause");
}
10
0 1 2 1 4 4 4 0 8
0 0 0 1 0 1 1 0 0 1
rt: 9 0:0 1:1
rt: 8 0:1 1:1
rt: 7 0:1 1:0
rt: 6 0:0 1:1
rt: 5 0:0 1:1
rt: 4 0:1 1:2
rt: 3 0:0 1:1
rt: 2 0:1 1:1
rt: 1 0:6 1:7
rt: 0 0:26 1:27