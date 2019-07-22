#include <algorithm>
#include <iostream>
using namespace std;
#define ll long long
const int N = 20;
ll n, w;
ll c[N], wei[N];
int ans = 20;
void DFS(int now, int cnt)
{
    if (cnt >= ans)
        return;
    if (now >= n)
    {
        ans = min(ans, cnt);
        return;
    }
    for (int i = 1; i <= cnt; i++)
    {
        if (wei[i] + c[now] <= w)
        {
            wei[i] += c[now];
            DFS(now + 1, cnt);
            wei[i] -= c[now];
        }
    }
    wei[cnt + 1] = c[now];
    DFS(now + 1, cnt + 1);
    wei[cnt + 1] = 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> w;
    for (int i = 0; i < n; i++)
        cin >> c[i];
    sort(c, c + n, greater<ll>());
    DFS(0, 0);
    cout << ans << endl;
    //system("pause");
    return 0;
}