#include <iostream>
#include <stdio.h>
using namespace std;
const int N = 1e5 + 50;
int rt, tot, fa[N], ch[N][2];
int val[N], cnt[N], sze[N];
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
    inline void Clear(int x)
    {
        lc(x) = rc(x) = fa[x] = val[x] = sze[x] = cnt[x] = 0;
    }
    void Rotate(int x)
    {
        int y = fa[x], z = fa[y], which = WhichChild(x);
        ch[y][which] = ch[x][which ^ 1];
        fa[ch[x][which ^ 1]] = y;
        ch[x][which ^ 1] = y;
        fa[y] = x, fa[x] = z;
        if (z)
            ch[z][y==ch[z][1]] = x;
        Pushup(y), Pushup(x);
    }
    void Splay(int x)
    {
        for (int f; f = fa[x], f; Rotate(x))
            if (fa[f])
                Rotate(WhichChild(x) == WhichChild(f) ? f : x);
        rt = x;
    }
    void Insert(int x)
    {
        if (!rt)
        {
            val[++tot] = x, cnt[tot]++, rt = tot, Pushup(rt);
            return;
        }
        int cur = rt, f = 0;
        while (1)
        {
            if (val[cur] == x)
            {
                cnt[cur]++, Pushup(cur), Pushup(f), Splay(cur);
                break;
            }
            f = cur, cur = ch[cur][val[cur] < x];
            if (!cur)
            {
                val[++tot] = x, cnt[tot]++, fa[tot] = f, ch[f][val[f] < x] = tot;
                Pushup(tot), Pushup(f), Splay(tot);
                break;
            }
        }
    }
    int Rank(int x)
    {
        int ans = 0, cur = rt;
        while (1)
        {
            if (x < val[cur])
                cur = lc(cur);
            else
            {
                ans += sze[lc(cur)];
                if (x == val[cur])
                {
                    Splay(cur);
                    return ans + 1;
                }
                ans += cnt[cur], cur = rc(cur);
            }
        }
    }
    int Kth(int x)
    {
        int cur = rt;
        while (1)
        {
            if (lc(cur) && x <= sze[lc(cur)])
                cur = lc(cur);
            else
            {
                x -= cnt[cur] + sze[lc(cur)];
                if (x <= 0)
                    return val[cur];
                cur = rc(cur);
            }
        }
    }
    int Pre()
    {
        int cur = lc(rt);
        while (rc(cur))
            cur = rc(cur);
        return cur;
    }
    int Nxt()
    {
        int cur = rc(rt);
        while (lc(cur))
            cur = lc(cur);
        return cur;
    }
    void Erase(int x)
    {
        Rank(x);
        if (cnt[rt] > 1)
        {
            cnt[rt]--, Pushup(rt);
            return;
        }
        if (!lc(rt) && !rc(rt))
        {
            Clear(rt), rt = 0;
            return;
        }
        if (!lc(rt))
        {
            int cur = rt;
            rt = rc(rt), fa[rt] = 0, Clear(cur);
            return;
        }
        if (!rc(rt))
        {
            int cur = rt;
            rt = lc(rt), fa[rt] = 0, Clear(cur);
            return;
        }
        int pre = Pre(), cur = rt;
        Splay(pre), fa[rc(cur)] = pre, rc(pre) = rc(cur), Clear(cur), Pushup(rt);
    }
    void DFS(int x)
    {
        if (x)
        {
            DFS(lc(x));
            cout << val[x] << " ";
            DFS(rc(x));
        }
    }
} splay;
int main()
{
    int n, opt, x;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &opt, &x);
        if (opt == 1)
            splay.Insert(x);
        else if (opt == 2)
            splay.Erase(x);
        else if (opt == 3)
            printf("%d\n", splay.Rank(x));
        else if (opt == 4)
            printf("%d\n", splay.Kth(x));
        else if (opt == 5)
            splay.Insert(x), printf("%d\n", val[splay.Pre()]), splay.Erase(x);
        else if (opt == 6)
            splay.Insert(x), printf("%d\n", val[splay.Nxt()]), splay.Erase(x);
        //splay.DFS(rt);
        //cout << endl;
    }
    //system("pause");
    return 0;
}