//! : help jimmy POJ 1661 只要计算横向移动距离

#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
#define size 1010
#define inf 99999
struct node
{
    int lx;
    int rx;
    int h;
    bool operator<(const node &n) const
    {
        return h < n.h;
    }
};
node layer[size];
int n, Max;
int dp[size][2];
int down(int x, int st, int h)
{
    for (int i = st; i >= 0; i--)
    {
        if (st == 0)
            return 0;
        if (h - layer[i].h > Max)
            return -1;
        if (x < layer[st].rx && x > layer[st].lx)
            return i;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int sx, sy;
    cin >> n >> Max >> sx >> sy;
    layer[0].lx = layer[0].rx = sx;
    layer[0].h = sy;
    layer[1].lx = 0;
    layer[1].rx = 0;
    layer[1].h = 0;
    for (int i = 2; i <= n + 1; i++)
    {
        cin >> layer[i].h >> layer[i].lx >> layer[i].rx;
    }
    sort(layer, layer + n + 2);
    int lx, rx;
    int downl, downr;
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n + 1; i++)
    {
        lx = layer[i].lx;
        rx = layer[i].rx; //从最低到最高 如果从最高到最低?
        downl = down(lx, i - 1, layer[i].h);
        downr = down(rx, i - 1, layer[i].h);
        cout << "downl:" << downl << " downr: " << downr << endl;
        if (downl > 0)
        {
            dp[i][0] = min((dp[downl][0] + lx - layer[downl].lx),
                           (dp[downl][1] + layer[downl].rx - lx));
        }
        else if (downl == 0)
            dp[i][0] = 0;
        else
            dp[i][0] = inf;
        if (downr > 0)
        {
            dp[i][1] = min(dp[downr][0] + rx - layer[downr].lx,
                           dp[downr][1] + layer[downr].rx - rx);
        }
        else if (downr == 0)
            dp[i][1] = 0;
        else
            dp[i][1] = inf;
        cout << "i:" << i << " dp[0]: " << dp[i][0] << " dp[1]: " << dp[i][1] << endl;
    }
    cout << dp[n + 1][0] + sy << endl;
    cout << dp[n + 1][1] + sy << endl;
    system("pause");
} //  WA!!
