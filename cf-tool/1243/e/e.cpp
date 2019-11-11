/* 
 * Author: Hemengjie
 * Time: 2019-11-11 14:51:13
**/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 80000;
int a[16][5050];
int k;
ll sum[16], n[16];
map<ll, int> Color;
int dp[1 << 16];
struct record
{
    ll c;
    int p;
    bool operator<(const record &r) const
    {
        return c < r.c;
    }
};
vector<pair<int, record>> ans[1 << 16];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> k;
    ll S = 0;
    for (int i = 1; i <= k; i++)
    {
        cin >> n[i];
        sum[i] = 0;
        for (int j = 1; j <= n[i]; j++)
        {
            cin >> a[i][j], sum[i] += a[i][j], Color[a[i][j]] = i - 1;
        }
        S += sum[i];
    }
    if (S % k)
    {
        cout << "No" << endl;
        return 0;
    }
    S /= k;
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= n[i]; j++)
        {
            ll cur = a[i][j];
            bool isOk = true;
            int state = 0;
            vector<pair<int, record>> temp;
            do
            {
                int cur_box = 0;
                auto it = Color.find(cur);
                if (it != Color.end())
                    cur_box = it->second;
                else
                {
                    isOk = false;
                    break;
                }
                if (state & (1 << cur_box))
                {
                    isOk = false;
                    break;
                }
                state |= (1 << cur_box);
                cur = S - sum[cur_box + 1] + cur;
                auto nxt = Color.find(cur);
                if (nxt != Color.end())
                    temp.push_back({nxt->second + 1, {cur, cur_box + 1}});
            } while (cur != a[i][j]);
            if (isOk)
                ans[state] = temp, dp[state] = 1;
        }
    }
    for (int i = 0; i < (1 << k); i++)
    {
        if (dp[i])
            continue;
        for (int j = i; j; j = (j - 1) & i)
        {
            int rest = i & (~j);
            if (dp[j] && dp[rest])
            {
                dp[i] = 1, ans[i] = ans[j];
                for (auto it : ans[rest])
                    ans[i].push_back(it);
                break;
            }
        }
    }
    int target = (1 << k) - 1;
    if (dp[target])
    {
        cout << "Yes" << endl;
        sort(ans[target].begin(), ans[target].end());
        for (auto it : ans[target])
            cout << it.second.c << " " << it.second.p << endl;
    }
    else
        cout << "No" << endl;
    //system("pause");
    return 0;
}