#include <cstring>
#include <iostream>
#include <stdio.h>
using namespace std;
const int MAXLEN = 1e5 + 50;
char ori[MAXLEN], str[MAXLEN * 2];
int d1[MAXLEN * 2], n, m;
int st[MAXLEN * 2], ed[MAXLEN * 2];
void Manacher()
{
    for (int i = 0, l = 0, r = -1; i < m; i++)
    {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i);
        while (i - k >= 0 && i + k < m && str[i - k] == str[i + k])
            k++;
        d1[i] = k--;
        st[i - d1[i] + 1] = max(st[i - d1[i] + 1], d1[i] - 1);
        ed[i + d1[i] - 1] = max(ed[i + d1[i] - 1], d1[i] - 1);
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
    m = n * 2 + 1;
    Manacher();
    for (int i = m - 3; i >= 0; i -= 2)
        ed[i] = max(ed[i], ed[i + 2] - 2);
    for (int i = 2; i < m; i += 2)
        st[i] = max(st[i], st[i - 2] - 2);
    int ans = 0;
    for (int i = 0; i < m; i += 2)
        if (st[i] && ed[i])
            ans = max(ans, st[i] + ed[i]);
    cout << ans << endl;
    //system("pause");
    return 0;
}