#include <cstring>
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
#define ll long long
const int MAXLEN = 1e6 + 50;
struct state
{
    int len, link, next[26];
} st[MAXLEN * 2];
int sz, last;
void SAM_Init()
{
    st[0].len = 0, st[0].link = -1;
    sz++, last = 0;
}
void SAM_Extend(int c)
{
    int cur = sz++;
    st[cur].len = st[last].len + 1;
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
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a, b;
    cin >> a >> b;
    SAM_Init();
    for (int i = 0; i < a.length(); i++)
        SAM_Extend(a[i] - 'a');
    int v = 0, l = 0, ans = 0;
    for (int i = 0; i < b.length(); i++)
    {
        int c = b[i] - 'a';
        while (v && !st[v].next[c])
        {
            v = st[v].link;
            l = st[v].len;
        }
        if (st[v].next[c])
            v = st[v].next[c], l++;
        ans = max(ans, l);
    }
    cout << ans << endl;
    //system("pause");
    return 0;
}