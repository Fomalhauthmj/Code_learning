/*
 * File Created: Tuesday, 16th July 2019 7:37:44 pm
 * Author: 北落师门 (NJTech_hemengjie@qq.com)
 * Last Modified: Tuesday, 16th July 2019 7:37:50 pm
 * Copyright (c) 2019 北落师门
 */
#include <iostream>
#include <string>
using namespace std;
#define ull unsigned long long
#define P 131
const int N = 1e6 + 50;
ull pre[N], suf[N], p[N];
string str;
int n;
void Init()
{
    pre[0] = suf[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] * P + str[i - 1];
        suf[i] = suf[i - 1] * P + str[n - i];
    }
}
ull Hash(int left, int right)
{
    return pre[right] - pre[left - 1] * p[right - left + 1];
}
ull HashReverse(int left, int right)
{
    //WA 这里注意推导
    return suf[n - left + 1] - suf[n - right] * p[right - left + 1];
}
#define ODD 1
#define EVEN 2
bool Judge(int pos, int len, int flag)
{
    if (flag == ODD)
    {
        if (pos - len < 1 || pos > n || pos < 1 || pos + len > n)
            return false;
        return Hash(pos - len, pos) == HashReverse(pos, pos + len);
    }
    else
    {
        if (pos - len < 1 || pos - 1 > n || pos < 1 || pos + len - 1 > n)
            return false;
        return Hash(pos - len, pos - 1) == HashReverse(pos, pos + len - 1);
    }
}
int Solve(int pos)
{
    int ans = 1;
    //奇数
    int left = 0;
    int right = N;
    int mid;
    while (left < right)
    {
        mid = (left + right + 1) >> 1;
        if (Judge(pos, mid, ODD))
            left = mid;
        else
            right = mid - 1;
    }
    ans = max(ans, 2 * left + 1);
    //偶数
    left = 0;
    right = N;
    while (left < right)
    {
        mid = (left + right + 1) >> 1;
        if (Judge(pos, mid, EVEN))
            left = mid;
        else
            right = mid - 1;
    }
    ans = max(ans, 2 * left);
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int casenum = 0;
    p[0] = 1;
    for (int i = 1; i < N; i++)
        p[i] = p[i - 1] * P;
    while (cin >> str && str != "END")
    {
        int ans = 1;
        n = str.length();
        Init();
        for (int i = 1; i <= n; i++)
            ans = max(ans, Solve(i));
        cout << "Case " << ++casenum << ": " << ans << endl;
    }
    //system("pause");
    return 0;
}