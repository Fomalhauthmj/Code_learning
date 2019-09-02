#include <algorithm>
#include <iostream>
using namespace std;
const int N = 2E5 + 50;
#define ll long long
int n, m;
struct edge
{
    int u, v, w;
    bool operator<(const edge &e) const
    {
        return w < e.w;
    }
} e[N];
ll fa[N], cnt[N], ans[N];
int Find(int x)
{
    if (fa[x] == x)
        return x;
    return fa[x] = Find(fa[x]);
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0, u, v, w; i < n - 1; i++)
        scanf("%d%d%d", &u, &v, &w), e[i] = {u, v, w};
    for (int i = 1; i <= n; i++)
        fa[i] = i, cnt[i] = 1;
    sort(e, e + n - 1);
    for (int i = 0; i < n - 1; i++)
    {
        int fu = Find(e[i].u), fv = Find(e[i].v);
        if (fu != fv)
        {
            if (i)
                ans[i] = ans[i - 1] + cnt[fu] * cnt[fv];
            else
                ans[i] = cnt[fu] * cnt[fv];
            //if (fu > fv)
            //swap(fu, fv);
            cnt[fu] += cnt[fv];
            fa[fv] = fu;
            //cout << i << " : " << ans[i] << endl;
        }
    }
    for (int i = 0; i < m; i++)
    {
        edge temp;
        scanf("%d", &temp.w);
        int k = upper_bound(e, e + n - 1, temp) - e;
        if (k - 1 >= 0)
            printf("%lld ", ans[k - 1]);
        else
            printf("0 ");
    }
    //system("pause");
    return 0;
}