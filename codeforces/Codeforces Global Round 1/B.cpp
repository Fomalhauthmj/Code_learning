//TODO:解法一
// #include <algorithm>
// #include <cstring>
// #include <iostream>
// using namespace std;
// #define N 100010
// long long n, m, k;
// int seg[N];
// bool vis[N];
// struct node
// {
//     long long left;
//     int index;
// };
// node ns[N];
// bool cmp(node &n1, node &n2)
// {
//     return n1.left < n2.left;
// }
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     while (cin >> n >> m >> k)
//     {
//         for (int i = 0; i < n; i++)
//         {
//             cin >> seg[i];
//             if (i != 0)
//             {
//                 ns[i].left = seg[i] - seg[i - 1];
//                 ns[i].index = i;
//             }
//         }
//         //k==n ans=n
//         //k<n ans=? 显然ans<=m
//         sort(ns + 1, ns + n, cmp);
//         memset(vis, 0, sizeof(vis));
//         for (int i = 1; i < 1 + n - k; i++)
//         {
//             vis[ns[i].index] = 1;
//         }
//         long long ans = 0;
//         for (int i = 0; i < n; i++)
//         {
//             if (vis[i])
//             {
//                 ans += seg[i] - seg[i - 1];
//             }
//             else
//             {
//                 ans++;
//             }
//         }
//         if (ans > m)
//             ans = m;
//         cout << ans << endl;
//     }
// }
//TODO:解法二
#include <iostream>
#include <queue>
using namespace std;
#define N 100010
long long n, m, k;
priority_queue<long long, vector<long long>, greater<long long>> Q; //由小到大
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long pre, cur;
    while (cin >> n >> m >> k)
    {
        while (!Q.empty())
            Q.pop();
        for (int i = 0; i < n; i++)
        {
            cin >> cur;
            if (i != 0)
            {

                Q.push(cur - pre - 1);
            }
            pre = cur;
        }
        long long ans = n; //一开始用n段长为1的修补
        //最多允许k段 去掉长度最小的n-k段即可
        int cnt = n - k;
        while (cnt--)
        {
            long long now = Q.top();
            //cout << "cur:" << now << endl;
            Q.pop();
            ans += now;
        }
        cout << ans << endl;
    }
}