//https://www.luogu.org/problemnew/show/P2341
//Tarjan 强连通分量缩点DAG
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
#define N 10010
vector<int> G[N];
int n, m;
bool vis[N];
stack<int> s;
int dfn[N];
int low[N];
int color[N];
int outdegree[N];
int pnum[N];
int cnt;
int sum;
void init()
{
    memset(dfn, 0, sizeof(dfn));
    memset(vis, 0, sizeof(vis));
    memset(outdegree, 0, sizeof(outdegree));
    memset(pnum, 0, sizeof(pnum));
    cnt = sum = 0;
}
void DFS(int cur)
{
    dfn[cur] = low[cur] = ++cnt;
    //这里++cnt 从1开始 如果从0开始 WA
    s.push(cur);
    vis[cur] = 1;
    for (auto ele : G[cur])
    {
        if (!dfn[ele])
        {
            DFS(ele);
            low[cur] = min(low[cur], low[ele]);
        }
        else if (vis[ele])
        {
            low[cur] = min(low[cur], dfn[ele]);
        }
    }
    if (dfn[cur] == low[cur])
    {
        sum++;
        while (1)
        {
            int t = s.top();
            s.pop();
            color[t] = sum;
            pnum[sum]++;
            vis[t] = 0;
            if (t == cur)
                break;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        G[u].push_back(v);
    }
    init();
    for (int i = 1; i <= n; i++)
    {
        if (!dfn[i])
        {
            DFS(i);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (auto ele : G[i])
        {
            if (color[ele] != color[i])
            {
                outdegree[color[i]]++;
            }
        }
    }
    int group = 0;
    int ans;
    for (int i = 1; i <= sum; i++)
    {
        if (!outdegree[i])
        {
            group++;
            ans = pnum[i];
        }
    }
    if (group != 1)
    {
        cout << 0 << endl;
    }
    else
        cout << ans << endl;
    system("pause");
    return 0;
}