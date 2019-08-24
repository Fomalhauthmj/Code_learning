#include <cstring>
#include <iostream>
#include <stdio.h>
using namespace std;
#define ll long long
const int MAXLEN = 2E5 + 50;
char str[MAXLEN];
ll p, q, dp[MAXLEN];
struct state
{
    int len, link, next[26];
} st[MAXLEN * 2];
int sz, last;
void SAM_Init()
{
    memset(st, 0, sizeof(st));
    st[0].len = 0, st[0].link = -1;
    sz = 1, last = 0;
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
    while (scanf("%s", str + 1) != EOF)
    {
        cin >> p >> q;
        int len = strlen(str + 1);
        SAM_Init();
        memset(dp, 0x3f, sizeof(dp));
        dp[0] = 0;
        int pos = 0;
        /*
        pos 表示可复制字符串所在后缀自动机中的节点位置 即s[j+1...i] 
        要求s[j+1...i] 为s[1...j]的子串
        */
        for (int i = 1, j = 0; i <= len; i++)
        {
            dp[i] = dp[i - 1] + p;
            int c = str[i] - 'a';
            while (1)
            {
                while (pos && st[st[pos].link].len >= i - j - 1)
                    pos = st[pos].link;
                if (st[pos].next[c])
                {
                    pos = st[pos].next[c];
                    break;
                }
                else
                    SAM_Extend(str[++j] - 'a');
            }
            dp[i] = min(dp[i], dp[j] + q);
        }
        cout << dp[len] << endl;
    }
    //system("pause");
    return 0;
}