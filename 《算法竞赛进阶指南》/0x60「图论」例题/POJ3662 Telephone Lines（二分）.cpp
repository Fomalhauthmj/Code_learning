#include <cstring>
#include <iostream>
#include <queue>
#include <stdio.h>
#include <vector>
using namespace std;
#define pii pair<int, int>
#define inf 0x3f3f3f3f
const int N = 1050;
int n, p, k;
vector<pii> v[N];
bool vis[N];
int dis[N];
bool Judge(int mid)
{
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    deque<int> q;
    dis[1] = 0;
    q.push_front(1);
    while (!q.empty())
    {
        int x = q.front();
        q.pop_front();
        if (vis[x])
            continue;
        vis[x] = 1;
        for (int i = 0; i < v[x].size(); i++)
        {
            int y = v[x][i].first;
            int l = v[x][i].second;
            if (!vis[y])
            {
                int temp = (l > mid) ? 1 : 0;
                if (dis[y] > dis[x] + temp)
                {
                    dis[y] = dis[x] + temp;
                    if (temp)
                        q.push_back(y);
                    else
                        q.push_front(y);
                }
            }
        }
    }
    return dis[n] <= k;
}
int main()
{
    scanf("%d%d%d", &n, &p, &k);
    int a, b, l;
    int max_l = 0;
    for (int i = 0; i < p; i++)
    {
        scanf("%d%d%d", &a, &b, &l);
        v[a].push_back({b, l});
        v[b].push_back({a, l});
        max_l = max(max_l, l);
    }
    if (!Judge(max_l))
    {
        cout << -1 << endl;
        //不连通
        return 0;
    }
    int left = 0;
    int right = max_l;
    int mid;
    while (left < right)
    {
        mid = (left + right) >> 1;
        //cout << "cur:" << mid << endl;
        if (Judge(mid))
        {
            right = mid;
        }
        else
            left = mid + 1;
    }
    cout << left << endl;
    //system("pause");
    return 0;
}