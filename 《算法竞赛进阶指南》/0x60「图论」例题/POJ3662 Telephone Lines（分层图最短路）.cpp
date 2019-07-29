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
vector<pii> v[N * N];
bool vis[N * N];
int dis[N * N];
//dis[i] 1->i  路径上最长边的最短值
//分层图最短路 广义最短路
void SPFA()
{
    memset(dis, 0x3f, sizeof(dis));
    queue<int> q;
    //1:  1+0*n
    dis[1] = 0;
    vis[1] = 1;
    q.push(1);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        vis[x] = 0;
        for (int i = 0; i < v[x].size(); i++)
        {
            int y = v[x][i].first;
            int l = v[x][i].second;
            if (dis[y] > max(dis[x], l))
            {
                //转移
                dis[y] = max(dis[x], l);
                if (!vis[y])
                    q.push(y), vis[y] = 1;
            }
        }
    }
}
int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //cin >> n >> p >> k;
    scanf("%d%d%d", &n, &p, &k);
    int a, b, l;
    for (int i = 0; i < p; i++)
    {
        //cin >> a >> b >> l;
        scanf("%d%d%d", &a, &b, &l);
        //建立分层图
        for (int j = 0; j <= k; j++)
        {
            v[a + j * n].push_back({b + j * n, l});
            v[b + j * n].push_back({a + j * n, l});
        }
        for (int j = 0; j < k; j++)
        {
            v[a + j * n].push_back({b + (j + 1) * n, 0});
            v[b + j * n].push_back({a + (j + 1) * n, 0});
        }
    }
    SPFA();
    if (dis[n + k * n] == inf)
        cout << -1 << endl;
    else
        cout << dis[n + k * n] << endl;
    //system("pause");
    return 0;
}