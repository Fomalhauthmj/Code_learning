#include <cstring>
#include <iostream>
#include <math.h>
using namespace std;
#define N 1010
#define MAX 1010 * 150
int n, k;
int Round(double x)
{
    return (int)(x + 0.5);
}
int a[N];
pair<int, int> v1[N];
int v2[N];
bool vis[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n >> k)
    {
        for (int i = 0; i < n; i++)
            cin >> a[i]; //1-150
        //m为已测试完成  n为总数
        //模拟多线程？
        int pos = 0;
        int m = 0;
        memset(v1, 0, sizeof(v1));
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < MAX; i++) //模拟时间
        {
            for (int j = 0; j < k; j++)
            {
                if (v1[j].first==0 && pos < n)
                {
                    v1[j].first = a[pos];
                    v1[j].second = pos++;
                    v2[j] = v1[j].first;
                }
            }             //分配任务
            int temp = 0; //统计这一刻完成的任务数
            for (int j = 0;j < k; j++)
            {
                if(v1[j].first<=0)
                    continue;
                v1[j].first--;
                int cur = v2[j] - v1[j].first;
                if (Round(100.0 * m / n) == cur)
                {
                    //cout<<j <<" "<< v1[j].second << " " << cur << " " << round(100.0 * m / n) << endl;
                    vis[v1[j].second] = 1;
                }
                if (v1[j].first == 0)
                {
                    temp++;
                }
            }
            m += temp; //更新
            bool all_finish = true;
            for (int j = 0; j < k; j++)
            {
                if (v2[j] != -1)
                {
                    all_finish = false;
                    break;
                }
            }
            if (all_finish)
                break;
        }

        //统计
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (vis[i])
                ans++;
        }
        cout << ans << endl;
    }
}