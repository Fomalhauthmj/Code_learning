#include <cstring>
#include <iostream>
using namespace std;
int n;
int dis[20][20];
int f[1 << 20][20];
int Hamilton()
{
    memset(f, 0x3f, sizeof(f));
    f[1][0] = 0;
    //f[i][j]  j表示当前位置
    for (int i = 1; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i >> j) & 1)
            {
                for (int k = 0; k < n; k++)
                {
                    if (j != k && (i >> k) & 1)
                        f[i][j] = min(f[i][j], f[i ^ (1 << j)][k] + dis[k][j]);
                }
            }
        }
    }
    return f[(1 << n) - 1][n - 1];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> dis[i][j];
        }
    }
    cout << Hamilton() << endl;
    //system("pause");
    return 0;
}