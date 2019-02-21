#include <iostream>
#include <map>
#include <vector>
using namespace std;
#define N 300030
int a[N];
vector<int> V[N];
int n;
map<pair<int, int>, int> M;
bool DFS(int from, int to, int cur)
{
    pair<int, int> p1, p2;
    p1.first = from, p1.second = to;
    p2.first = to, p2.second = from;
    int temp1 = M[p1];
    int temp2 = M[p2];
    /*
    if (temp1 != 0)
    {
        if (temp1 == 1)
            return true;
        else
            return false;
    }
    if (temp2 != 0)
    {
        if (temp2 == 1)
            return true;
        else
            return false;
    }
    */
    for (auto ele : V[to])
    {
        if (ele == from)
            continue;
        if (cur == 0 && a[ele] != 0)
        {
            cur = a[ele];
        }
        if (cur != 0 && a[ele] != 0 && a[ele] != cur)
        {
            M[p1] = 2;
            M[p2] = 2;
            return false;
        }
        if (!DFS(to, ele, cur))
            return false;
    }
    M[p1] = 1;
    M[p2] = 1;
    return true;
}
bool judge(int from, int to)
{
    for (auto ele : V[from])
    {
        if (ele == to)
            continue;
        if (!DFS(from, ele, a[from]))
        {
            return false;
        }
    }
    for (auto ele : V[to])
    {
        if (ele == from)
            continue;
        if (!DFS(to, ele, a[to]))
        {
            return false;
        }
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++)
            V[i].clear();
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        int u, v;
        for (int i = 0; i < n - 1; i++)
        {
            cin >> u >> v;
            V[u].push_back(v);
            V[v].push_back(u); //建图
        }
        int ans = 0;
        M.clear();
        for (int i = 1; i <= n; i++)
        {
            for (auto ele : V[i]) //枚举删除边
            {
                if (i < ele)
                {
                    if (judge(i, ele))
                        ans++;
                }
            }
        }
        cout << ans << endl;
    }
}