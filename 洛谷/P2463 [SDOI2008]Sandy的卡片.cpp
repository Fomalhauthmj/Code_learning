#include <iostream>
#include <stdio.h>
using namespace std;
const int N = 105;
int n, nxt[N];
int seq[10 * N][N], cnt[10 * N], a[N];
void calc_next(int len)
{
    nxt[1] = 0;
    for (int i = 2, j = 0; i <= len; i++)
    {
        while (j > 0 && a[i] != a[j + 1])
            j = nxt[j];
        if (a[i] == a[j + 1])
            j++;
        nxt[i] = j;
    }
}
int KMP(int b[], int slen, int plen)
{
    int ret = 0;
    for (int i = 1, j = 0; i <= slen; i++)
    {
        while (j > 0 && (j == plen || b[i] != a[j + 1]))
            j = nxt[j];
        if (b[i] == a[j + 1])
            j++;
        ret = max(ret, j);
        // if (f[i] == n)，此时就是a在b中的某一次出现
    }
    return ret;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int val, pre;
        scanf("%d", &cnt[i]);
        for (int j = 0; j < cnt[i]; j++)
        {
            scanf("%d", &val);
            if (j)
                seq[i][j] = val - pre;
            else
                seq[i][j] = val;
            pre = val;
        }
    }
    int ans = 1;
    for (int i = 1; i < cnt[1]; i++)
    {
        for (int j = i; j < cnt[1]; j++)
            a[j - i + 1] = seq[1][j];
        calc_next(cnt[1] - i);
        int min_match = 1e3;
        for (int j = 2; j <= n; j++)
            min_match = min(min_match, KMP(seq[j], cnt[j] - 1, cnt[1] - i));
        ans = max(ans, min_match + 1);
    }
    printf("%d\n", ans);
    //system("pause");
    return 0;
}