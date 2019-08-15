#include <iostream>
#include <math.h>
#include <queue>
#include <set>
#include <stdio.h>
using namespace std;
#define ll long long
const int N = 1E5 + 50;
const int M = 3e5 + 50;
int n, m, d[N], dfn[N], num;
int head[N], ver[M], nxt[M], edge[M], tot;
int fa[N][20], k;
ll dis[N];
struct node
{
    int id;
    bool operator<(const node &n) const
    {
        return dfn[id] < dfn[n.id];
    }
};
set<node> s;
void add(int x, int y, int z)
{
    ver[++tot] = y, nxt[tot] = head[x], head[x] = tot, edge[tot] = z;
}
void BFS()
{
    k = log2(n) + 1;
    queue<int> q;
    q.push(1);
    d[1] = 1;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = head[x]; i; i = nxt[i])
        {
            int y = ver[i];
            if (!d[y])
            {
                d[y] = d[x] + 1;
                fa[y][0] = x;
                for (int j = 1; j <= k; j++)
                {
                    fa[y][j] = fa[fa[y][j - 1]][j - 1];
                }
                q.push(y);
            }
        }
    }
}
int LCA(int x, int y)
{
    if (d[x] < d[y])
        swap(x, y);
    for (int i = k; i >= 0; i--)
        if (d[fa[x][i]] >= d[y])
            x = fa[x][i];
    if (x == y)
        return y;
    for (int i = k; i >= 0; i--)
        if (fa[x][i] != fa[y][i])
            x = fa[x][i], y = fa[y][i];
    return fa[x][0];
}
void DFS(int x)
{
    dfn[x] = ++num;
    for (int i = head[x]; i; i = nxt[i])
    {
        int y = ver[i];
        if (!dfn[y])
        {
            dis[y] = dis[x] + edge[i];
            DFS(y);
        }
    }
}
ll Path(int x, int y)
{
    //cout << x << "->" << y << endl;
    return dis[x] + dis[y] - 2 * dis[LCA(x, y)];
}
int main()
{
    scanf("%d", &n);
    for (int i = 0, x, y, z; i < n - 1; i++)
        scanf("%d%d%d", &x, &y, &z), add(x, y, z), add(y, x, z);
    BFS();
    dis[1] = 0;
    DFS(1);
    ll ans = 0;
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        char ch;
        int pos;
        cin >> ch;
        if (ch == '+')
        {
            scanf("%d", &pos);
            s.insert({pos});
            set<node>::iterator l, r;
            l = r = s.find({pos});
            if (r == --s.end())
                r = s.begin();
            else
                r++;
            if (l == s.begin())
                l = --s.end();
            else
                l--;
            ans -= Path((*l).id, (*r).id);
            ans += Path((*l).id, pos) + Path(pos, (*r).id);
        }
        else if (ch == '-')
        {
            scanf("%d", &pos);
            set<node>::iterator l, r;
            l = r = s.find({pos});
            if (r == --s.end())
                r = s.begin();
            else
                r++;
            if (l == s.begin())
                l = --s.end();
            else
                l--;
            s.erase({pos});
            ans -= Path((*l).id, pos) + Path(pos, (*r).id);
            ans += Path((*l).id, (*r).id);
        }
        else
        {
            cout << ans / 2 << endl;
        }
    }
    //system("pause");
    return 0;
}