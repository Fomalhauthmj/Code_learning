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
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {

            cin >> a[i];
            sum += a[i];
        }
        if(m>sum)
        {
            //大于理论无损耗最大值 无可行解
            cout << -1 << endl;
            continue;
        }
        //一天可以喝多杯 但效果递减直到效果降为0 等待第二天 求最少天数
        //贪心 先喝效果最好的喝到没效果 等第二天？ 但是会浪费一部分效果  不如留到第二天充分发挥
        //dp? 递推方程怎么写? TODO:根据tag  并非dp而是贪心 为何？
        //贪心角度来考虑，一天要写尽可能多的页数 如何应对样例345
        //有可行解
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