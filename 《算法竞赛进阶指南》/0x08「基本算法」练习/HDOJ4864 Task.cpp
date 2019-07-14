/*
 * File Created: Sunday, 14th July 2019 2:42:37 pm
 * Author: 北落师门 (NJTech_hemengjie@qq.com)
 * Last Modified: Sunday, 14th July 2019 2:46:04 pm
 * Copyright (c) 2019 北落师门
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int N = 1E5 + 50;
#define ll long long
int n, m;
struct task
{
    int x, y;
    bool operator<(const task &n) const
    {
        return 500 * x + 2 * y > 500 * n.x + 2 * n.y;
    }
};
task b[N];
vector<int> a[105];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n >> m)
    {
        for (int i = 0; i <= 100; i++)
            a[i].clear();
        int x, y;
        for (int i = 0; i < n; i++)
        {
            cin >> x >> y;
            a[y].push_back(x);
        }
        for (int i = 0; i < m; i++)
        {
            cin >> b[i].x >> b[i].y;
        }
        for (int i = 0; i <= 100; i++)
            sort(a[i].begin(), a[i].end());
        sort(b, b + m);
        ll cnt = 0, ans = 0;
        for (int i = 0; i < m; i++)
        {
            bool flag = false;
            for (int key = b[i].y; key <= 100; key++)
            {
                int len = a[key].size();
                if (len)
                {
                    int pos = lower_bound(a[key].begin(), a[key].end(), b[i].x) - a[key].begin();
                    if (pos < len)
                    {
                        a[key].erase(a[key].begin() + pos);
                        flag = true;
                        break;
                    }
                }
            }
            if (flag)
            {
                cnt++;
                ans += b[i].x * 500 + b[i].y * 2;
            }
        }
        cout << cnt << " " << ans << endl;
    }
    //system("pause");
    return 0;
}