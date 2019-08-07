#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int N = 305;
//小数据可行 大数据段错误  
//FIXME 完善其他方法
#define pii pair<int, int>
#define inf 0x3f3f3f3f
int n, s, dis[N], path[N], temp_ecc, dis_to_core[N];
vector<pii> v[N];
vector<int> diameter;
bool tag[N], vis[N];
void DFS(int x)
{
    temp_ecc = max(temp_ecc, dis_to_core[x]);
    vis[x] = 1;
    for (auto it : v[x])
    {
        int y = it.first;
        int z = it.second;
        if (!vis[y] && !tag[y])
        {
            dis_to_core[y] = dis_to_core[x] + z;
            DFS(y);
        }
    }
}
int Calc(int p, int q)
{
    memset(tag, 0, sizeof(tag));
    //标记p,q路径上的点
    int temp = p;
    bool flag = false;
    while (temp)
    {
        if (temp == q)
        {
            flag = true;
            break;
        }
        temp = path[temp];
    }
    if (flag)
    {
        temp = p;
        while (temp)
        {
            tag[temp] = 1;
            if (temp == q)
                break;
            temp = path[temp];
        }
    }
    else
    {
        temp = q;
        while (temp)
        {
            tag[temp] = 1;
            if (temp == p)
                break;
            temp = path[temp];
        }
    }
    temp_ecc = 0;
    memset(vis,0,sizeof(vis));
    for (int i = 1; i <= n; i++)
    {
        if (tag[i])
        {
            //核上的点
            dis_to_core[i]=0;
            DFS(i);
        }
    }
    return temp_ecc;
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
        for (auto it : v[x])
        {
            int y = it.first, z = it.second;
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
    int temp = v;
    while (temp)
    {
        diameter.push_back(temp);
        temp = path[temp];
    }
    int ans = inf;
    for (int i = 0; i < diameter.size(); i++)
    {
        for (int j = 0; j < diameter.size(); j++)
        {
            int p = diameter[i], q = diameter[j];
            if (p <= q && abs(dis[p] - dis[q]) <= s)
            {
                //cout<<p<<" "<<q<<endl;
                //p->q 的路径作为核
                ans = min(ans, Calc(p, q));
            }
        }
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
        v[x].push_back({y, z});
        v[y].push_back({x, z});
    }
    cout << Solve() << endl;
    system("pause");
    return 0;
}