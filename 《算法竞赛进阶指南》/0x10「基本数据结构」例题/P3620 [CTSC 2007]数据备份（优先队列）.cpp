/*
 * File Created: Wednesday, 17th July 2019 9:19:11 pm
 * Author: 北落师门 (NJTech_hemengjie@qq.com)
 * Last Modified: Wednesday, 17th July 2019 10:37:00 pm
 * Copyright (c) 2019 北落师门
 */
#include <iostream>
#include <queue>
using namespace std;
#define ll long long
const int N = 1E5 + 50;
int nxt[N], pre[N], a[N];
struct node
{
    int lptr;
    bool operator<(const node &n) const
    {
        return a[lptr] > a[n.lptr];
    }
    node(int pp) : lptr(pp) {}
};
priority_queue<node> q;
bool vis[N];
ll n, k;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll pre_val, cur_val;
    cin >> n >> k >> pre_val;
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> cur_val;
        a[i] = cur_val - pre_val;
        pre_val = cur_val;
        nxt[i] = i + 1;
        pre[i] = i - 1;
        q.push(node(i));
    }
    ll ans = 0;
    a[0] = 0x3f3f3f3f;
    a[n] = 0x3f3f3f3f;
    for (int i = 0; i < k; i++)
    {
        node now = q.top();
        q.pop();
        while (vis[now.lptr])
        {
            now = q.top();
            q.pop();
        }
        ans += a[now.lptr];
        a[now.lptr] = a[pre[now.lptr]] + a[nxt[now.lptr]] - a[now.lptr];
        vis[pre[now.lptr]] = 1;
        vis[nxt[now.lptr]] = 1;
        pre[now.lptr] = pre[pre[now.lptr]];
        nxt[now.lptr] = nxt[nxt[now.lptr]];
        pre[nxt[now.lptr]] = now.lptr;
        nxt[pre[now.lptr]] = now.lptr;
        q.push(now);
    }
    cout << ans << endl;
    //system("pause");
    return 0;
}