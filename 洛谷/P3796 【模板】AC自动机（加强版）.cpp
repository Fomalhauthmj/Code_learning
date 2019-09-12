#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;
const int MAXLEN = 1e6 + 50;
struct ret
{
    int match_cnt;
    int string_id;
    bool operator<(const ret &r) const
    {
        if (match_cnt != r.match_cnt)
            return match_cnt > r.match_cnt;
        return string_id < r.string_id;
    }
} R[200];
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
    void Insert(const char *s, int string_id)
    {
        int p = rt;
        for (int i = 0; s[i]; i++)
        {
            int c = s[i] - 'a';
            if (!tr[p][c])
                tr[p][c] = NewNode();
            p = tr[p][c];
        }
        End[p] = string_id;
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
    void Query(const char *s)
    {
        int u = rt;
        for (int i = 0; s[i]; i++)
        {
            u = tr[u][s[i] - 'a']; // 转移
            for (int j = u; j; j = fail[j])
                R[End[j]].match_cnt++;
        }
    }
} ac;
char str[MAXLEN];
char s[205][80];
int main()
{
    int n;
    while (scanf("%d", &n) && n)
    {
        ac.Init();
        for (int i = 1; i <= n; i++)
            scanf("%s", s[i]), ac.Insert(s[i], i),R[i].match_cnt=0,R[i].string_id=i;
        ac.Build();
        scanf("%s", str);
        ac.Query(str);
        sort(R + 1, R + 1 + n);
        printf("%d\n", R[1].match_cnt);
        printf("%s\n", s[R[1].string_id]);
        for (int i = 2; i <= n; i++)
        {
            if (R[i].match_cnt == R[1].match_cnt)
                printf("%s\n", s[R[i].string_id]);
            else
                break;
        }
    }
    //system("pause");
    return 0;
}
