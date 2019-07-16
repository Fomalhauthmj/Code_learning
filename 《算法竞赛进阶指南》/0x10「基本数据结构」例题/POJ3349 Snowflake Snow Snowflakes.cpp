/*
 * File Created: Tuesday, 16th July 2019 10:44:50 am
 * Author: 北落师门 (NJTech_hemengjie@qq.com)
 * Last Modified: Tuesday, 16th July 2019 6:48:20 pm
 * Copyright (c) 2019 北落师门
 */
#include <cstring>
#include <iostream>
#include <stdio.h>
using namespace std;
#define P 99991
#define ll long long
const int N = 1e5 + 20;
int n, snow[N][6], head[N], nxt[N], tot = 0;
bool Equal(int *a, int *b)
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            bool flag = true;
            for (int k = 0; k < 6; k++)
                if (a[(i + k) % 6] != b[(j + k) % 6])
                    flag = false;
            if (flag)
                return true;
            flag = true;
            for (int k = 0; k < 6; k++)
                if (a[(i + k) % 6] != b[(j - k + 6) % 6])
                    flag = false;
            if (flag)
                return true;
        }
    }
    return false;
}
int H(int *a)
{
    ll sum = 0, mul = 1;
    for (int i = 0; i < 6; i++)
    {
        sum = (sum + a[i]) % P, mul = (mul * a[i]) % P;
        //cout << a[i] << " " << sum << " " << mul << endl;
    }
    return (sum + mul) % P;
}
bool Insert(int *a)
{
    int key = H(a);
    //cout << key << endl;
    for (int i = head[key]; i; i = nxt[i])
        if (Equal(a, snow[i]))
            return true;
    ++tot;
    memcpy(snow[tot], a, 6 * sizeof(int));
    nxt[tot] = head[key];
    head[key] = tot;
    return false;
}
int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    cin >> n;
    int a[6];
    bool flag = true;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 6; j++)
            scanf("%d", &a[j]);
        if (Insert(a))
        {
            cout << "Twin snowflakes found." << endl;
            flag = false;
            break;
        }
    }
    if (flag)
        cout << "No two snowflakes are alike." << endl;
    //system("pause");
    return 0;
}