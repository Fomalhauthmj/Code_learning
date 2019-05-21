//https://www.luogu.org/problemnew/show/P2863
//Tarjan 强连通分量
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
const int N = 10500;
vector<int> G[N];
bool vis[N];
int dfn[N];
int low[N];
int cnt;
stack<int> s;
int n, m;
void init()
{
    memset(vis, 0, sizeof(vis));
    memset(dfn, 0, sizeof(dfn));
    cnt = 0;
}
int result;
void DFS(int cur)
{
    dfn[cur] = low[cur] = ++cnt;
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
        result = 0;
        while (1)
        {
            int t = s.top();
            s.pop();
            vis[t] = 0;
            result++;
            if (t == cur)
                break;
        }
        //cout << cur << " " << result << endl;
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
    int ans = 0;
    init();
    for (int i = 1; i <= n; i++)
    {
        if (!dfn[i])
        {
            DFS(i);
            if (result > 1)
                ans++;
        }
    }
    cout << ans << endl;
    //system("pause");
    return 0;
}