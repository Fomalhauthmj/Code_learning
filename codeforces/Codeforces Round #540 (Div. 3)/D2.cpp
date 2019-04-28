#include <algorithm>
#include <iostream>
using namespace std;
#define N 200020
long long n, m;
long long a[N];
bool judge(int day)
{
    long long cur = 0;
    //取最大的k个元素为 每天第一杯
    //取次大的k个元素为 每天第二杯
    //如此往复
    //根据从大到小的顺序
    //a0 ak ...
    //a1 ak+1 ...
    //a2 ak+2 ...
    //ak-1 ak+3 ...
    for (int i = 0; i < n; i++)
    {
        cur += max((long long)0, a[i] - i / day); //k个一组
    }
    if (cur >= m)
        return true;
    else
        return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n >> m)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        //数据范围增大 遍历是否可行？
        long long ans = N;
        bool finish = false;
        sort(a, a + n, greater<long long>());
        //减少遍历次数 采用二分搜索
        long long left=1;
        long long right=N;
        long long mid;
        while(left<=right)
        {
            mid=(left+right)/2;
            if(judge(mid))
            {
                ans = min(ans, mid);
                finish = true;
                right = mid - 1;
            }
            else
                left = mid+1;
        }
        if (finish)
        {
            cout << ans << endl;
        }
        else
            cout << -1 << endl;
    }
}