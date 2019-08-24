#include <cstring>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;
string ori[30], res[30];
string s1[105], s2[105];
bool vis[105];
int n, m;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= n; i++)
            cin >> ori[i] >> res[i];
        for (int i = 0; i < m; i++)
            s1[i] = s2[i] = "";
        for (int i = 0; i < m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                s1[i] += ori[j][i];
                s2[i] += res[j][i];
            }
        }
        vector<int> ans;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[j] && s1[i] == s2[j])
                {
                    ans.push_back(j + 1), vis[j] = true;
                    break;
                }
            }
        }
        if (ans.size() != m)
            cout << -1 << endl;
        else
        {
            for (int i = 0; i < ans.size(); i++)
            {
                if (i != ans.size() - 1)
                    cout << ans[i] << " ";
                else
                    cout << ans[i] << endl;
            }
        }
    }
    //system("pause");
    return 0;
}