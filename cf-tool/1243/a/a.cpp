/* 
 * Author: Hemengjie
 * Time: 2019-11-09 09:16:39
**/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k;
    cin >> k;
    while (k--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        sort(v.begin(), v.end(), greater<int>());
        int ans = 0;
        for (int i = n; i >= 1; i--)
        {
            int cnt = 0;
            for (int it : v)
            {
                if (it >= i)
                    cnt++;
            }
            if (cnt >= i)
            {
                ans = i;
                break;
            }
        }
        cout << ans << endl;
    }
    //system("pause");
    return 0;
}