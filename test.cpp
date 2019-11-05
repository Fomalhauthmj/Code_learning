#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 2000 + 10;
const int maxm = 10000 + 10;

int n, k;
int pre[maxn], id[maxn];
int dfn[maxn], cnt;
vector<pair<int, int>> edge[maxn];
bool vis[maxn];
vector<int> A, B;
map<int, int> tag;

void dfs(int u)
{
    dfn[u] = ++cnt;
    for (auto x : edge[u])
    {
        int v = x.first;
        if (v == pre[u])
            continue;
        if (dfn[v])
        {
            if (dfn[v] < dfn[u])
                continue;
            B.push_back(x.second);
            for (; v != u; v = pre[v])
                B.push_back(id[v]);
            continue;
        }
        pre[v] = u;
        id[v] = x.second;
        dfs(v);
    }
}

const int MAX_V = 10000 + 2000 + 10;
const int inf = 0x3f3f3f3f;
int res[maxn];

struct Dinic
{

    struct edge
    {
        int to, cap, rev;
    };
    vector<edge> G[MAX_V];
    int level[MAX_V];
    int iter[MAX_V];

    void add(int from, int to, int cap)
    {
        G[from].push_back((edge){to, cap, (int)G[to].size()});
        G[to].push_back((edge){from, 0, (int)G[from].size() - 1});
    }

    void bfs(int s)
    {
        memset(level, -1, sizeof level);
        queue<int> que;
        level[s] = 0;
        que.push(s);
        while (!que.empty())
        {
            int v = que.front();
            que.pop();
            for (int i = 0; i < G[v].size(); i++)
            {
                edge &e = G[v][i];
                if (e.cap > 0 && level[e.to] < 0)
                {
                    level[e.to] = level[v] + 1;
                    que.push(e.to);
                }
            }
        }
    }

    int dfs(int v, int t, int f)
    {
        if (v == t)
            return f;
        for (int &i = iter[v]; i < G[v].size(); i++)
        {
            edge &e = G[v][i];
            if (e.cap > 0 && level[v] < level[e.to])
            {
                int d = dfs(e.to, t, min(f, e.cap));
                if (d > 0)
                {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    int max_flow(int s, int t)
    {
        int flow = 0;
        for (;;)
        {
            bfs(s);
            if (level[t] < 0)
                return flow;
            memset(iter, 0, sizeof iter);
            int f;
            while ((f = dfs(s, t, inf)) > 0)
                flow += f;
        }
    }

    void getans()
    {
        for (int i = 1; i <= n; i++)
        {
            for (auto e : G[i])
            {
                if (e.to <= n)
                    continue;
                if (e.cap == 0)
                    res[i] = e.to - n;
            }
        }
    }
} dinic;

vector<int> P[maxm];
int pos[maxm];
pair<int, int> e[maxn];
int ans[maxn];

int main()
{
    int tot = 0;
    scanf("%d%d", &n, &k);
    int S = 0, T;
    for (int i = 1; i <= n; i++)
    {
        int u, k, x;
        scanf("%d%d", &u, &k);
        edge[i].push_back({u, i});
        edge[u].push_back({i, i});
        e[i] = make_pair(i, u);
        while (k--)
        {
            scanf("%d", &x);
            if (!tag[x])
                tag[x] = ++tot;
            dinic.add(i, tag[x] + n, 1);
        }
    }
    dfs(1);
    for (auto v : B)
        vis[v] = true;
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            A.push_back(i);
    /*
    T = n + tot + 1;
    for (int i = 1; i <= k; i++)
    {
        int x;
        scanf("%d", &x);
        if (!tag[x])
            continue;
        P[tag[x]].push_back(i);
    }
    for (int i = 1; i <= tot; i++)
        dinic.add(n + i, T, (int)P[i].size());
    for (auto x : A)
        dinic.add(S, x, 1);
    int cur = dinic.max_flow(S, T);
    if (cur < A.size())
        return 0 * puts("-1");
    for (auto x : B)
        dinic.add(S, x, 1);
    cur += dinic.max_flow(S, T);
    if (cur < n - 1)
        return 0 * puts("-1");
    dinic.getans();
    for (int i = 1; i <= n; i++)
    {
        if (pos[res[i]] == P[res[i]].size())
            continue;
        ans[P[res[i]][pos[res[i]]]] = i;
        pos[res[i]]++;
    }
    for (int i = 1; i <= k; i++)
    {
        if (ans[i] == 0)
            puts("0 0");
        else
            printf("%d %d\n", e[ans[i]].first, e[ans[i]].second);
    }
    */
    system("pause");
    return 0;
}