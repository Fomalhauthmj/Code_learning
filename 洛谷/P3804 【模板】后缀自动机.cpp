#include <iostream>
#include <map>
#include <stdio.h>
using namespace std;
struct state
{
    int len, link;
    map<char, int> next;
};
const int MAXLEN = 1e6 + 50;
state st[MAXLEN * 2];
int sz, last;
void SAM_Init()
{
    st[0].len = 0, st[0].link = -1;
    sz++, last = 0;
}
void SAM_Extend(char c)
{
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    int p = last;
    while (p != -1 && !st[p].next.count(c))
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
            st[clone].next = st[q].next;
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
    system("pause");
    return 0;
}