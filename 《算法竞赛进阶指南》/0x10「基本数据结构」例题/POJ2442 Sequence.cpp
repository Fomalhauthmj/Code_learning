/*
 * File Created: Wednesday, 17th July 2019 10:46:07 am
 * Author: 北落师门 (NJTech_hemengjie@qq.com)
 * Last Modified: Wednesday, 17th July 2019 8:25:50 pm
 * Copyright (c) 2019 北落师门
 */
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int N = 2E3 + 50;
int a[N], b[N], c[N];
int m, n;
struct node
{
    int i, j;
    bool flag;
    node(int ii, int jj, int ff) : i(ii), j(jj), flag(ff) {}
    bool operator<(const node &n) const
    {
        return a[i] + b[j] > a[n.i] + b[n.j];
    }
};
priority_queue<node> q;
void Solve()
{
    while (!q.empty())
        q.pop();
    q.push(node(0, 0, false));
    int cnt = 0;
    while (cnt<n)
    {
        node now = q.top();
        q.pop();
        c[cnt++]=a[now.i]+b[now.j];
        if (now.i < n && now.j + 1 < n)
            q.push(node(now.i, now.j + 1, true));
        if (now.i + 1 < n && now.j < n && !now.flag)
            q.push(node(now.i + 1, now.j, false));
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> m >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        for (int i = 0; i < m - 1; i++)
        {
            for (int j = 0; j < n; j++)
                cin >> b[j];
            sort(b, b + n);
            Solve();
            memcpy(a, c, sizeof(a));
        }
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
    //system("pause");
    return 0;
}