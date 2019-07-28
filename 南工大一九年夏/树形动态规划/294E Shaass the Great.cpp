//http://codeforces.com/problemset/problem/294/E
#include <cstring>
#include <iostream>
#include <math.h>
using namespace std;
const int N = 5005;
#define inf 0x3f3f3f3f3f3f3f3f
#define ll long long
ll head[N], nxt[2 * N], ver[2 * N], edge[2 * N], tot = 0, n;
void add(ll u, ll v, ll w)
{
    ver[++tot] = v;
    nxt[tot] = head[u];
    head[u] = tot;
    edge[tot] = w;
}
/*
枚举删除边？ 如何确定新添边的影响？
 */
ll sze[N]; //sze[rt] 以rt为根的子树大小
ll cut1, cut2;
ll dp[N]; //dp[rt] 表示以rt为根的子树 子树内所有结点到rt的距离和
ll sum, min_dp;
void DFS_1(ll rt, ll pa)
{
    sze[rt] = 1;
    dp[rt]=0;
    for (ll i = head[rt]; i; i = nxt[i])
    {
        ll y = ver[i];
        if (y != pa)
        {
            DFS_1(y, rt);
            dp[rt] += dp[y] + sze[y] * edge[i];
            sze[rt] += sze[y];
        }
    }
}
void DFS_2(ll rt, ll pa, ll subtree_n)
{
    sum += dp[rt];
    min_dp = min(min_dp, dp[rt]);
    for (ll i = head[rt]; i; i = nxt[i])
    {
        ll y = ver[i];
        if (y != pa)
        {
            dp[y] = dp[rt] + edge[i] * (subtree_n - sze[y]) - edge[i] * sze[y];
            DFS_2(y, rt, subtree_n);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    ll u, v, w;
    for (ll i = 0; i < n - 1; i++)
        cin >> u >> v >> w, add(u, v, w), add(v, u, w);
    ll ans = inf;
    for (ll i = 1; i <= tot; i += 2)
    {
        cut1 = ver[i], cut2 = ver[i + 1];
        DFS_1(cut1, cut2);
        sum = 0, min_dp = inf;
        DFS_2(cut1, cut2, sze[cut1]);
        ll choose_1 = min_dp;
        ll sum1 = sum / 2;
        DFS_1(cut2, cut1);
        sum = 0, min_dp = inf;
        DFS_2(cut2, cut1, sze[cut2]);
        ll choose_2 = min_dp;
        ll sum2 = sum / 2;
        ans = min(ans, sum1 + sum2 + choose_1 * sze[cut2] + choose_2 * sze[cut1] + sze[cut1] * sze[cut2] * edge[i]);
    }
    cout << ans << endl;
    //system("pause");
    return 0;
}