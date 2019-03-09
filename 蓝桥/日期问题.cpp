#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
struct node
{
    int year;
    int month;
    int day;
    node(int y, int m, int d)
    {
        //* 1960年1月1日至2059年12月31日
        if (y < 60)
            year = 2000 + y;
        else if (y >= 60)
            year = 1900 + y;
        month = m;
        day = d;
    }
    bool operator==(node &n2)
    {
        if (year != n2.year)
            return false;
        if (month != n2.month)
            return false;
        if (day != n2.day)
            return false;
        return true;
    }
};
vector<node> v;
bool cmp(node &n1, node &n2)
{
    if (n1.year != n2.year)
        return n1.year < n2.year;
    if (n1.month != n2.month)
        return n1.month < n2.month;
    return n1.day < n2.day;
}
//* 闰年
bool is_leapyear(int y)
{
    if (y % 400 == 0)
        return true;
    if (y % 4 == 0 && y % 100 != 0)
        return true;
    return false;
}
int month[] = {
    0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int a[3];
bool judge(int year, int m, int day)
{
    if (year < 60)
        year = 2000 + year;
    else if (year >= 60)
        year = 1900 + year;
    if (m == 2 && is_leapyear(year))
    {
        if (day >= 1 && day <= month[2] + 1)
            return true;
        else
            return false;
    }
    else
    {
        if (m >= 1 && m <= 12)
        {
            if (day >= 1 && day <= month[m])
                return true;
            else
                return false;
        }
        else
            return false;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //一个日期，格式是"AA/BB/CC"。  (0 <= A, B, C <= 9)
    while (scanf("%d/%d/%d", &a[0], &a[1], &a[2]))
    {
        v.clear();
        /*
        sort(a, a + 3);
        do
        {
            if (judge())
                v.push_back(node(a[0], a[1], a[2]));
        } while (next_permutation(a, a + 3));
        */
        //有采用年 / 月 / 日的，有采用月 / 日 / 年的，还有采用日 / 月 / 年
        if (judge(a[0], a[1], a[2]))
        {
            v.push_back(node(a[0], a[1], a[2]));
        }
        if (judge(a[2], a[0], a[1]))
        {
            v.push_back(node(a[2], a[0], a[1]));
        }
        if (judge(a[2], a[1], a[0]))
        {
            v.push_back(node(a[2], a[1], a[0]));
        }
        sort(v.begin(), v.end(), cmp);
        int cnt = unique(v.begin(), v.end()) - v.begin();
        //输出若干个不相同的日期，每个日期一行，格式是 "yyyy-MM-dd"。多个日期按从早到晚排列。
        for (int i = 0; i < cnt; i++)
        {
            printf("%04d-%02d-%02d\n", v[i].year, v[i].month, v[i].day);
        }
    }
}