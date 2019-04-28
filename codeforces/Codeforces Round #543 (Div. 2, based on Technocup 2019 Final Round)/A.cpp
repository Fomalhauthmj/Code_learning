#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
#define N 105
int n, m, k; //m,k<=n
int p[N];    //power 各不相同
int s[N];    //school 1<=s[i]<=m
int c[N];    //只选择相同学校里p值最大 如果c[i]在其学校不能脱颖而出 伪造出一个新学校 使其为该学校内的唯一元素
//先按学校分别排序取最大 标记 然后检查未被选中的 伪造新学校
priority_queue<pair<int, int>> q[N]; //默认第一元素最大
bool vis[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n >> m >> k)
    {
        for (int i = 1; i <= n; i++)
            cin >> p[i];
        for (int i = 1; i <= n; i++)
            cin >> s[i];
        for (int i = 0; i < k; i++)
            cin >> c[i];
        for (int i = 1; i <= n; i++)
        {
            q[s[i]].push(make_pair(p[i], i)); //第一元素为p值
        }
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= m; i++)
        {
            if (!q[i].empty())
            {
                pair<int, int> now = q[i].top();
                vis[now.second] = 1;
            }
        }
        int ans = 0;
        for (int i = 0; i < k; i++)
        {
            if (!vis[c[i]])
                ans++;
        }
        cout << ans << endl;
    }
}