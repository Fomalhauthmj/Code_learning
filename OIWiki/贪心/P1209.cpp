//https://www.luogu.org/problemnew/show/P1209
#include <algorithm>
#include <iostream>
using namespace std;
const int N = 205;
int m, s, c;
int cc[N];
int d[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> m >> s >> c;
    for (int i = 0; i < c; i++)
    {
        cin >> cc[i];
    }
    sort(cc, cc + c);
    int ans = cc[c - 1] - cc[0] + 1;
    if (m >= c)
    {
        cout << c << endl;
    }
    else
    {
        for (int i = 0; i < c - 1; i++)
        {
            d[i] = cc[i + 1] - cc[i] - 1;
        }
        sort(d, d + c - 1, greater<int>());
        for (int i = 0; i < m - 1; i++)
        {
            ans -= d[i];
        }
        cout << ans << endl;
    }
    //system("pause");
    return 0;
}