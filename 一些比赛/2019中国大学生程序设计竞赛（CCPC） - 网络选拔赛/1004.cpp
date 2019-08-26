#include <algorithm>
#include <iostream>
#include <queue>
#include <stdio.h>
#include <vector>
using namespace std;
#define ll long long
#define pii pair<int, int>
const int N = 1E5 + 50;
const int M = 1E5 + 50;
int n, m, ask[N];
ll ans[N];
vector<pii> v[N];
bool cmp(pii &p1, pii &p2)
{
    return p1.second < p2.second;
}
struct node
{
    int x, y, id;
    ll dis;
    bool operator<(const node &n) const
    {
        return dis > n.dis;
    }
};
int main()
{
    int T, q;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d", &n, &m, &q);
        for (int i = 1; i <= n; i++)
            v[i].clear();
        for (int i = 0, x, y, z; i < m; i++)
            scanf("%d%d%d", &x, &y, &z), v[x].push_back({y, z});
        priority_queue<node> pq;
        for (int i = 1; i <= n; i++)
            if (v[i].size())
            {
                sort(v[i].begin(), v[i].end(), cmp);
                pq.push({i, v[i][0].first, 0, v[i][0].second});
            }
        int max_k = 0;
        for (int i = 0; i < q; i++)
            scanf("%d", &ask[i]), max_k = max(max_k, ask[i]);
        int temp = 0;
        while (++temp <= max_k)
        {
            node now = pq.top();
            pq.pop();
            ans[temp] = now.dis;
            int x = now.x, y = now.y, id = now.id;
            if (id + 1 < v[x].size())
                pq.push({x, v[x][id + 1].first, id + 1, now.dis - v[x][id].second + v[x][id + 1].second});
            if (v[y].size())
                pq.push({y, v[y][0].first, 0, now.dis + v[y][0].second});
        }
        for (int i = 0; i < q; i++)
            printf("%lld\n", ans[ask[i]]);
    }
    //system("pause");
    return 0;
}