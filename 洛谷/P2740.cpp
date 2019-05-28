//https://www.luogu.org/problemnew/show/P2740
//网络流
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f
const int M = 205;
ll origin[M][M];
bool vis[M];
int n, m;
ll ans;
vector<pair<int, ll>> V[M];
bool in_stack[M];
int dfn[M];
int low[M];
int color[M];
int cnt, sum;
stack<int> s;
void DFS(int cur, ll val)
{
    vis[cur] = 1;
    if (cur == color[m])
    {
        ans += val;
        return;
    }
    for (auto ele : V[cur])
    {
        if (!vis[ele.first])
        {
            DFS(ele.first, min(val, ele.second));
            vis[ele.first] = 0;
        }
    }
}
void Init()
{
    cnt = sum = 0;
    memset(in_stack, 0, sizeof(in_stack));
    memset(dfn, 0, sizeof(dfn));
}
void Tarjan(int cur)
{
    dfn[cur] = low[cur] = ++cnt;
    in_stack[cur] = 1;
    s.push(cur);
    for (int i = 1; i <= m; i++)
    {
        if (origin[cur][i] != inf)
        {
            if (!dfn[i])
            {
                Tarjan(i);
                low[cur] = min(low[cur], low[i]);
            }
            else if (in_stack[i])
            {
                low[cur] = min(low[cur], dfn[i]);
            }
        }
    }
    if (dfn[cur] == low[cur])
    {
        ++sum;
        while (1)
        {
            int now = s.top();
            s.pop();
            in_stack[now] = 0;
            color[now] = sum;
            if (now == cur)
                break;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            origin[i][j] = inf;
        }
    }
    ll si, ei, ci;
    for (int i = 0; i < n; i++)
    {
        cin >> si >> ei >> ci;
        if (origin[si][ei] == inf)
        {
            origin[si][ei] = ci;
        }
        else
            origin[si][ei] += ci;
    }
    Init();
    for (int i = 1; i <= m; i++)
    {
        if (!dfn[i])
        {
            Tarjan(i);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (origin[i][j] != inf && color[i] != color[j])
            {
                V[color[i]].push_back(make_pair(color[j], origin[i][j]));
            }
        }
    }
    ans = 0;
    memset(vis, 0, sizeof(vis));
    DFS(color[1], inf);
    cout << ans << endl;
    //system("pause");
    return 0;
}