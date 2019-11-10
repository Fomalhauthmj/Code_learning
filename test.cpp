#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 50;
vector<int> G[N];
int pre[N], nxt[N];
vector<int> ans;
int tag[N], n, m;
void BFS(int start)
{
    queue<int> q;
    q.push(start);
    int cnt = 0;
    while (q.size())
    {
        int x = q.front();
        q.pop();
        cnt++;
        for (auto y : G[x])
            tag[y] = x;
        for (int i = nxt[0]; i <= n; i = nxt[i])
        {
            if (i != start && tag[i] != x)
                q.push(i), nxt[pre[i]] = nxt[i], pre[nxt[i]] = pre[i];
        }
    }
    ans.push_back(cnt);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0, u, v; i < m; i++)
    {
        cin >> u >> v;
        G[u].push_back(v), G[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        pre[i] = i - 1, nxt[i] = i + 1;
    nxt[0] = 1, pre[n + 1] = n;
    for (int i = nxt[0]; i <= n;)
    {
        BFS(i);
        int nxt_p = nxt[i];
        nxt[pre[i]] = nxt[i], pre[nxt[i]] = pre[i];
        i = nxt_p;
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto it : ans)
        cout << it << " ";
    cout << endl;
    //system("pause");
    return 0;
}