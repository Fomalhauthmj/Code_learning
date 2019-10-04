#include <iostream>
#include <stdio.h>
using namespace std;
const int N = 1e5 + 50;
int rt, tot, fa[N], ch[N][2];
int val[N], cnt[N], sze[N];
bool rev[N];
int data[N];
int n, m;
struct Splay_Tree
{
#define lc(x) ch[x][0]
#define rc(x) ch[x][1]
    inline void Pushup(int x)
    {
        sze[x] = sze[lc(x)] + sze[rc(x)] + cnt[x];
    }
    inline bool WhichChild(int x)
    {
        return x == rc(fa[x]);
        //return 0 lc
        //return 1 rc
    }
    inline void Pushdown(int x)
    {
        if (rev[x])
        {
            rev[lc(x)] ^= 1, rev[rc(x)] ^= 1;
            swap(lc(x), rc(x));
            rev[x] = 0;
        }
    }
    void Rotate(int x)
    {
        int y = fa[x], z = fa[y], which = WhichChild(x);
        Pushdown(y), Pushdown(x);
        ch[y][which] = ch[x][which ^ 1];
        fa[ch[x][which ^ 1]] = y;
        ch[x][which ^ 1] = y;
        fa[y] = x, fa[x] = z;
        if (z)
            ch[z][y == ch[z][1]] = x;
        Pushup(y), Pushup(x);
    }
    void Splay(int x, int goal) //x:the son of goal
    {
        for (int f; (f = fa[x]) != goal; Rotate(x))
            if (fa[f] != goal)
                Rotate(WhichChild(x) == WhichChild(f) ? f : x);
        if (!goal)
            rt = x;
    }
    int Kth(int x)
    {
        int cur = rt;
        while (1)
        {
            Pushdown(cur);
            if (lc(cur) && x <= sze[lc(cur)])
                cur = lc(cur);
            else
            {
                x -= cnt[cur] + sze[lc(cur)];
                if (x <= 0)
                    return cur;
                cur = rc(cur);
            }
        }
    }
    int Build(int f, int l, int r)
    {
        if (l > r)
            return 0;
        int cur = ++tot;
        int mid = (l + r) >> 1;
        val[cur] = data[mid], fa[cur] = f, rev[cur] = 0;
        sze[cur] = cnt[cur] = 1;
        lc(cur) = Build(cur, l, mid - 1);
        rc(cur) = Build(cur, mid + 1, r);
        Pushup(cur);
        return cur;
    }
    void DFS(int x)
    {
        if (x)
        {
            Pushdown(x);
            DFS(lc(x));
            if (val[x] >= 1 && val[x] <= n)
                printf("%d ", val[x]);
            DFS(rc(x));
        }
    }
    void Reverse(int l, int r)
    {
        int x = Kth(l);
        int y = Kth(r + 2);
        Splay(x, 0);
        Splay(y, x);
        int target = lc(rc(rt));
        rev[target] ^= 1;
    }
} splay;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n + 1; i++)
        data[i] = i;
    rt = splay.Build(0, 0, n + 1);
    int l, r;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &l, &r);
        splay.Reverse(l, r);
    }
    splay.DFS(rt);
    printf("\n");
    //system("pause");
    return 0;
}