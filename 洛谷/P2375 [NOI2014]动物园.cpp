#include <cstring>
#include <iostream>
#include <stdio.h>
using namespace std;
const int MAXLEN = 1e6 + 50;
const int mod = 1e9 + 7;
#define ll long long
char a[MAXLEN];
int n, nxt[MAXLEN], num[MAXLEN];
void calc_next()
{
    nxt[1] = 0;
    num[1] = 1;//包括本身的可重叠前后缀相同数量
    for (int i = 2, j = 0; i <= n; i++)
    {
        while (j > 0 && a[i] != a[j + 1])
            j = nxt[j];
        if (a[i] == a[j + 1])
            j++;
        nxt[i] = j;
        num[i] = num[j] + 1;
        //cout << i << " " << num[i] << endl;
    }
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%s", a + 1);
        n = strlen(a + 1);
        calc_next();
        ll ans = 1;
        for (int i = 2, j = 0; i <= n; i++)
        {
            while (j > 0 && a[i] != a[j + 1])
                j = nxt[j];
            if (a[i] == a[j + 1])
                j++;
            while (j > i / 2)
                j = nxt[j];
            //cout << i << "   " << num[j] << endl;
            ans = ans * (num[j] + 1) % mod;
        }
        printf("%lld\n", ans);
    }
    //system("pause");
    return 0;
}