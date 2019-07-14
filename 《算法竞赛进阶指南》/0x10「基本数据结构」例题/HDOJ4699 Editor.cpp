/*
 * File Created: Sunday, 14th July 2019 7:51:35 pm
 * Author: 北落师门 (NJTech_hemengjie@qq.com)
 * Last Modified: Sunday, 14th July 2019 7:52:16 pm
 * Copyright (c) 2019 北落师门
 */
#include <iostream>
#include <stack>
using namespace std;
stack<int> a, b, c;
const int N = 1e6 + 50;
#define ll long long
ll sum[N], f[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    while (cin >> q)
    {
        a = c;
        b = c;
        char ch;
        int x, k;
        sum[0] = 0;
        f[0] = -0x3f3f3f3f;
        while (q--)
        {
            cin >> ch;
            if (ch == 'I')
            {
                cin >> x;
                a.push(x);
                int pa = a.size();
                sum[pa] = sum[pa - 1] + x;
                f[pa] = max(f[pa - 1], sum[pa]);
            }
            else if (ch == 'D')
            {
                if (!a.empty())
                    a.pop();
            }
            else if (ch == 'L')
            {
                if (!a.empty())
                {
                    ll now = a.top();
                    a.pop();
                    b.push(now);
                }
            }
            else if (ch == 'R')
            {
                if (!b.empty())
                {
                    ll now = b.top();
                    b.pop();
                    a.push(now);
                    int pa = a.size();
                    sum[pa] = sum[pa - 1] + a.top();
                    f[pa] = max(f[pa - 1], sum[pa]);
                }
            }
            else if (ch == 'Q')
            {
                cin >> k;
                cout << f[k] << endl;
            }
        }
    }
    //system("pause");
    return 0;
}