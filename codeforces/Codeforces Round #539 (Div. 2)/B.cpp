#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define N 50050
int n;
int a[N];
vector<int> v[101];
//TODO:贪心 找出最大数的最大因数 同时选择最小的数乘以这个因数？
//假设最大数是素数 不可行
//预处理？首先确定出1-100的因子
//排序去重 暴力枚举
void init()
{
    for (int i = 1; i <= 100; i++)
    {
        v[i].clear();
        for (int j = 1; j <= i; j++)
        {
            if (i % j == 0)
                v[i].push_back(j);
        }
        //cout << i << ":" << v[i].size() << endl; max:12
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    while (cin >> n)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        sort(a, a + n);
        int cnt = unique(a, a + n) - a;
        int ans = sum;
        //a[0]->ele*a[0]  a[i]->a[i]/ele
        for (int i = 0; i < cnt; i++)//100*12
        {
            for (auto ele : v[a[i]]) //TODO: WA这里不要写错了
            {
                ans = min(ans, sum + (ele - 1) * a[0] - a[i] / ele * (ele - 1));
            }
        }
        cout << ans << endl;
    }
}