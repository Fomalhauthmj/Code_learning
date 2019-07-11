/*
 * File Created: Thursday, 11th July 2019 11:29:39 pm
 * Author: 北落师门 (NJTech_hemengjie@qq.com)
 * Last Modified: Thursday, 11th July 2019 11:31:45 pm
 * Copyright (c) 2019 北落师门
 */
#include <cstring>
#include <iostream>
#include <math.h>
using namespace std;
#define N 1010
bool p[N][N];
int len;
void print(int k, int r, int c)
{
    if (k == 1)
    {
        p[r][c] = 1;
        return;
    }
    int temp = pow(3, k - 2);
    print(k - 1, r, c);
    print(k - 1, r, c + 2 * temp);
    print(k - 1, r + temp, c + temp);
    print(k - 1, r + 2 * temp, c);
    print(k - 1, r + 2 * temp, c + 2 * temp);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while (cin >> n && n != -1)
    {
        memset(p, 0, sizeof(p));
        len = pow(3, n - 1);
        print(n, 0, 0);
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < len; j++)
                if (p[i][j])
                    cout << 'X';
                else
                    cout << ' ';
            cout << endl;
        }
        cout << "-" << endl;
    }
    //system("pause");
    return 0;
}