//http://codeforces.com/problemset/problem/486/D
// TODO 2300
#include <iostream>
#include <vector>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
const int N = 2005;
int a[N], d, n;
vector<int> son[N];
bool vis[N];
ll dp[N][3];
/*
dp[rt][0] rt为根的子树中最大值
dp[rt][1] rt为根的子树中最小值

dp[rt][dis]
 */
void DP(int rt)
{
    vis[rt] = 1;
    dp[rt][0] = dp[rt][1] = a[rt];
    dp[rt][2] = 1;
    for (int i = 0; i < son[rt].size(); i++)
    {
        int s = son[rt][i];
        if (!vis[s])
        {
            DP(s);
            dp[rt][0] = max(dp[rt][0], dp[s][0]);
            dp[rt][1] = min(dp[rt][1], dp[s][1]);
            if (dp[rt][0] - dp[s][1] <= d && dp[s][0] - dp[rt][1] <= d)
                dp[rt][2] = dp[rt][2] * dp[s][2];
        }
    }
    //cout << "rt: " << rt << " " << dp[rt][0] << " " << dp[rt][1] << endl;
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
    DP(1);
    cout << dp[1][2] << endl;
    system("pause");
    return 0;
}