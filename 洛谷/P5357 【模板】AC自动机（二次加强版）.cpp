#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;
const int MAXLEN = 2e6 + 50;
const int N=2e5+50;
int R[N];
struct Trie
{
    int tr[MAXLEN][26], fail[MAXLEN], End[MAXLEN];
    int sz, rt;
    int NewNode()
    {
        memset(tr[sz], 0, sizeof(tr[sz]));
        //End[sz] = 0, fail[sz] = 0; //注意重置
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
        End[string_id] = p;
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
            R[u]++;
        }
    }
} ac;
char str[MAXLEN];
int head[N],nxt[N],ver[N],tot=0;
void add(int x,int y)
{
    ver[++tot]=y,nxt[tot]=head[x],head[x]=tot;
}
void DFS(int x)
{
    for(int i=head[x];i;i=nxt[i])
    {
        int y=ver[i];
        DFS(y);
        R[x]+=R[y];
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    ac.Init();
    for (int i = 1; i <= n; i++)
        scanf("%s", str), ac.Insert(str, i),R[i]=0;
    ac.Build();
    scanf("%s", str);
    ac.Query(str);
    for(int i=1;i<ac.sz;i++)
        add(ac.fail[i],i);
    DFS(0);
    for (int i = 1; i <= n; i++)
        printf("%d\n",R[ac.End[i]]);
    //system("pause");
    return 0;
}