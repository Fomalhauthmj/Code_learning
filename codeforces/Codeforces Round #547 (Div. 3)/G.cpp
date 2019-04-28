#include <cstring>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
#define N 200050
int n, k;
vector<int> V[N];
vector<pair<int, int>> E;
map<pair<int, int>, int> M;
bool judge(int mid)
{
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        if (V[i].size() > mid)
        {
            temp++;
            if (temp > k)
                return false;
        }
    }
    return true;
}
bool vis[N];
int ans;
void DFS(int from, int pre_c)
{
    vis[from] = 1;
    int c = 1;
    for (auto to : V[from])
    {
        if (!vis[to])
        {
            if (pre_c == c)
            {
                c = c % ans + 1;
            }
            M[make_pair(from, to)] = c;
            M[make_pair(to, from)] = c;
            //cout << from << "->" << to << " : " << c << endl;
            DFS(to, c);
            c = c % ans + 1;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    int u, v;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        E.push_back(make_pair(u, v));
        //边集
        V[u].push_back(v);
        V[v].push_back(u);
        //无向图
    }
    //二分或贪心
    int left = 1;
    int right = n - 1;
    int mid;
    ans = n - 1;
    while (left <= right)
    {
        mid = (left + right) / 2;
        //cout << "cur:" << mid << endl;
        if (judge(mid))
        {
            if (ans == mid)
                break;
            ans = mid;
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    cout << ans << endl;
    //如何构造？
    memset(vis, 0, sizeof(vis));
    DFS(1, 0);
    //DFS遍历
    for (auto ele : E)
    {
        cout << M[ele] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}