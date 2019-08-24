#include <iostream>
#include <stdio.h>
using namespace std;
const int MAXLEN = 1e5 + 50;
char a[MAXLEN], b[MAXLEN];
int f[MAXLEN], nxt[MAXLEN], n, m, q;
void calc_next()
{
    nxt[1] = 0;
    for (int i = 2, j = 0; i <= m; i++)
    {
        while (j > 0 && a[i] != a[j + 1])
            j = nxt[j];
        if (a[i] == a[j + 1])
            j++;
        nxt[i] = j;
    }
}
int KMP(int k)
{

    int cnt = 0;
    for (int i = 1, j = 0; i <= n; i++)
    {
        while (j > 0 && (j == n || b[i] != a[j + 1]))
            j = nxt[j];
        if (b[i] == a[j + 1])
            j++;
        f[i] = j;
        if (f[i] == m)
        {
            cnt++;
            if (cnt == k)
                return i - m + 1;
        }
    }
    return -1;
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        scanf("%d%d", &n, &q);
        scanf("%s", b + 1);
        int l, r, k;
        for (int i = 0; i < q; i++)
        {
            scanf("%d%d%d", &l, &r, &k);
            memcpy(a + 1, b + l, r - l + 1);
            m = r - l + 1;
            calc_next();
            printf("%d\n", KMP(k));
        }
    }
    //system("pause");
    return 0;
}
