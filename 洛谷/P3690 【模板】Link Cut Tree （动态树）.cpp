#include <iostream>
#include <stdio.h>
using namespace std;
const int N = 5e5 + 50;
int ch[N][2], fa[N], sum[N], val[N], rev[N], laz[N], sze[N];
/*
    ch[N][2] 左右⼉子
    fa[N] ⽗亲指向
    sum[N] 路径权值和
    val[N] 点权
    rev[N] 翻转标记
    laz[N] 权值标记
    sze[N] 辅助树上子树大小
*/
struct LCT
{
#define lc(x) ch[x][0]
#define rc(x) ch[x][1]
    inline void Reverse(int x)
    {
        swap(lc(x), rc(x)), rev[x] ^= 1;
    }
    inline void Pushup(int x)
    {
        sum[x] = sum[lc(x)] ^ sum[rc(x)] ^ val[x];
    }
    inline void Pushdown(int x)
    {
        if (rev[x])
        {
            if (lc(x))
                Reverse(lc(x));
            if (rc(x))
                Reverse(rc(x));
            rev[x] = 0;
        }
    }
    inline bool WhichChild(int x)
    {
        return x == rc(fa[x]);
        //return 0 lc
        //return 1 rc
    }
    inline bool isRoot(int x)
    {
        return lc(fa[x]) != x && rc(fa[x]) != x;
    }
    void Update(int x)
    {
        if (!isRoot(x))
            Update(fa[x]);
        Pushdown(x);
    }
    void Rotate(int x)
    {
        int y = fa[x], z = fa[y], which = WhichChild(x);
        if (!isRoot(y)) //虚边的存在
            ch[z][WhichChild(y)] = x;
        ch[y][which] = ch[x][which ^ 1];
        fa[ch[x][which ^ 1]] = y;
        ch[x][which ^ 1] = y;
        fa[y] = x, fa[x] = z;
        Pushup(y), Pushup(x);
    }
    void Splay(int x)
    {
        Update(x);
        for (int f; f = fa[x], !isRoot(x); Rotate(x))
            if (!isRoot(f))
                Rotate(WhichChild(x) == WhichChild(f) ? f : x);
    }
    void Access(int x)
    {
        for (int pre = 0; x; pre = x, x = fa[x])
            Splay(x), rc(x) = pre, Pushup(x);
    }
    void MakeRoot(int x)
    {
        Access(x), Splay(x), Reverse(x);
    }
    int FindRoot(int x)
    {
        Access(x), Splay(x);
        while (lc(x))
            Pushdown(x), x = lc(x);
        Splay(x); //防止卡链 保证时间复杂度 例如根在链的远处却多次找根
        return x;
    }
    void Link(int x, int y)
    {
        MakeRoot(x);
        if (FindRoot(y) == x)
            return;
        fa[x] = y;
        //if Find(y)==x 在同一颗树中 不合法 合法连虚边
    }
    void Cut(int x, int y)
    {
        /*
        操作合法
        MakeRoot(x), Access(y), Splay(y);
        fa[x] = lc(y) = 0;
        Pushup(y);
        */
        MakeRoot(x);
        if (FindRoot(y) != x || fa[y] != x || lc(y))
            return;
        fa[y] = rc(x) = 0;
        Pushup(x);
    }
    void Split(int x, int y)
    {
        MakeRoot(x), Access(y), Splay(y);
    }
} lct;
int main()
{
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &val[i]);
    for (int i = 1; i <= m; i++)
    {
        int opt, x, y;
        scanf("%d%d%d", &opt, &x, &y);
        if (opt == 0)
            lct.Split(x, y), printf("%d\n", sum[y]);
        else if (opt == 1)
            lct.Link(x, y);
        else if (opt == 2)
            lct.Cut(x, y);
        else if (opt == 3)
            lct.Splay(x), val[x] = y;
    }
    //system("pause");
    return 0;
}