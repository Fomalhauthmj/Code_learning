#include <cstring>
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f
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
int c[MAXLEN * 2], id[MAXLEN * 2];
void Topo()
{
    for (int i = 1; i < sz; i++)
        c[st[i].len]++;
    for (int i = 1; i < MAXLEN; i++)
        c[i] += c[i - 1];
    for (int i = 1; i < sz; i++)
        id[c[st[i].len]--] = i;
}
int max_match_len[MAXLEN * 2]; //处理单字符串时每个状态最大匹配长度
int min_match_len[MAXLEN * 2]; //对于所有字符串每个状态的最大匹配长度
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a, b;
    cin >> a;
    SAM_Init();
    for (int i = 0; i < a.length(); i++)
        SAM_Extend(a[i] - 'a');
    Topo();
    memset(min_match_len, inf, sizeof(min_match_len));
    while (cin >> b)
    {
        int v = 0, l = 0;
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
            max_match_len[v] = max(max_match_len[v], l);
        }
        for (int i = sz - 1; i >= 1; i--)
        {
            int s = id[i], p = st[s].link;
            max_match_len[p] = max(max_match_len[p], min(max_match_len[s], st[p].len));
            //这里父节点取子节点的最大匹配长度取与自身最大串长度的较小值 避免溢出
            min_match_len[s] = min(min_match_len[s], max_match_len[s]);
            max_match_len[s] = 0;
        }
    }
    int ans = 0;
    for (int i = 1; i < sz; i++)
        ans = max(ans, min_match_len[i]);
    cout << ans << endl;
    //system("pause");
    return 0;
}