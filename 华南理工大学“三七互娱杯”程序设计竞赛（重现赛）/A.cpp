#include <iomanip>
#include <iostream>
#include <math.h>
using namespace std;
#define N 305
double p[N];
int n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    system("pause");
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        //两个账号
        for (int i = 0; i < n; i++)
            cin >> p[i];
        double ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += pow(0.5, i + 1) * i * p[i];
            cout << ans << endl;
        }
    }
    return 0;
}