#include <cstring>
#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;
const int MAXLEN = 1e4 + 50;
const int mod = 1e4 + 7;
struct Trie
{
    int tr[MAXLEN][26], fail[MAXLEN], End[MAXLEN];
    int sz, rt;
    int NewNode()
    {
        memset(tr[sz], 0, sizeof(tr[sz]));
        End[sz] = 0, fail[sz] = 0; //注意重置
        return sz++;
    }
    void Init()
    {
        sz = 0, rt = NewNode();
    }
    void Insert(const char *s)
    {
        int p = rt;
        for (int i = 0; s[i]; i++)
        {
            int c = s[i] - 'A';
            if (!tr[p][c])
                tr[p][c] = NewNode();
            p = tr[p][c];
        }
        End[p] = 1;
    }
    void Build()
    {
        queue<int> q;
        for (int c = 0; c < 26; c++)
            if (tr[rt][c])
                q.push(tr[rt][c]);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            End[u] |= End[fail[u]];
            for (int c = 0; c < 26; c++)
            {
                if (tr[u][c])
                    fail[tr[u][c]] = tr[fail[u]][c], q.push(tr[u][c]);
                else
                    tr[u][c] = tr[fail[u]][c];
            }
        }
    }
} ac;
char str[MAXLEN];
int dp[105][MAXLEN];
int main()
{
    int n,m;
    scanf("%d%d", &n, &m);
    ac.Init();
    for (int i = 0; i < n; i++)
    {
        scanf("%s", str);
        ac.Insert(str);
    }
    ac.Build();
    dp[0][0] = 1;
    for (int i = 1; i <= m; i++)
        for (int j = 0; j < ac.sz; j++)
            for (int k = 0; k < 26; k++)
                if (!ac.End[ac.tr[j][k]])
                    dp[i][ac.tr[j][k]] += dp[i - 1][j], dp[i][ac.tr[j][k]] %= mod;
    int ans = 1;
    for (int i = 1; i <= m; i++)
        ans = ans * 26 % mod;
    int temp = 0;
    for (int i = 0; i < ac.sz; i++)
        temp = (temp + dp[m][i]) % mod;
    ans = (ans - temp + mod) % mod;
    printf("%d\n", ans);
    //system("pause");
    return 0;
}