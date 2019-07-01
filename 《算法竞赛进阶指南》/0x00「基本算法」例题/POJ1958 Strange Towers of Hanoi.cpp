#include <algorithm>
#include <iostream>
#include <math.h>
using namespace std;
#define ll long long
ll f[13];
ll Solve(int n)
{
    if (n == 1)
        return f[1];
    else
        f[n] = 0x3f3f3f3f;
    for (int k = 1; k <= n; k++)
    {
        f[n] = min(f[n], 2 * f[k] + (ll)pow(2, n - k) - 1);
    }
    return f[n];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    f[1] = 1;
    for (int n = 1; n <= 12; n++)
    {
        cout << Solve(n) << endl;
    }
    //system("pause");
    return 0;
}