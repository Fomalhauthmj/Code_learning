#include <iostream>
#include <stdio.h>
using namespace std;
const int N = 2e5 + 50;
int n, m, q, cnt[N], nxt[N], f[N];
char s[N], t[N];
void calc_nxt()
{
    nxt[1] = 0;
    for (int i = 2, j = 0; i <= m; i++)
    {
        while (j && t[i] != t[j + 1])
            j = nxt[j];
        if (t[i] == t[j + 1])
            j++;
        nxt[i] = j;
    }
}
void KMP()
{
    for (int i = 1, j = 0; i <= n; i++)
    {
        while (j && (s[i] != t[j + 1] || j == m))
            j = nxt[j];
        if (s[i] == t[j + 1])
            j++;
        f[i] = j;
    }
}
int main()
{
    cin >> n >> m >> q;
    scanf("%s", s + 1);
    scanf("%s", t + 1);
    calc_nxt();
    KMP();
    for (int i = 1; i <= n; i++)
        cnt[f[i]]++;
    for (int i = n; i >= 1; i--)
        cnt[nxt[i]] += cnt[i];
    int x;
    while (q--)
    {
        cin >> x;
        cout << cnt[x] - cnt[x + 1] << endl;
    }
    //system("pause");
    return 0;
}