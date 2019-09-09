#include <cstring>
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
#define ll long long
const int MAXLEN = 1e6 + 50;
ll ans;
struct SAM
{
    int len[MAXLEN << 1], link[MAXLEN << 1], next[MAXLEN << 1][26];
    ll sze[MAXLEN << 1]; ////每个结点所代表的字符串的出现次数
    int sz, last, rt;
    int NewNode(int x = 0)
    {
        len[sz] = x;
        link[sz] = -1;
        memset(next[sz], -1, sizeof(next[sz]));
        return sz++;
    }
    void Init()
    {
        //重置
        sz = last = 0, rt = NewNode();
    }
    void Extend(int c)
    {
        int cur = NewNode(len[last] + 1);
        sze[cur] = 1;
        int p = last;
        while (~p && next[p][c] == -1)
            next[p][c] = cur, p = link[p];
        if (p == -1)
            link[cur] = rt;
        else
        {
            int q = next[p][c];
            if (len[q] == len[p] + 1)
                link[cur] = q;
            else
            {
                int clone = NewNode(len[p] + 1);
                memcpy(next[clone], next[q], sizeof(next[q]));
                link[clone] = link[q], link[q] = link[cur] = clone;
                while (~p && next[p][c] == q)
                    next[p][c] = clone, p = link[p];
            }
        }
        last = cur;
    }
    int id[MAXLEN << 1], c[MAXLEN];
    void Topo()
    {
        //计数排序
        memset(c, 0, sizeof(c));
        for (int i = 0; i < sz; i++)
            c[len[i]]++;
        for (int i = 1; i < MAXLEN; i++)
            c[i] += c[i - 1];
        for (int i = 0; i < sz; i++)
            id[--c[len[i]]] = i;
        for (int i = sz - 1; ~i; i--)
        {
            int u = id[i];
            if (~link[u])
                sze[link[u]] += sze[u];
            if (sze[u] > 1)
                ans = max(ans, sze[u] * len[u]);
        }
    }
} RUN;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string str;
    cin >> str;
    RUN.Init();
    for (int i = 0; i < str.length(); i++)
        RUN.Extend(str[i] - 'a');
    ans = 0;
    RUN.Topo();
    cout << ans << endl;
    //system("pause");
    return 0;
}