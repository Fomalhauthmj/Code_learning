/*
 * File Created: Friday, 19th July 2019 6:45:55 am
 * Author: 北落师门 (NJTech_hemengjie@qq.com)
 * Last Modified: Friday, 19th July 2019 6:48:25 am
 * Copyright (c) 2019 北落师门
 */
#include <cstring>
#include <iostream>
#include <stack>
#include <stdio.h>
#include <string>
using namespace std;
const int N = 1010;
int n, m;
int city[N][N];
int height[N], width[N];
void calc_height(int r)
{
    for (int i = 0; i < m; i++)
        height[i + 1] = (city[r][i] == 1) ? height[i + 1] + 1 : 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    string str;
    while (t--)
    {
        memset(city, 0, sizeof(city));
        memset(height, 0, sizeof(height));
        cin >> n >> m;
        char ch;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> str;
                ch = str[0];
                city[i][j] = (ch == 'F') ? 1 : 0;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) //枚举水平面
        {
            calc_height(i);
            stack<int> s;
            memset(width, 0, sizeof(width));
            height[m + 1] = 0;
            s.push(0);
            for (int i = 1; i <= m + 1; i++)
            {
                if (height[i] > height[s.top()])
                    s.push(i), width[i] = 1;
                else
                {
                    int width_sum = 0;
                    while (s.size() && height[i] < height[s.top()])
                    {
                        width_sum += width[s.top()];
                        ans = max(ans, width_sum * height[s.top()]);
                        s.pop();
                    }
                    s.push(i);
                    width[i] = width_sum + 1;
                }
            }
            //cout<<"cur:"<<ans<<endl;
        }
        cout << ans * 3 << endl;
    }
    return 0;
}