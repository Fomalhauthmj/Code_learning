/*
 * File Created: Sunday, 14th July 2019 2:14:21 pm
 * Author: 北落师门 (NJTech_hemengjie@qq.com)
 * Last Modified: Sunday, 14th July 2019 2:14:24 pm
 * Copyright (c) 2019 北落师门
 */
#include <cstring>
#include <iostream>
using namespace std;
const int N = 105;
int a[N][N];
int b[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    int ans = -0x3f3f3f3f;
    for (int i = 1; i <= n; i++)//起始行
    {
        memset(b, 0, sizeof(b));//累加至一行
        for (int j = i; j <= n; j++)//结束行
        {
            int temp = 0;//当前段
            for (int k = 1; k <= n; k++)
            {
                b[k] += a[j][k];//行累加
                temp += b[k];
                ans = max(ans, temp);
                if (temp < 0)
                    temp = 0;
            }
        }
    }
    cout << ans << endl;
    //system("pause");
    return 0;
}