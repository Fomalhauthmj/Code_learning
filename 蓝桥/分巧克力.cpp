#include <algorithm>
#include <iostream>
using namespace std;
#define N 100010
int n, k;
pair<int, int> cho[N];
bool cmp(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.first != p2.first)
        return p1.first < p2.first;
    return p1.second < p2.second;
}
bool judge(int mid)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cnt += (cho[i].first / mid) * (cho[i].second / mid);
    }
    //cout << cnt << endl;
    if (cnt < k)
        return false;
    else
        return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    // 不要搞while循环来输入 TLE！！！
    for (int i = 0; i < n; i++)
    {
        cin >> cho[i].first >> cho[i].second;
    }
    //排序
    sort(cho, cho + n, cmp);
    long long left = 1;
    long long right = N;
    long long mid;
    long long ans = 1;
    while (left <= right)
    {
        mid = (left + right) / 2;
        //cout << "cur:" << mid << endl;
        if (judge(mid))
        {
            if (mid == ans)
                break;
            ans = max(mid, ans);
            left = mid;
        }
        else
            right = mid;
    }
    cout << ans << endl;
    //system("pause");
}