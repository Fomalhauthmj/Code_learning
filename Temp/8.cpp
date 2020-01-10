#include <iostream>
#include <math.h>
using namespace std;
#define inf 0x3f3f3f3f;
struct p
{
    int r, c;
};
double Dis(p p1, p p2)
{
    return sqrt(1.0 * (p1.r - p2.r) * (p1.r - p2.r) + 1.0 * (p1.c - p2.c) * (p1.c - p2.c));
}
int n, m;
double d;
bool legal(p p1)
{
    if (p1.r < 1 || p1.r > n)
        return false;
    if (p1.c < 1 || p1.c > m)
        return false;
    return true;
}
p FindBestp(p cp)
{
    double cur_dis = inf;
    p nxt;
    p target;
    target.r = n, target.c = m;
    for (int i = 0; i <= d; i++)
    {
        for (int j = 0; j <= d; j++)
        {
            p np;
            np.r = cp.r + i;
            np.c = cp.c + j;
            double limit = Dis(cp, np);
            if (limit > d || !legal(np))
                continue;
            double temp_dis = Dis(target, np);
            if (temp_dis < cur_dis)
            {
                cur_dis = temp_dis;
                nxt = np;
            }
        }
    }
    return nxt;
}
int main()
{
    cin >> n >> m >> d;
    int ans = 0;
    p init, target;
    init.r = 1, init.c = 1;
    target.r = n, target.c = m;
    while (1)
    {
        ans++;
        init = FindBestp(init);
        //cout << "goto:" << init.r << " " << init.c << endl;
        if (Dis(init, target) < 1e-6)
            break;
    }
    cout << ans << endl;
    system("pause");
    return 0;
}