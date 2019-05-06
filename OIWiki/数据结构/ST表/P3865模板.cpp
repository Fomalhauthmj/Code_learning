//https://www.luogu.org/problemnew/show/P3865
#include <iostream>
#include <stdio.h>
using namespace std;
const int N = 1e5 + 10;
int n, m;
long long f[N][20];
int lg[N];
int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //cin >> n >> m;
    scanf("%d%d", &n, &m);
    long long ai;
    for (int i = 1; i <= n; i++)
    {
        //cin >> ai;
        scanf("%ld", &ai);
        f[i][0] = ai;
    }
    for (int j = 1; (1 << j) <= n; j++)
    {
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
        {
            f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
        }
    }
    lg[0] = -1;
    for (int i = 1; i <= n; i++)
    {
        lg[i] = lg[i >> 1] + 1;
    }
    int left, right;
    for (int i = 0; i < m; i++)
    {
        //cin >> left >> right;
        scanf("%d%d", &left, &right);
        int s = lg[right - left + 1];
        //cout << max(f[left][s], f[right - (1 << s) + 1][s]) << endl;
        printf("%ld\n", max(f[left][s], f[right - (1 << s) + 1][s]));
    }
    //system("pause");
    return 0;
}