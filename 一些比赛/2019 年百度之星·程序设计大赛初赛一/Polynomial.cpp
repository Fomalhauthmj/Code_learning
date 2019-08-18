#include <iostream>
#include <stdio.h>
using namespace std;
const int N = 1050;
int f[N], g[N];
int n;
int GCD(int a, int b)
{
    return b ? GCD(b, a % b) : a;
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> f[i];
        for (int i = 0; i < n; i++)
            cin >> g[i];
        for (int i = n - 1; i >= 0; i--)
        {
            if (f[i] == 0 && g[i])
            {
                cout << "0/1" << endl;
                break;
            }
            else if (g[i] == 0 && f[i])
            {
                cout << "1/0" << endl;
                break;
            }
            else if (g[i] && f[i])
            {
                int gcd = GCD(f[i], g[i]);
                cout << f[i] / gcd << '/' << g[i] / gcd << endl;
                break;
            }
        }
    }
    system("pause");
    return 0;
}