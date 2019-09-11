#include <cstring>
#include <iostream>
#include <stdio.h>
using namespace std;
const int MAXLEN = 5e5 + 50;
char ori[MAXLEN], str[MAXLEN * 2], legal[MAXLEN * 2];
int d1[MAXLEN * 2], n, m;
long long ans = 0;
void Manacher()
{
    for (int i = 0, l = 0, r = -1; i < m; i+=2)
    {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i);
        while (i - k >= 0 && i + k < m && str[i - k] == legal[i + k])
            k++;
        d1[i] = k--;
        if ((d1[i] - 1) % 2 == 0)
            ans += (d1[i] - 1) / 2;
        //cout << i << " " << (d1[i] - 1) / 2 << endl;
        if (i + k > r)
            l = i - k, r = i + k;
    }
}
int main()
{
    scanf("%d", &n);
    scanf("%s", ori);
    str[0] = '#';
    for (int i = 0; i < n; i++)
    {
        str[(i + 1) * 2] = '#';
        str[(i + 1) * 2 - 1] = ori[i];
    }
    m = n * 2 + 1;
    for (int i = 0; i < m; i++)
        if (str[i] == '0')
            legal[i] = '1';
        else if (str[i] == '1')
            legal[i] = '0';
        else
            legal[i] = '#';
    Manacher();
    printf("%lld\n", ans);
    //system("pause");
    return 0;
}
