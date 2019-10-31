/* 
 * Author: Hemengjie
 * Time: 2019-10-31 19:40:29
**/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const int N = 1e5 + 50;
#define pii pair<ll, ll>
pii land[N];
bool cmp(pii &p1, pii &p2)
{
    if (p1.first != p2.first)
        return p1.first > p2.first;
    return p1.second < p2.second;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ld ans = 0;
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld%lld", &land[i].first, &land[i].second);
        ld area = land[i].first * land[i].second / 2.0;
        ans = max(ans, area);
        if (land[i].first > land[i].second)
            swap(land[i].first, land[i].second);
    }
    sort(land + 1, land + 1 + n, cmp);
    ld temp = 0;
    ll wj = land[1].second;
    for (int i = 2; i <= n; i++)
    {
        temp = max(temp, (ld)land[i].first * min(land[i].second, wj));
        wj = max(wj, land[i].second);
    }
    ans = max(ans, temp * 1.0);
    printf("%.1Lf\n", ans);
    //system("pause");
    return 0;
}
/*
1 
999999999 999999999
*/