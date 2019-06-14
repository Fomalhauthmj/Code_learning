/*
    网络流
        最大流问题
*/
//https://www.luogu.org/problemnew/show/P2740
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f
const int M = 205;
ll c[M][M];
int pre[M];
ll flow[M];
int n, m;
ll BFS(int s, int t)
{
    queue<int> q;
    memset(pre, -1, sizeof(pre));
    flow[s] = inf;
    pre[s] = 0;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (u == t)
        {
            break;
        }
        for (int v = 1; v <= m; v++)
        {
            if (c[u][v] > 0 && pre[v] == -1&&v!=s)
            {
                pre[v] = u;
                flow[v] = min(c[u][v], flow[u]);
                q.push(v);
            }
        }
    }
    if (pre[t] == -1)
        return -1;
    return flow[t];
}
ll Edmonds_Karp(int s, int t)
{
    ll inc;
    ll ans = 0;
    int k, last;
    while ((inc = BFS(s, t)) != -1)
    {
        k = t;
        while (k != s)
        {
            last = pre[k];
            c[last][k] -= inc;
            c[k][last] += inc;
            k = last;
        }
        ans += inc;
        //cout<<"cur:"<<inc<<endl;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    memset(c, 0, sizeof(c));
    ll si, ei, ci;
    for (int i = 0; i < n; i++)
    {
        cin >> si >> ei >> ci;
        c[si][ei] += ci;
    }
    cout << Edmonds_Karp(1, m) << endl;
    //system("pause");
    return 0;
}