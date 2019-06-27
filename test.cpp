#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 100000 + 10;
int read()
{
    int x = 0, f = 1;
    char ch = ' ';
    while (ch > '9' || ch < '0')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 3) + (x << 1) + (ch ^ '0');
        ch = getchar();
    }
    return x * f;
}
int n, L;
double a[N];
double tp[N];
double s[N];
bool check(double x)
{
    for (int i = 1; i <= n; i++)
        tp[i] = a[i] - x;
    s[0] = 0;
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + tp[i];
    double ans = -(1 << 30), minval = (1 << 30);
    for (int i = L; i <= n; i++)
    {
        minval = min(minval, s[i - L]);
        ans = max(ans, s[i] - minval);
    }
    if (ans >= 0)
        return true;
    else
        return false;
}
int main()
{
    freopen("cowfnc.14.in", "r", stdin);
    freopen("output.out", "w", stdout);
    n = read(), L = read();
    for (int i = 1; i <= n; i++)
    {
        scanf("%lf", &a[i]);
    }
    double l = -(1 << 30), r = (1 << 30), mid;
    double eps = 1e-5;
    while (r - l > eps)
    {
        mid = (l + r) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    printf("%d", int(1000 * r));
    return 0;
}