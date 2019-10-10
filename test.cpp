#include <cstring>
#include <iostream>
#include <stdio.h>
using namespace std;
#define ll long long
const int MAXLEN = 5e3 + 50;
const int mod = 1e9 + 7;
char str[MAXLEN];
ll c[5005][5005], ans[5005], app[5005];
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
        memset(sze,0,sizeof(sze));
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
        }
    }
} sam;
int main()
{
    for (int i = 1; i <= 5000; i++)
    {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; j++)
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
    }
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int q, n;
        scanf("%d%d", &n, &q);
        scanf("%s", str + 1);
        sam.Init();
        for (int i = 1; i <= n; i++)
            sam.Extend(str[i] - 'a');
        sam.Topo();
        for (int i = 1; i <= n; i++)
            app[i] = 0;
        for (int i = 1; i < sam.sz; i++)
            app[sam.sze[i]] += sam.len[i] - sam.len[sam.link[i]];
        for (int i = 1; i <= n; i++)
        {
            ans[i]=0;
            for (int j = n; j >= i; j--)
                ans[i] = (ans[i] + app[j] * c[j][i]) % mod;
        }
        while (q--)
        {
            int k;
            scanf("%d", &k);
            if (k > n)
                printf("0\n");
            else
                printf("%lld\n", ans[k]);
        }
    }
    //system("pause");
    return 0;
}
//https://www.codechef.com/problems/CHSTR