//http://codeforces.com/problemset/problem/486/D
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
const int N = 2005;
int a[N], d, n;
vector<int> son[N];
bool vis[N];
ll dp[N];
/*
枚举rt作为最小或最大 n遍O(n)的DFS 注意重复计数
 */
void DP(int rt, int min_a)
{
    vis[rt] = 1;
    dp[rt] = 1;
    for (int i = 0; i < son[rt].size(); i++)
    {
        int s = son[rt][i];
        if (!vis[s])
        {
            if (a[s] >= a[min_a] && a[min_a] + d >= a[s])
            {
                if (a[min_a] == a[s] && min_a < s)
                    continue;
                DP(s,min_a);
                dp[rt] = (dp[s] + 1) * dp[rt] % mod;
                //选或不选
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> d >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int u, v;
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> u >> v;
        son[u].push_back(v);
        son[v].push_back(u);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        memset(vis, 0, sizeof(vis));
        DP(i, i);
        ans = (ans + dp[i]) % mod;
    }
    cout << ans << endl;
    //system("pause");
    return 0;
}