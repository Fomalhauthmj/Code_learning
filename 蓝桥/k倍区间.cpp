#include <cstring>
#include <iostream>
#include <stdio.h>
using namespace std;
#define N 100010
int n, k;
int a[N];
long long sum[N];
int cnt[N];
//O(n^2) 28%
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    cin >> n >> k;
    sum[0] = 0;
    memset(cnt, 0, sizeof(cnt));
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i]; //前缀和 获得区间和
        ans += cnt[sum[i] % k];     //计算前缀和的过程中统计
        //前缀和取模相同的相减得到一段符合区间
        cnt[sum[i] % k]++;
    }
    //同时 遗漏了1->i 前缀和取模符合0的区间
    ans += cnt[0];
    cout << ans << endl;
    return 0;
}
//https://fomalhauthmj.github.io/2019/02/24/Codeforces-Round-539-Div-2/
//C - Sasha and a Bit of Relax
//注意这种前缀和的处理方法 第二次出现了！！！