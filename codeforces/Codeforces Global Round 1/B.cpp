#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
#define N 100010
long long n, m, k;
int seg[N];
bool vis[N];
struct node
{
    long long left;
    int index;
};
node ns[N];
bool cmp(node &n1, node &n2)
{
    return n1.left < n2.left;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n >> m >> k)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> seg[i];
            if (i != 0)
            {
                ns[i].left = seg[i] - seg[i - 1];
                ns[i].index = i;
            }
        }
        //k==n ans=n
        //k<n ans=? 显然ans<=m
        sort(ns + 1, ns + n, cmp);
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i < 1 + n - k; i++)
        {
            vis[ns[i].index] = 1;
        }
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (vis[i])
            {
                ans += seg[i] - seg[i - 1];
            }
            else
            {
                ans++;
            }
        }
        if (ans > m)
            ans = m;
        cout << ans << endl;
    }
}