#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
#define ll long long
bool Solve(ll num)
{
    if (num >= 2)
        return true;
    else
        return false;
    ll limit = sqrt(num);
    for (ll i = 2; i <= limit; i++)
    {
        if (num % i == 0)
        {
            return true;
            while (num % i == 0)
                num /= i;
        }
    }
    if (num > 1)
        return true;
    return false;
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        ll x, y;
        scanf("%lld%lld", &x, &y);
        if (Solve(x - y))
            printf("YES\n");
        else
            printf("NO\n");
    }
    //system("pause");
    return 0;
}