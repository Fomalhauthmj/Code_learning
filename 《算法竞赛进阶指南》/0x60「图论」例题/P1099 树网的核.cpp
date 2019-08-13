#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int N = 5e5 + 500;
//小数据可行 大数据段错误
//FIXME 完善其他方法
#define pii pair<int, int>
#define inf 0x3f3f3f3f
int n, s, dis[N], path[N], d[N];
vector<pii> v[N];
vector<int> diameter;
bool vis[N];
void DFS(int x)
{
    vis[x] = 1;
    for (int i = 0; i < v[x].size(); i++)
    {
        int y = v[x][i].first;
        int z = v[x][i].second;
        if (!vis[y])
        {
            DFS(y);
            d[x] = max(d[x], d[y] + z);
        }
    }
}
int BFS(int start, bool record_path)
{
    queue<int> q;
    q.push(start), dis[start] = 0;
    memset(vis, 0, sizeof(vis));
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        vis[x] = 1;
        for (int i = 0; i < v[x].size(); i++)
        {
            int y = v[x][i].first, z = v[x][i].second;
            if (!vis[y])
            {
                dis[y] = dis[x] + z;
                if (record_path)
                    path[y] = x;
                q.push(y);
            }
        }
    }
    int temp = 0;
    for (int i = 1; i <= n; i++)
        if (!temp || dis[i] > dis[temp])
            temp = i;
    return temp;
}
int Solve()
{
    int u = BFS(1, false);
    int v = BFS(u, true);
    //(u,v) 直径 枚举计算
    memset(vis, 0, sizeof(vis));
    int temp = v;
    while (temp)
    {
        diameter.push_back(temp);
        vis[temp] = 1;
        temp = path[temp];
    }
    for (int i = 0; i < diameter.size(); i++)
        DFS(diameter[i]); //树形DP
    temp = 0;
    for (int i = 0; i < diameter.size(); i++)
        temp = max(temp, d[diameter[i]]);
    int ans = inf;
    int j = 0;
    for (int i = 0; i < diameter.size(); i++)
    {
        int x = diameter[i];
        while (j < diameter.size() && dis[x] - dis[diameter[j]] <= s)
            j++;
        int y = diameter[j - 1];
        ans = min(ans, max(temp, max(dis[v] - dis[x], dis[y])));
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> s;
    int x, y, z;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> x >> y >> z;
        v[x].push_back(make_pair(y, z));
        v[y].push_back(make_pair(x, z));
    }
    cout << Solve() << endl;
    //system("pause");
    return 0;
}