#include <iostream>
#include <math.h>
#include<algorithm>
#include <stdio.h>
using namespace std;
const int N = 2e5 + 50;
#define pi acos(-1.0)
#define ll long long
struct point
{
    int x, y;
    double r;
} poi[2 * N];
bool cmp(const point &p1, const point &p2)
{
    return p1.r < p2.r;
}
int n;
ll sx[N * 2], sy[N * 2];
ll ans = 0;
void calc(int i, int j)
{
    //cout<<i<<" "<<j<<endl;
    ll t1 = sx[j] - sx[i-1];
    ll t2 = sy[j] - sy[i-1];
    ans = max(ans, t1 * t1 + t2 * t2);
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &poi[i].x, &poi[i].y), poi[i].r = atan2(poi[i].y, poi[i].x);
    sort(poi + 1, poi + 1 + n,cmp);
    for (int i = 1; i <= n; i++)
        poi[i + n] = poi[i], poi[i + n].r += 2.0 * pi;
    for (int i = 1; i <= 2 * n; i++)
        sx[i] = sx[i - 1] + poi[i].x, sy[i] = sy[i - 1] + poi[i].y;
    for (int l = 1, r = 1; l <= n; l++)
    {
        while (r - l < n && poi[r].r <= poi[l].r + pi)
            calc(l,r),r++;
        calc(l+1,r-1);
    }
    printf("%lld\n", ans);
    //system("pause");
    return 0;
}