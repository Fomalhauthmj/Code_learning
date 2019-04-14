#include <iostream>
#include <stdio.h>
using namespace std;
int year, month, day, hour, minute, second;
//知道S距离2050年1月1日0点0时0分多少秒。
#define MOD 100
bool is_leapyear(int y)
{
    if (y % 400 == 0)
        return true;
    if (y % 4 == 0 && y % 100 != 0)
        return true;
    return false;
}
int months[] = {
    0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
long long solve(int ye, int mo, int da, int ho, int mi, int se)
{
    long long res;
    for (int i = 2019; i < ye; i++)
    {
        if (is_leapyear(i))
        {
            res += 31622400;
        }
        else
            res += 31536000;
    }
    for (int i = 1; i < mo; i++)
    {
        res += months[i] * 24 * 60 * 60;
    }
    res += (da - 1) * 24 * 60 * 60;
    res += ho * 60 * 60;
    res += 60 * mi;
    res += se;
    return res;
}
int main()
{
    int T;
    scanf("%d", &T);
    long long all = solve(2050, 1, 1, 0, 0, 0);
    all--;
    while (T--)
    {
        scanf("%d-%d-%d %d:%d:%d", &year, &month, &day, &hour, &minute, &second);
        //printf("%d\n%d\n%d\n%d\n%d\n%d\n", year, month, day, hour, minute, second);
        long long sub = solve(year, month, day, hour, minute, second);
        sub--;
        //cout << sub << endl;
        //cout << all - sub<< endl;
        long long ans = all - sub;
        cout << ans%MOD<< endl;
    }
    //system("pause");
    return 0;
}
/*
4
2019-01-01 00:00:00
2050-01-01 00:00:00
2035-07-13 13:16:18
2023-12-31 13:16:18
*/