#include <cstring>
#include <iostream>
#include <stdio.h>
using namespace std;
const int MAXLEN = 3E5 + 50;
#define ll long long
struct state
{
    int len, link, next[26];
} st[MAXLEN * 2];
int sz, last, sze[MAXLEN * 2], fa[MAXLEN * 2][20], pos[MAXLEN];
void SAM_Init()
{
    st[0].len = 0, st[0].link = -1;
    sz++, last = 0;
}
void SAM_Extend(int c)
{
    int cur = sz++;
    st[cur].len = st[last].len + 1, sze[cur] = 1;
    int p = last;
    while (p != -1 && !st[p].next[c])
    {
        st[p].next[c] = cur;
        p = st[p].link;
    }
    if (p == -1)
        st[cur].link = 0;
    else
    {
        int q = st[p].next[c];
        if (st[q].len == st[p].len + 1)
            st[cur].link = q;
        else
        {
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            memcpy(st[clone].next, st[q].next, sizeof(st[clone].next));
            st[clone].link = st[q].link;
            while (p != -1 && st[p].next[c] == q)
            {
                st[p].next[c] = clone;
                p = st[p].link;
            }
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}
int id[MAXLEN * 2], c[MAXLEN * 2];
void Topo()
{
    //计数排序
    for (int i = 1; i < sz; i++)
        c[st[i].len]++;
    for (int i = 1; i < MAXLEN; i++)
        c[i] += c[i - 1];
    for (int i = 1; i < sz; i++)
        id[c[st[i].len]--] = i;
    for (int i = sz - 1; i >= 1; i--)
    {
        int s = id[i], p = st[s].link;
        sze[p] += sze[s];
    }
    for (int i = 1; i < sz; i++)
    {
        int s = id[i], p = st[s].link;
        fa[s][0] = p;
        for (int j = 1; j < 20; j++)
            fa[s][j] = fa[fa[s][j - 1]][j - 1];
    }
}
char ori[MAXLEN], str[MAXLEN * 2];
int d1[MAXLEN * 2], n, m,pos_in_ori[MAXLEN * 2];
ll ans=0;
ll Ask(int l, int r)
{
    if (l < 1 || r > n || l > r)
        return 0;
    int p = pos[r];
    for (int i = 19; i >= 0; i--)
        if (st[fa[p][i]].len >= r - l + 1)
            p = fa[p][i];
    return (ll)sze[p] * (r - l + 1);
}
void Manacher()
{
    for (int i = 0, l = 0, r = -1; i < m; i++)
    {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i);
        while (i - k >= 0 && i + k < m && str[i - k] == str[i + k])
        {
            if (str[i - k] == '#')
                ans = max(ans, Ask(pos_in_ori[i - k + 1], pos_in_ori[i + k - 1]));
            k++;
        }
        d1[i] = k--;
        if (i + k > r)
            l = i - k, r = i + k;
    }
}
int main()
{
    scanf("%s", ori + 1);
    n = strlen(ori + 1);
    str[0] = '#';
    for (int i = 1; i <= n; i++)
    {
        str[i * 2] = '#';
        str[i * 2 - 1] = ori[i];
        pos_in_ori[i * 2 - 1] = i;
    }
    m = n * 2 + 1;
    SAM_Init();
    for (int i = 1; i <= n; i++)
        SAM_Extend(ori[i] - 'a'), pos[i] = last;
    Topo();
    Manacher();
    printf("%lld\n", ans);
    //system("pause");
    return 0;
}