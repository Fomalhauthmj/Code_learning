/*
    网络流
        最大流问题
*/
//https://www.luogu.org/problemnew/show/P3376
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define ll int
#define inf 0x3f3f3f3f
const int M = 10500;
//MLE
ll origin[M][M];
int pre[M];
ll flow[M];
int n, m, s, t;
ll BFS(int s, int t)
{
    queue<int> q;
    memset(pre, -1, sizeof(pre));
    flow[s] = inf;
    pre[s] = 0;
    q.push(s);
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        if (now == t)
        {
            break;
        }
        for (int i = 1; i <= n; i++)
        {
            if (origin[now][i] > 0 && pre[i] == -1)
            {
                pre[i] = now;
                flow[i] = min(origin[now][i], flow[now]);
                q.push(i);
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
            origin[last][k] -= inc;
            origin[k][last] += inc;
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
    cin >> n >> m >> s >> t;
    memset(origin, 0, sizeof(origin));
    ll si, ei, ci;
    for (int i = 0; i < m; i++)
    {
        cin >> si >> ei >> ci;
        origin[si][ei] += ci;
    }
    cout << Edmonds_Karp(s, t) << endl;
    //system("pause");
    return 0;
}