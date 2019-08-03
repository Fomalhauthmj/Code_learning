#include <algorithm>
#include <cstring>
#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
const int N = 4E4 + 50;
const int T = 37;
int n, m, cnt, t;
int a[N], b[N];
int L[N], R[N], pos[N], each_cnt[T][T][N], max_cnt[T][T][2];
void count(int p, int q)
{
    for (int i = L[p]; i <= R[q]; i++)
        ++each_cnt[p][q][a[i]];
    for (int i = 1; i <= cnt; i++)
    {
        if (each_cnt[p][q][i] > max_cnt[p][q][0])
        {
            max_cnt[p][q][0] = each_cnt[p][q][i];
            max_cnt[p][q][1] = i;
        }
    }
}
int temp_max[2];
inline void work(int x, int y, int val)
{
    ++each_cnt[x][y][val];
    if (each_cnt[x][y][val] > temp_max[0] || (each_cnt[x][y][val] == temp_max[0] && val < temp_max[1]))
    {
        temp_max[0] = each_cnt[x][y][val];
        temp_max[1] = val;
    }
}
int ask(int l, int r)
{
    int p = pos[l], q = pos[r];
    int x = 0, y = 0;
    if (p == q)
    {
        memcpy(temp_max, max_cnt[x][y], sizeof(temp_max));
        for (int i = l; i <= r; i++)
            work(x, y, a[i]);
        for (int i = l; i <= r; i++)
            --each_cnt[x][y][a[i]];
    }
    else
    {
        if (p + 1 <= q - 1)
        {
            x = p + 1, y = q - 1;
        }
        memcpy(temp_max, max_cnt[x][y], sizeof(temp_max));
        for (int i = l; i <= R[p]; i++)
            work(x, y, a[i]);
        for (int i = L[q]; i <= r; i++)
            work(x, y, a[i]);
        for (int i = l; i <= R[p]; i++)
            --each_cnt[x][y][a[i]];
        for (int i = L[q]; i <= r; i++)
            --each_cnt[x][y][a[i]];
    }
    return b[temp_max[1]];
}
int main()
{
    cin >> n >> m;
    t = pow(n, 1.0 / 3.0) + 1; //分块
    int len=n/t;//TLE 注意分块大小
    for (int i = 1; i <= t; i++)
        L[i] = (i - 1) * len + 1, R[i] = i * len;
    if (R[t] < n)
        t++, L[t] = R[t - 1] + 1, R[t] = n;
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]), b[i] = a[i];
    sort(b + 1, b + 1 + n);
    cnt = unique(b + 1, b + n + 1) - (b + 1);
    for (int i = 1; i <= n; i++)
        a[i] = lower_bound(b + 1, b + cnt + 1, a[i]) - b;
    for (int i = 1; i <= t; i++)
        for (int j = L[i]; j <= R[i]; j++)
            pos[j] = i;
    for (int i = 1; i <= t; i++)
    {
        for (int j = i; j <= t; j++)
        {
            count(i, j);
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
        printf("%d\n",x);
    }
    system("pause");
    return 0;
}