#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;
#define N 200020
int n, m, k;
long long a[N];
long long b[N];
map<long long, int> M;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n >> m >> k)
    {
        M.clear();
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            b[i] = a[i];
        }
        long long ans = 0;
        sort(b, b + n, greater<long long>());
        for (int i = 0; i < m * k; i++)
        {
            ans += b[i];
            M[b[i]]++;
        }
        /*
        nth_element(b, b + n-m*k, b + n);
        for (int i =n- m*k; i <n; i++)
        {
            ans += b[i];
            M[b[i]]++;
        }
        */
        cout << ans << endl; //如何划分
        int pos = 0;
        int cnt = 0; //记录当前段已选数量
        int seg_cnt = 0;
        while (pos < n)
        {
            if (M[a[pos]] > 0)
            {
                M[a[pos]]--;
                cnt++;
            }
            if (cnt == m)
            {
                cout << pos + 1;
                cnt = 0;
                seg_cnt++;
                if (seg_cnt != k - 1)
                    cout << " ";
                else
                {
                    cout << endl;
                    break;
                }
            }
            pos++;
        }
    }
}
//参考题解
// #include <algorithm>
// #include <cstring>
// #include <iostream>
// #define N 200020
// using namespace std;
// int n, m, k;
// struct node
// {
//     long long val;
//     int pos;
// };
// bool cmp(node &n1, node &n2)
// {
//     return n1.val > n2.val;
// }
// node ns[N];
// bool vis[N];
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     while (cin >> n >> m >> k)
//     {
//         for (int i = 0; i < n; i++)
//         {
//             cin >> ns[i].val;
//             ns[i].pos = i + 1;
//         }
//         sort(ns, ns + n, cmp);
//         long long ans = 0;
//         memset(vis, 0, sizeof(vis));
//         for (int i = 0; i < m * k; i++)
//         {
//             ans += ns[i].val;
//             vis[ns[i].pos] = 1;
//         }
//         cout << ans << endl;
//         int cnt = 0;
//         int seg_cnt = 0;
//         for (int i = 1; i <= n; i++)
//         {
//             if (seg_cnt == k - 1)
//                 break;
//             if (vis[i])
//                 cnt++;
//             if (cnt == m)
//             {
//                 cnt = 0;
//                 seg_cnt++;
//                 cout << i << " ";
//             }
//         }
//         cout << endl;
//     }
// }