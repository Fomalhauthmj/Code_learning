/* 
 * Author: Hemengjie
 * Time: 2019-11-09 09:24:29
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
        string s, t;
        cin >> s >> t;
        int exchange_cnt = 0;
        int pos;
        bool find = false;
        for (int i = 0; i < n; i++)
        {
            if (s[i] != t[i])
            {
                if (!find)
                    pos = i, find = true;
                else
                {
                    if (s[pos] == s[i] && t[pos] == t[i])
                        find = false, exchange_cnt++;
                    else
                        break;
                }
            }
        }
        if (exchange_cnt > 1 || find)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
    //system("pause");
    return 0;
}