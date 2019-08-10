#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int N = 55;
vector<int> v[N];
bool vis[N];
int n, m, match[N];
bool DFS(int x)
{
    for (int i = 0; i < v[x].size(); i++)
    {
        int y = v[x][i];
        if (!vis[y])
        {
            vis[y] = 1;
            if (!match[y] || DFS(match[y]))
            {
                match[y] = x;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    cin >> n >> m;
    char ch;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> ch;
            if (ch == '*')
                v[i].push_back(j);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        memset(vis, 0, sizeof(vis));
        if (DFS(i))
            ans++;
    }
    cout << ans << endl;
    system("pause");
}