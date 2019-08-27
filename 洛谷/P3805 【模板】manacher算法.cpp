#include <cstring>
#include <iostream>
#include <stdio.h>
using namespace std;
const int MAXLEN = 11000010;
char ori[MAXLEN], str[MAXLEN * 2];
int d1[MAXLEN * 2], n;
int ans = 0;
void Manacher()
{
    for (int i = 0, l = 0, r = -1; i < n; i++)
    {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i);
        while (i - k >= 0 && i + k < n && str[i - k] == str[i + k])
            k++;
        d1[i] = k--;
        ans = max(ans, d1[i] - 1);
        if (i + k > r)
            l = i - k, r = i + k;
    }
}
int main()
{
    scanf("%s", ori);
    n = strlen(ori);
    str[0] = '#';
    for (int i = 0; i < n; i++)
    {
        str[(i + 1) << 1] = '#';
        str[(i + 1) * 2 - 1] = ori[i];
    }
    n = n * 2 + 1;
    Manacher();
    printf("%d\n", ans);
    //system("pause");
    return 0;
}