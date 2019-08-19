/*
 * File Created: Tuesday, 16th July 2019 8:47:07 pm
 * Author: 北落师门 (NJTech_hemengjie@qq.com)
 * Last Modified: Tuesday, 16th July 2019 8:49:30 pm
 * Copyright (c) 2019 北落师门
 */
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
#define ull unsigned long long
#define P 131
const int N = 3e5 + 50;
ull f[N], p[N];
char str[N];
int SA[N], n, Height[N];
void Init()
{
    p[0] = 1, f[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        p[i] = p[i - 1] * P;
        f[i] = f[i - 1] * P + str[i];
    }
}
ull Hash(int left, int right)
{
    return f[right] - f[left - 1] * p[right - left + 1];
}
// k∈[0,n) 表示后缀S(k,n-1)
int LCP(int a, int b)
{
    int left = 0;
    int right = N;
    int mid;
    while (left < right)
    {
        mid = (left + right + 1) >> 1;
        if (a + mid - 1 <= n && b + mid - 1 <= n && Hash(a, a + mid - 1) == Hash(b, b + mid - 1))
            left = mid;
        else
            right = mid - 1;
    }
    return left;
}
bool cmp(int a, int b)
{
    int len = LCP(a, b);
    return str[a + len] < str[b + len];
}
void calc_height()
{
    Height[1] = 0;
    for (int i = 2; i <= n; i++)
        Height[i] = LCP(SA[i], SA[i - 1]);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    scanf("%s", str + 1);
    n = strlen(str + 1);
    //cout << str + 1 << " " << n << endl;
    for (int i = 1; i <= n; i++)
        SA[i] = i;
    Init();
    sort(SA + 1, SA + n + 1, cmp);
    for (int i = 1; i <= n; i++)
        cout << SA[i] - 1 << " ";
    cout << endl;
    calc_height();
    for (int i = 1; i <= n; i++)
        cout << Height[i] << " ";
    cout << endl;
    system("pause");
    return 0;
}