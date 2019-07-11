/*
 * File Created: Monday, 8th July 2019 3:51:41 pm
 * Author: 北落师门 (NJTech_hemengjie@qq.com)
 * Last Modified: Thursday, 11th July 2019 10:36:13 pm
 * Copyright (c) 2019 北落师门
 */
#include <cstring>
#include <iostream>
using namespace std;
int a[5][5];
int b[5][5];
bool all_open()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            if (b[i][j])
                return false;
    }
    return true;
}
void change(int state)
{
    int r = state / 4;
    int c = state % 4;
    for (int i = 0; i < 4; i++)
    {
        if (i != c)
            b[r][i] ^= 1;
        if (i != r)
            b[i][c] ^= 1;
    }
    b[r][c] ^= 1;
}
void print(int state)
{
    int ans = 0;
    for (int i = 0; i < 16; i++)
    {
        if (state & (1 << i))
            ans++;
    }
    cout << ans << endl;
    int r, c;
    for (int i = 0; i < 16; i++)
    {
        if (1 & (state >> i))
        {
            r = i / 4;
            c = i % 4;
            cout << r + 1 << " " << c + 1 << endl;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(a, 0, sizeof(a));
    char ch;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> ch;
            if (ch == '+')
                a[i][j] = 1;
        }
    }
    for (int i = 0; i < (1 << 16); i++)
    {
        memcpy(b, a, sizeof(b));
        for (int j = 0; j < 16; j++)
        {
            if (i & (1 << j))
                change(j);
        }
        if (all_open())
        {
            print(i);
            break;
        }
    }
    //system("pause");
    return 0;
}