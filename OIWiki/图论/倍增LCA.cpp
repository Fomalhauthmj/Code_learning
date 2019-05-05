//https://www.luogu.org/problemnew/show/P3379
//O2 ??
#include <stdio.h>
#include <vector>
using namespace std;
#define N 500050
int depth[N];
int fa[N][20];
vector<int> v[N];
int lg[N]; //log2(n) floor
int n, m, s;
void DFS(int cur, int pre)
{
    depth[cur] = depth[pre] + 1;
    fa[cur][0] = pre;
    for (int i = 1; (1 << i) <= depth[cur]; i++)
    {
        fa[cur][i] = fa[fa[cur][i - 1]][i - 1];
    }
    for (auto ele : v[cur])
    {
        if (ele != pre)
        {
            DFS(ele, cur);
        }
    }
}
void init()
{
    lg[0] = -1;
    //floor
    for (int i = 1; i <= n; i++)
    {
        lg[i] = lg[i >> 1] + 1;
    }
}
int LCA(int a, int b)
{
    // assume depth[a]>=depth[b]
    if (depth[a] < depth[b])
        swap(a, b);
    // reset to the same depth
    while (depth[a] > depth[b])
    {
        a = fa[a][lg[depth[a] - depth[b]]];
        //up
    }
    if (a == b)
        return a;
    for (int k = lg[depth[a]] + 1; k >= 0; k--)
    {
        if (fa[a][k] != fa[b][k])
        {
            a = fa[a][k];
            b = fa[b][k];
            //up
        }
    }
    return fa[a][0];
}
int main()
{
    /*
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> s;
    */
    scanf("%d%d%d", &n, &m, &s);
    int x, y;
    for (int i = 0; i < n - 1; i++)
    {
        //cin >> x >> y;
        scanf("%d%d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    depth[s] = 0;
    DFS(s, 0);
    init();
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &x, &y);
        printf("%d\n", LCA(x, y));
    }
    return 0;
}