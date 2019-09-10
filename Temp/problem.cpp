#include <cstring>
#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;
const int MAXLEN = 1e6 + 50;
struct Trie
{
    int tr[MAXLEN][26], fail[MAXLEN], End[MAXLEN];
    int sz, rt;
    int NewNode()
    {
        memset(tr[sz], 0, sizeof(tr[sz]));
        End[sz] = 0, fail[sz] = 0;
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
            int c = s[i] - 'a';
            if (!tr[p][c])
                tr[p][c] = NewNode();
            p = tr[p][c];
        }
        End[p]++;
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
            for (int c = 0; c < 26; c++)
            {
                if (tr[u][c])
                    fail[tr[u][c]] = tr[fail[u]][c], q.push(tr[u][c]);
                else
                    tr[u][c] = tr[fail[u]][c];
            }
        }
    }
    int Query(const char *s)
    {
        int u = rt, res = 0;
        for (int i = 0; s[i]; i++)
        {
            u = tr[u][s[i] - 'a']; // 转移
            for (int j = u; j && End[j] != -1; j = fail[j])
            {
                res += End[j], End[j] = -1;
            }
        }
        return res;
    }
} ac;
char str[MAXLEN];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        ac.Init();
        for (int i = 0; i < n; i++)
        {
            scanf("%s", str);
            ac.Insert(str);
        }
        ac.Build();
        scanf("%s", str);
        printf("%d\n", ac.Query(str));
    }
    //system("pause");
    return 0;
}