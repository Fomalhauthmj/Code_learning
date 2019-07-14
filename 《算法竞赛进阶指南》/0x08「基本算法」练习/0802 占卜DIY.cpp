/*
 * File Created: Sunday, 14th July 2019 3:49:46 pm
 * Author: 北落师门 (NJTech_hemengjie@qq.com)
 * Last Modified: Sunday, 14th July 2019 3:58:17 pm
 * Copyright (c) 2019 北落师门
 */
#include <deque>
#include <iostream>
using namespace std;
deque<char> a[14];
int m[150];
int cnt[13];
void Init()
{
    m['A'] = 1;
    for (int i = 2; i <= 9; i++)
        m['0' + i] = i;
    m['0'] = 10;
    m['J'] = 11;
    m['Q'] = 12;
    m['K'] = 13;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    Init();
    int life = 4;
    int start = 13;
    char ch;
    for (int i = 1; i <= 13; i++)
    {
        for (int j = 0; j < 4; j++)
            cin >> ch, a[i].push_back(ch);
    }
    while (life)
    {
        char now;
        if (start == 13)
        {
            now = a[13].front();
            a[13].pop_front();
        }
        else
        {
            now = a[start].back();
            a[start].pop_back();
        }
        //cout << "cur:" << now << endl;
        if (now == 'K')
        {
            life--;
            start = 13;
            continue;
        }
        else
        {
            int num = m[now];
            cnt[num]++;
            start = num;
        }
    }
    int ans = 0;
    for (int i = 1; i <= 12; i++)
        if (cnt[i] == 4)
            ans++;
    cout << ans << endl;
    //system("pause");
    return 0;
}