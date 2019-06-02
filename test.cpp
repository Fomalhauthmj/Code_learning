/****************************************************
* author:xiefubao
*******************************************************/
#pragma comment(linker, "/STACK:102400000,102400000")
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string.h>
#include <vector>

using namespace std;

#define eps 1e-8
typedef long long LL;

char s[30];
int per;
int len = 0;
LL fac[21];
struct point
{
    char c;
    int x;
} points[100];
int tot = 0;
void init()
{
    fac[0] = 1;
    for (LL i = 1; i <= 20; i++)
        fac[i] = fac[i - 1] * i;
}
LL cal()
{
    LL tool = 1;
    int t = 0;
    for (int i = 0; i <= tot; i++)
        t += points[i].x, tool *= fac[points[i].x];
    return fac[t] / tool;
}
void solve()
{
    if (cal() < per)
    {
        printf("Impossible\n");
        return;
    }
    for (int i = 0; i < len; i++)
    {
        LL tool = 0;
        int j;
        for (j = 0; j <= tot; j++)
        {
            points[j].x--;
            LL now = cal();
            tool += now;
            if (tool >= per)
            {
                putchar(points[j].c);
                per -= tool - now;
                break;
            }
            points[j].x++;
        }
        if (points[j].x == 0)
        {
            for (int k = j; k < tot; k++)
                points[k] = points[k + 1];
            tot--;
        }
    }
    puts("");
}
int main()
{
    int t;
    cin >> t;
    int kk = 1;
    init();
    while (t--)
    {
        tot = 0;
        scanf("%s%d", s, &per);
        len = strlen(s);
        sort(s, s + len);
        points[tot].c = s[0];
        points[tot].x = 1;
        for (int i = 1; i < len; i++)
        {
            if (s[i] == s[i - 1])
                points[tot].x++;
            else
            {
                points[++tot].c = s[i];
                points[tot].x = 1;
            }
        }
        printf("Case %d: ", kk++);
        solve();
    }
    system("pause");
    return 0;
}