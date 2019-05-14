#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define inf 0x3f3f3f3f
const int N = 2e5 + 20;
struct node
{
    long long u, v, w;
    node(int uu, int vv, int ww) : u(uu), v(vv), w(ww)
    {
    }
    bool operator<(node n) const
    {
        return w > n.w;
    }
};
long long n, m;
priority_queue<node> q;
vector<pair<long long, long long>> G[N];
bool vis[N];
long long Prim()
{
    long long ans = 0;
    for (auto ele : G[1])
    {
        q.push(node(1, ele.first, ele.second));
    }
    memset(vis, 0, sizeof(vis));
    vis[1] = 1;
    int t = n - 1;
    while (t--)
    {
        node top = q.top();
        q.pop();
        while (vis[top.v])
        {
            top = q.top();
            q.pop();
        }
        ans += top.w;
        vis[top.v] = 1;
        for (auto ele : G[top.v])
        {
            q.push(node(top.v, ele.first, ele.second));
        }
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    long long u, v, w;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        G[u].push_back(make_pair(v, w));
        G[v].push_back(make_pair(u, w));
    }
    cout << Prim() << endl;
    //system("pause");
    return 0;
}