#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
#define T 105
int n, t, s, e;
int point[2 * T], tot = 0;
int link[1005];
struct edge
{
    int u, v, w;
};
edge es[T];
struct matrix
{
    int a[T][T];
    void init()
    {
        memset(a, 0x3f, sizeof(a));
    }
};
matrix matrix_mul(matrix m1, matrix m2)
{
    matrix ret;
    ret.init();
    for (int i = 0; i < tot; i++)
    {
        for (int j = 0; j < tot; j++)
        {
            for (int k = 0; k < tot; k++)
            {
                ret.a[i][j] = min(ret.a[i][j], m1.a[i][k] + m2.a[k][j]);
            }
        }
    }
    return ret;
}
matrix matrix_pow(matrix m1, int n)
{
    matrix ret;
    ret.init();
    for (int i = 0; i < tot; i++)
        ret.a[i][i] = 0;
    while (n)
    {
        if (n & 1)
            ret = matrix_mul(ret, m1);
        m1 = matrix_mul(m1, m1);
        n >>= 1;
    }
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> t >> s >> e;
    point[tot++] = s;
    point[tot++] = e;
    for (int i = 0; i < t; i++)
    {
        cin >> es[i].w >> es[i].u >> es[i].v;
        point[tot++] = es[i].u;
        point[tot++] = es[i].v;
    }
    sort(point, point + tot);
    tot = unique(point, point + tot) - point;
    for (int i = 0; i < tot; i++)
        link[point[i]] = i;
    matrix start;
    start.init();
    for (int i = 0; i < t; i++)
    {
        int u = link[es[i].u], v = link[es[i].v];
        start.a[u][v] = start.a[v][u] = es[i].w;
    }
    matrix ret = matrix_pow(start, n);
    cout << ret.a[link[s]][link[e]] << endl;
    //system("pause");
    return 0;
}