#include <algorithm>
#include <iostream>
using namespace std;
#define N 105
int a[N];
int n, m;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n >> m)
    {
        for (int i = 0; i < n; i++)
            cin >> a[i];
        //一天可以喝多杯 但效果递减直到效果降为0 等待第二天 求最少天数
        //贪心 先喝效果最好的喝到没效果 等第二天？ 但是会浪费一部分效果  不如留到第二天充分发挥
        //dp? 递推方程怎么写? TODO:根据tag  并非dp而是贪心 为何？
        //贪心角度来考虑，一天要写尽可能多的页数
        //根据第四个样例 可以知道在一天中喝到后面时选择稍微大于0的咖啡即可？
        sort(a, a + n, greater<int>());
        int cur = 0;
        int ans = 1;
        int k = 1;
        for (int i = 0; i < n; i++)
        {
            if (cur >= m)
            {
                break;
            }
            int temp = max(0, a[i] - k + 1);
            if (temp == 0)
            {
                ans++;
                i--;
                k = 1;
            }
            else
            {
                cur += temp;
                k++;
            }
        }
        if (cur < m)
        {
            cout << -1 << endl;
        }
        else
            cout << ans << endl;
    }
}