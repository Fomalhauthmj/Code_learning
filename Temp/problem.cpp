#include <iostream>
#include <map>
#include <stdio.h>
using namespace std;
#define ll long long
const int N = 1e4 + 50;
ll a[N], b[N];
bool vis[N];
int n;
map<ll, int> M;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]), M[a[i]]++;
    for (int i = 1; i <= n; i++)
        scanf("%lld", &b[i]);
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (M[a[i]] > 1)
            ans += b[i], vis[i] = true;
    }
    //cout << "before" << ans << endl;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            for (int j = 1; j <= n; j++)
            {
                if (vis[j] && (a[i] | a[j]) == a[j])
                {
                    ans += b[i];
                    vis[i] = true;
                    break;
                }
            }
        }
    }
    printf("%lld\n", ans);
    //system("pause");
    return 0;
}