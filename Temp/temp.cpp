#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int x1, y1, z1, x2, y2, z2;
    scanf("%d.%d.%d %d.%d.%d", &x1, &y1, &z1, &x2, &y2, &z2);
    ll ans = 1ll * (x1 + x2) * 17 * 29 + (y1 + y2) * 29 + z1 + z2;
    printf("%lld.%lld.%lld\n", ans / 29 / 17, ans / 29 % 17, ans % 29);
    vector<int> v;
    deque<int> d;
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}