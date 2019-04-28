#include <algorithm>
#include <iostream>
#include <math.h>
using namespace std;
#define N 100010
//一个位置可能有多个人 map不能确定范围内数量 用二分查找
long long pos[N];
//区间人数=upper_bound(pos,pos+k,right)-lower_bound(pos,pos+k,left)
//>right- >=left
//如果没有人 只能+a
//如果有人   b*人数*区间长度
long long n, k, a, b;
long long ans;
long long solve(long long left, long long right)
{
    if (left == right)
    {
        int num = upper_bound(pos, pos + k, right) - lower_bound(pos, pos + k, left);
        if (num != 0)
            return b * num * 1;
        else
            return a;
    }
    else
    {
        int num = upper_bound(pos, pos + k, right) - lower_bound(pos, pos + k, left);
        //cout << left << "->" << right << ":" << num << endl;
        if (num != 0)
        {
            long long temp = b * num * (right - left + 1);
            long long mid = (left + right) / 2;
            long long t1 = solve(left, mid);
            long long t2 = solve(mid + 1, right);
            if (temp < t1 + t2)
                return temp;
            else
                return t1 + t2;
        }
        else
            return a;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n >> k >> a >> b)
    {
        for (int i = 0; i < k; i++)
        {
            cin >> pos[i];
        }
        sort(pos, pos + k); //排序
        ans=solve(1, pow(2, n));
        cout << ans << endl;
    }
}