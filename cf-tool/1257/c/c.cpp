/* 
 * Author: Hemengjie
 * Time: 2019-11-15 14:29:42
**/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 50;
int a[N], lst[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i], lst[a[i]] = -n;
        int ans = n + 1;
        for (int i = 1; i <= n; i++)
        {
            ans = min(ans, i - lst[a[i]] + 1);
            lst[a[i]] = i;
        }
        if (ans > 1 && ans <= n)
            cout << ans << endl;
        else
            cout << -1 << endl;
    }
    //system("pause");
    return 0;
}