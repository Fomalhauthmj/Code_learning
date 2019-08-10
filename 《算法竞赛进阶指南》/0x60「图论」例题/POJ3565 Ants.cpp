#include <cstring>
#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
#define pii pair<int,int>
#define inf 0x3f3f3f3f
#define eps 1e-6
const int N = 105;
pii black[N], white[N];
double w[N][N], la[N], lb[N], upd[N], delta;
int n, match[N];
bool visa[N], visb[N];
double Distance(pii &p1, pii &p2)
{
    return sqrt((p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second));
}
bool DFS(int x)
{
    visa[x] = true;
    for (int y = 1; y <= n; y++)
    {
        if (!visb[y])
        {
            double temp = fabs(la[x] + lb[y] - w[x][y]);
            if (temp < eps)
            {
                visb[y] = true;
                if (!match[y] || DFS(match[y]))
                {
                    match[y] = x;
                    return true;
                }
            }
            else
                upd[y] = min(upd[y], la[x] + lb[y] - w[x][y]);
        }
    }
    return false;
}
void KM()
{
    for (int i = 1; i <= n; i++)
    {
        la[i] = -inf;
        lb[i] = 0;
        for (int j = 1; j <= n; j++)
            la[i] = max(la[i], w[i][j]);
    }
    for (int i = 1; i <= n; i++)
    {
        while (true)
        {
            memset(visa, 0, sizeof(visa));
            memset(visb, 0, sizeof(visb));
            for (int j = 1; j <= n; j++)
                upd[j] = inf;
            if (DFS(i))
                break;
            else
            {
                delta = inf;
                for (int j = 1; j <= n; j++)
                    if (!visb[j])
                        delta = min(delta, upd[j]);
                for (int j = 1; j <= n; j++)
                {
                    if (visa[j])
                        la[j] -= delta;
                    if (visb[j])
                        lb[j] += delta;
                }
            }
        }
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &black[i].first, &black[i].second);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &white[i].first, &white[i].second);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            w[i][j] = -Distance(white[i], black[j]);
    }
    KM();
    for (int i = 1; i <= n; i++)
        cout << match[i] << endl;
    system("pause");
    return 0;
}