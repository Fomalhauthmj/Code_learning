#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
const int SIZE = 1E5 + 50;
#define inf 0x7fffffff
struct Treap
{
    int l, r;
    int val, dat;
    int cnt, size;
} a[SIZE];
int tot, root, n;
int New(int val)
{
    a[++tot].val = val, a[tot].dat = rand(), a[tot].cnt = a[tot].size = 1;
    return tot;
}
void Update(int p)
{
    a[p].size = a[a[p].l].size + a[a[p].r].size + a[p].cnt;
}
void Build()
{
    New(-inf), New(inf), root = 1, a[1].r = 2, Update(root);
}
int GetRankByVal(int p, int val)
{
    if (p == 0)
        return 0;
    if (val == a[p].val)
        return a[a[p].l].size + 1;
    if (val < a[p].val)
        return GetRankByVal(a[p].l, val);
    return GetRankByVal(a[p].r, val) + a[a[p].l].size + a[p].cnt;
}
int GetValByRank(int p, int rank)
{
    if (p == 0)
        return inf;
    if (a[a[p].l].size >= rank)
        return GetValByRank(a[p].l, rank);
    if (a[a[p].l].size + a[p].cnt >= rank)
        return a[p].val;
    return GetValByRank(a[p].r, rank - a[a[p].l].size - a[p].cnt);
}
void Zag(int &p)
{
    int q = a[p].r;
    a[p].r = a[q].l, a[q].l = p, p = q, Update(a[p].l), Update(p);
}
void Zig(int &p)
{
    int q = a[p].l;
    a[p].l = a[q].r, a[q].r = p, p = q, Update(a[p].r), Update(p);
}
void Insert(int &p, int val)
{
    if (p == 0)
    {
        p = New(val);
        return;
    }
    if (val == a[p].val)
    {
        a[p].cnt++, Update(p);
        return;
    }
    if (val < a[p].val)
    {
        Insert(a[p].l, val);
        if (a[p].dat < a[a[p].l].dat)
            Zig(p);
    }
    else
    {
        Insert(a[p].r, val);
        if (a[p].dat < a[a[p].r].dat)
            Zag(p);
    }
    Update(p);
}
int GetPre(int val)
{
    int ans = 1, p = root;
    while (p)
    {
        if (val == a[p].val)
        {
            if (a[p].l > 0)
            {
                p = a[p].l;
                while (a[p].r > 0)
                    p = a[p].r;
                ans = p;
            }
            break;
        }
        if (a[p].val < val && a[p].val > a[ans].val)
            ans = p;
        p = val < a[p].val ? a[p].l : a[p].r;
    }
    return a[ans].val;
}
int GetNext(int val)
{
    int ans = 2, p = root;
    while (p)
    {
        if (val == a[p].val)
        {
            if (a[p].r > 0)
            {
                p = a[p].r;
                while (a[p].l > 0)
                    p = a[p].l;
                ans = p;
            }
            break;
        }
        if (a[p].val > val && a[p].val < a[ans].val)
            ans = p;
        p = val < a[p].val ? a[p].l : a[p].r;
    }
    return a[ans].val;
}
void Remove(int &p, int val)
{
    if (p == 0)
        return;
    if (val == a[p].val)
    {
        if (a[p].cnt > 1)
        {
            a[p].cnt--, Update(p);
            return;
        }
        if (a[p].l || a[p].r)
        {
            if (a[p].r == 0 || a[a[p].l].dat > a[a[p].r].dat)
                Zig(p), Remove(a[p].r, val);
            else
                Zag(p), Remove(a[p].l, val);
            Update(p);
        }
        else
            p = 0;
        return;
    }
    val < a[p].val ? Remove(a[p].l, val) : Remove(a[p].r, val);
    Update(p);
}
int main()
{
    Build();
    scanf("%d", &n);
    while (n--)
    {
        int opt, x;
        scanf("%d%d", &opt, &x);
        switch (opt)
        {
        case 1:
            Insert(root, x);
            break;
        case 2:
            Remove(root, x);
            break;
        case 3:
            //存在-inf
            printf("%d\n", GetRankByVal(root, x) - 1);
            break;
        case 4:
            //存在-inf
            printf("%d\n", GetValByRank(root, x + 1));
            break;
        case 5:
            printf("%d\n", GetPre(x));
            break;
        case 6:
            printf("%d\n", GetNext(x));
            break;
        }
    }
    //system("pause");
    return 0;
}