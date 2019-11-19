/* 
 * Author: Hemengjie
 * Time: 2019-11-19 16:10:44
**/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 50;
#define inf 0x3f3f3f3f
vector<int> V[N];
struct node
{
    int minp, maxp;
} temp;
vector<node> ret;
bool vis[N];
void DFS(int x)
{
    vis[x] = 1;
    temp.minp = min(temp.minp, x);
    temp.maxp = max(temp.maxp, x);
    for (int y : V[x])
    {
        if (!vis[y])
            DFS(y);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0, u, v; i < m; i++)
        cin >> u >> v, V[u].push_back(v), V[v].push_back(u);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            temp = {i, i};
            DFS(i);
            ret.push_back(temp);
        }
    }
    int ans = 0;
    int max_r=-1;
    for(auto it:ret)
    {
        if(it.minp<=max_r) ans++;
        max_r=max(max_r,it.maxp);
    }
    cout << ans << endl;
    //system("pause");
    return 0;
}