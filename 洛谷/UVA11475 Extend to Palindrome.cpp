#include <cstring>
#include <iostream>
#include <stdio.h>
using namespace std;
const int MAXLEN = 2e5 + 50;
char ori[MAXLEN], cpy[MAXLEN], str[MAXLEN * 2];
int d1[MAXLEN * 2], n, m;
void Manacher()
{
    for (int i = 0, l = 0, r = -1; i < m; i++)
    {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i);
        while (i - k >= 0 && i + k < m && str[i - k] == str[i + k])
            k++;
        d1[i] = k--;
        if (i + k > r)
            l = i - k, r = i + k;
    }
}
int main()
{
    while (scanf("%s", ori) != EOF)
    {
        n = strlen(ori);
        str[0] = '#';
        for (int i = 0; i < n; i++)
        {
            str[(i + 1) << 1] = '#';
            str[(i + 1) * 2 - 1] = ori[i];
        }
        m = n * 2 + 1;
        Manacher();
        for (int i = 0; i < m; i++)
        {
            if (i + d1[i] - 1 == m - 1)
            //找到某中心位置的回文串长度到达末尾，只需补齐部分前缀即可
            //未到末尾的非最优解
            {
                printf("%s", ori);
                for (int j = i - d1[i]; j >= 0; j--)
                {
                    if (str[j] != '#')
                        printf("%c", str[j]);
                }
                break;
            }
        }
        printf("\n");
    }
    //system("pause");
    return 0;
}