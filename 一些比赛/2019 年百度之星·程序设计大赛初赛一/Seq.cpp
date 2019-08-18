#include <cstring>
#include <iostream>
#include <stdio.h>
using namespace std;
#define ll long long
ll Solve(ll x)
{
    if (x == 1 || x == 2)
        return 1;
    ll k = (x - 2) % 6;
    ll cnt = (x - 2) / 6;
    if (k == 1 || k == 3)
        return cnt;
    else if (k == 2)
        return 3 + 6 * cnt;
    else if (k == 4)
        return 3 + 3 * cnt;
    else if (k == 5)
        return 5 + 4 * cnt;
    else if (k == 0)
        return 4 + 3 * (cnt - 1);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        ll n;
        cin >> n;
        cout << Solve(n) << endl;
    }
    //system("pause");
    return 0;
}