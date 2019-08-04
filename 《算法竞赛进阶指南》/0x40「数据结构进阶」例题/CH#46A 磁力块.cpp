#include <algorithm>
#include <iostream>
#include <math.h>
#include <queue>
#include <stdio.h>
#define pii pair<int, int>
#define ll long long
using namespace std;
const ll N = 2.5E5 + 50;
ll X0, Y0, pl, rl, n, t;
struct node
{
    ll x, y, m, p, r;
    double dis;
    inline void distance()
    {
        ll t1 = (x - X0) * (x - X0);
        ll t2 = (y - Y0) * (y - Y0);
        dis = sqrt(t1 + t2);
    }
} a[N];
ll L[N], R[N], pos[N], weight[N];
bool vis[N];
bool cmp_m(node &n1, node &n2)
{
    return n1.m < n2.m;
}
bool cmp_d(node &n1, node &n2)
{
    return n1.dis < n2.dis;
}
ll BFS()
{
    queue<pii> q;
    ll ans = 0;
    q.push({pl, rl});
    while (!q.empty())
    {
        pii now = q.front();
        q.pop();
        for (ll i = 1; i <= t; i++)
        {
            if (weight[i] <= now.first)
            {
                for (ll j = pos[i]; j <= R[i]; j++)
                {
                    if (a[j].dis <= now.second)
                    {
                        if(!vis[j])
                        {
                            ans++;
                            vis[j] = 1;
                            q.push({a[j].p, a[j].r});
                            pos[i]++;
                        }
                    }
                    else break;
                }
            }
            else
            {
                for (ll j = L[i]; j <= R[i]; j++)
                {
                    if (!vis[j] && a[j].m <= now.first && a[j].dis <= now.second)
                    {
                        vis[j] = 1;
                        ans++;
                        q.push({a[j].p, a[j].r});
                    }
                }
                break;
            }
        }
    }
    return ans;
}
int main()
{
    cin >> X0 >> Y0 >> pl >> rl >> n;
    for (ll i = 1; i <= n; i++)
        scanf("%lld%lld%lld%lld%lld", &a[i].x, &a[i].y, &a[i].m, &a[i].p, &a[i].r), a[i].distance();
    sort(a + 1, a + 1 + n, cmp_m);
    t = sqrt(n) + 1;
    ll len = n / t;
    for (ll i = 1; i <= t; i++)
        L[i] = (i - 1) * len + 1, R[i] = i * len;
    if (R[t] < n)
        t++, L[t] = R[t - 1] + 1, R[t] = n;
    //按质量分块
    for (ll i = 1; i <= t; i++)
    {
        pos[i] = L[i];
        weight[i] = a[R[i]].m;
        sort(a + L[i], a + R[i] + 1, cmp_d);
        //块内部按距离排序
    }
    cout << BFS() << endl;
    system("pause");
    return 0;
}