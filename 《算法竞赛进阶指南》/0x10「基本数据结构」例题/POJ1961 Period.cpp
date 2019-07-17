/*
 * File Created: Wednesday, 17th July 2019 9:48:26 am
 * Author: 北落师门 (NJTech_hemengjie@qq.com)
 * Last Modified: Wednesday, 17th July 2019 10:33:26 am
 * Copyright (c) 2019 北落师门
 */
#include <iostream>
#include <stdio.h>
using namespace std;
const int N = 1e6 + 50;
char str[N];
int nxt[N];
int n;
void calc_next()
{
    nxt[1] = 0;
    for (int i = 2, j = 0; i <= n; i++)
    {
        while (j > 0 && str[i] != str[j + 1])
            j = nxt[j];
        if (str[i] == str[j + 1])
            j++;
        nxt[i] = j;
    }
}
int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int casenum = 0;
    while (cin >> n && n)
    {
        scanf("%s", str + 1);
        calc_next();
        cout << "Test case #" << ++casenum << endl;
        for (int i = 2; i <= n; i++)
        {
            if (i % (i - nxt[i]) == 0 && i / (i - nxt[i]) > 1)
                cout << i << " " << i / (i - nxt[i]) << endl;
        }
        cout << endl;
    }
    //system("pause");
    return 0;
}