#include <algorithm>
#include <cstring>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <vector>
using namespace std;
const int N = 4E4 + 50;
const int T = 785;
int n, m, cnt, t;
int a[N], b[N];
int L[N], R[N], pos[N], max_cnt[T][T][2], each_cnt[N];
vector<int> v[N];
int temp_max[2];
inline void work(int l, int r, int val)
{
    int cnt = upper_bound(v[val].begin(), v[val].end(), r) -
              lower_bound(v[val].begin(), v[val].end(), l);
    if (cnt > temp_max[0] || (cnt == temp_max[0] && val < temp_max[1]))
    {
        temp_max[0] = cnt;
        temp_max[1] = val;
    }
}
int ask(int l, int r)
{
    int p = pos[l], q = pos[r];
    int x = 0, y = 0;
    if (p == q)
    {
        memset(temp_max, 0, sizeof(temp_max));
        for (int i = l; i <= r; i++)
            work(l, r, a[i]);
    }
    else
    {
        if (p + 1 <= q - 1)
        {
            x = p + 1, y = q - 1;
            memcpy(temp_max, max_cnt[x][y], sizeof(temp_max));
        }
        else
            memset(temp_max, 0, sizeof(temp_max));
        for (int i = l; i <= R[p]; i++)
            work(l, r, a[i]);
        for (int i = L[q]; i <= r; i++)
            work(l, r, a[i]);
    }
    return b[temp_max[1]];
}
int main()
{
    cin >> n >> m;
    t = sqrt(n * log2(n)) + 1; //分块
    int len = n / t;           //TLE 注意分块大小
    for (int i = 1; i <= t; i++)
        L[i] = (i - 1) * len + 1, R[i] = i * len;
    if (R[t] < n)
        t++, L[t] = R[t - 1] + 1, R[t] = n;
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]), b[i] = a[i];
    sort(b + 1, b + 1 + n);
    cnt = unique(b + 1, b + n + 1) - (b + 1);
    for (int i = 1; i <= n; i++)
    {
        a[i] = lower_bound(b + 1, b + cnt + 1, a[i]) - b;
        v[a[i]].push_back(i); //出现位置
    }
    for (int i = 1; i <= t; i++)
        for (int j = L[i]; j <= R[i]; j++)
            pos[j] = i;
    for (int i = 1; i <= t; i++)
    {
        memset(each_cnt, 0, sizeof(each_cnt));
        int t_cnt = 0, t_val = 0;
        for (int j = L[i]; j <= n; j++)
        {
            each_cnt[a[j]]++;
            int k = pos[j];
            if (each_cnt[a[j]] > t_cnt || (each_cnt[a[j]] == t_cnt && a[j] < t_val))
            {
                t_cnt = each_cnt[a[j]];
                t_val = a[j];
            }
            max_cnt[i][k][0] = t_cnt;//注意这里统计众数的优化
            max_cnt[i][k][1] = t_val;
        }
    }
    int l, r, l0, r0, x = 0;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &l0, &r0);
        l = (l0 + x - 1) % n + 1, r = (r0 + x - 1) % n + 1;
        if (l > r)
            swap(l, r);
        x = ask(l, r);
        printf("%d\n", x);
    }
    system("pause");
    return 0;
}