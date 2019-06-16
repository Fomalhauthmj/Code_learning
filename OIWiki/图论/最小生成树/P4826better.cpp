//https://www.luogu.org/problemnew/show/P4826
#include <iostream>
using namespace std;
#define ll long long
#define N 2050
bool vis[N];
ll dis[N];
ll id[N];
int n;
ll Prim()
{
    int cnt = n;
    int pos;
    ll ans = 0;
    while (cnt--)
    {
        pos = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i] && dis[i] >= dis[pos])
            {
                pos = i;
            }
        }
        vis[pos] = 1;
        ans += dis[pos];
        //cout << pos << " " << ans << endl;
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i] && dis[i] < (id[pos] ^ id[i]))
                dis[i] = id[pos] ^ id[i]; //最大生成树
        }
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> id[i];
    }
    cout << Prim() << endl;
    //system("pause");
    return 0;
}