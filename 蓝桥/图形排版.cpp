#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
#define N 100010
int n, m;
vector<pair<int, int> > v;
//注意这个空格在蓝桥测评
//O(n^2) 37%
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> m >> n;
    int wi, hi;
    for (int i = 0; i < n; i++)
    {
        cin >> wi >> hi;
        v.push_back(make_pair(wi, hi));
    }
    int ans = 0x3f3f3f3f;
    int temp_ans;
    for (int k = 0; k < n; k++)
    {
        temp_ans = 0;
        int cur_width = 0;
        int temp_max = 0;
        for (int i = 0; i < n; i++)
        {
            if (i == k)
                continue;
            if (cur_width <= m)
            {
                int rest = m - cur_width;
                if (v[i].first >= rest)
                {
                    //缩放
                    double t = rest * 1.0 / v[i].first * v[i].second;
                    //cout << ceil(t) << endl;
                    temp_max = max(temp_max, (int)ceil(t));
                    temp_ans += temp_max;
                    cur_width = 0;
                    temp_max = 0;
                }
                else
                {
                    cur_width += v[i].first;
                    temp_max = max(temp_max, v[i].second);
                }
            }
            //cout << "Cur:" << ans << endl;
        }
        //若一行未满
        temp_ans += temp_max;
        ans = min(ans, temp_ans);
        //cout << "Final:" << ans << endl;
    }
    cout << ans << endl;
    return 0;
    //system("pause");
}