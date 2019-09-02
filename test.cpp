#include <iostream>
#include <stdio.h>
using namespace std;
#define ll long long
int n = 5;
ll Ori_Val(int x, int y)
{
    x = x - (n + 1) / 2;
    y = y - (n + 1) / 2;
    int t = max(abs(x), abs(y));
    if (x >= y)
        return (ll)n * n - (ll)4 * t * t - 2 * t - x - y;
    else
        return (ll)n * n - (ll)4 * t * t + 2 * t + x + y;
}
ll Bit_Val(ll ori_val)
{
    int ret = 0;
    while (ori_val)
        ret += ori_val % 10, ori_val /= 10;
    return ret;
}
int main()
{
    for (int j = 5; j >= 1; j--)
    {
        for (int i = 1; i <= 5; i++)
        {
            cout << Ori_Val(i, j) << " ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}