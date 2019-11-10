/* 
 * Author: Hemengjie
 * Time: 2019-11-09 09:24:29
**/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
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
        int cnt[26];
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; i++)
            cnt[s[i] - 'a']++, cnt[t[i] - 'a']++;
        bool flag = true;
        for (int i = 0; i < 26; i++)
            if (cnt[i] & 1)
                flag = false;
        if (!flag)
            cout << "No" << endl;
        else
        {
            vector<pii> ans;
            for (int i = 0; i < n; i++)
            {
                if (s[i] != t[i])
                {
                    for (int j = i + 1; j < n; j++)
                    {
                        if (s[j] == s[i])
                        {
                            ans.push_back({j, i}), swap(s[j], t[i]);
                            break;
                        }
                        else if (t[j] == s[i])
                        {
                            ans.push_back({j, j}), swap(s[j], t[j]), ans.push_back({j, i}), swap(s[j], t[i]);
                            break;
                        }
                    }
                }
            }
            cout << "Yes" << endl;
            cout << ans.size() << endl;
            for (auto it : ans)
                cout << it.first + 1 << " " << it.second + 1 << endl;
        }
    }
    //system("pause");
    return 0;
}